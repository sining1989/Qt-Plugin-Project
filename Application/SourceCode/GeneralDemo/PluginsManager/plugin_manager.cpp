#include "plugin_manager.h"
#include "plugin_manager_private.h"
#include "interface_plugin.h"

#include <QDir>
#include <QApplication>
#include <QPluginLoader>
#include <QLibrary>
#include <QJsonObject>
#include <QJsonArray>

// 加载所有插件
QDir PluginManager::getPluginPath()
{
	// 进入插件目录
	QDir path = QDir(qApp->applicationDirPath());
	path.cd("./plugins");
	return path;
}

void PluginManager::loadAllPlugins()
{
	// 进入插件目录
	QDir path = getPluginPath();

	// 初始化插件中的元数据
	foreach(QFileInfo info, path.entryInfoList(QDir::Files | QDir::NoDotAndDotDot))
	{
		scan(info.absoluteFilePath());
	}
	// 加载插件
	foreach(QFileInfo info, path.entryInfoList(QDir::Files | QDir::NoDotAndDotDot))
	{
		loadPlugin(info.absoluteFilePath());
	}
}


// 扫描 JSON 文件中的插件元数据
void PluginManager::scan(const QString& path)
{
	/*****
	*  判断是否是库（后缀有效性）
	* Windows：.dll、.DLL
	* Unix/Linux：.so
	*****/

	if (!QLibrary::isLibrary(path))
		return;

	// 获取元数据（名称、版本、依赖）
	QPluginLoader *loader = new QPluginLoader(path);
	QJsonObject json = loader->metaData().value("MetaData").toObject();
	m_pluginPrivate->m_names.insert(path, json.value("name").toVariant());
	m_pluginPrivate->m_versions.insert(path, json.value("version").toVariant());
	m_pluginPrivate->m_dependencies.insert(path, json.value("dependencies").toArray().toVariantList());

	delete loader;
	loader = Q_NULLPTR;
}

// 加载插件
void PluginManager::loadPlugin(const QString& path)
{
	// 判断是否是库
	if (!QLibrary::isLibrary(path))
		return;

	// 检测插件依赖
	if (!m_pluginPrivate->check(path))
		return;

	// 加载插件
	QPluginLoader *loader = new QPluginLoader(path);
	if (loader->load()) {
		// 如果继承自 InterfacePlugin，则认为是自己的插件（防止外部插件注入）。
		InterfacePlugin *plugin = qobject_cast<InterfacePlugin *>(loader->instance());
		if (plugin)
		{
			m_pluginPrivate->m_loaders.insert(path, loader);
		}
		else
		{
			delete loader;
			loader = Q_NULLPTR;
		}
	}
}

// 卸载所有插件
void PluginManager::unloadAllPlugins()
{
	foreach(const QString &path, m_pluginPrivate->m_loaders.keys())
		unloadPlugin(path);
}

// 卸载插件
void PluginManager::unloadPlugin(const QString& path)
{
	QPluginLoader *loader = m_pluginPrivate->m_loaders.value(path);

	// 卸载插件，并从内部数据结构中移除
	if (loader->unload())
	{
		m_pluginPrivate->m_loaders.remove(path);
		delete loader;
		loader = Q_NULLPTR;
	}
}

QList<QPluginLoader *> PluginManager::getAllPlugins()
{
	return m_pluginPrivate->m_loaders.values();
}

QPluginLoader* PluginManager::getPlugin(const QString &name)
{
	QString strKey = getPluginPath().absolutePath() + QString("/") + name + ".dll";
	QPluginLoader *loader = m_pluginPrivate->m_loaders.value(strKey);
	return  loader;
}

void PluginManager::initSignalAndSlot()
{
	auto plugins = getAllPlugins();
	foreach(auto loader, plugins)
	{
		// 每个插件发送消息到manager，然后由manager 根据 dest 字段转发
		connect(loader->instance(), SIGNAL(sendMsg2Manager(PluginMetaData)), this, SLOT(recMsgfromPlugin(PluginMetaData)));
	}
}

void PluginManager::recMsgfromPlugin(PluginMetaData metadata)
{
	QString strDest = metadata.dest;
	if ("MainProcess" == strDest)
	{
		emit sendMsg2MainProcess(metadata);
	}
	else
	{
		auto loader = getPlugin(strDest);
		if (loader)
		{
			auto interface = qobject_cast<InterfacePlugin*>(loader->instance());
			if (interface)
			{
				interface->recMsgfromManager(metadata);
			}
		}
	}
	
}

PluginManager::PluginManager(QObject *parent)
    : QObject(parent)
	, m_pluginPrivate(NULL)
{
	m_pluginPrivate = new PluginManagerPrivate();
}

PluginManager::~PluginManager()
{

}