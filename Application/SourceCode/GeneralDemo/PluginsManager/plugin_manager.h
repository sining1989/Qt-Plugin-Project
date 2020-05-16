#ifndef GENERAL_DEMO_PLUGIN_MANAGER_H
#define GENERAL_DEMO_PLUGIN_MANAGER_H

#include <QObject>
#include <QPluginLoader>
#include <QDir>
#include "plugin_manager_private.h"
#include "plugin_meta_data.h"


class PluginManager : public QObject
{
    Q_OBJECT
public:
	static PluginManager &getInstance()
	{
		static PluginManager m_instance;
		return m_instance;
	}

public:
	QDir getPluginPath();
	//加载所有插件
	void loadAllPlugins();
	//扫描JSON文件中的插件元数据
	void scan(const QString &filepath);
	//加载其中某个插件
	void loadPlugin(const QString &filepath);
	//卸载所有插件
	void unloadAllPlugins();
	//卸载某个插件
	void unloadPlugin(const QString &filepath);
	//获取所有插件
	QList<QPluginLoader *> getAllPlugins();
	//获取某个插件
	QPluginLoader* getPlugin(const QString &name);
	//初始化和插件通信的信号槽
	void initSignalAndSlot();

signals:
	void sendMsg2MainProcess(PluginMetaData);

public slots:
	//接受来自各插件的消息
	void recMsgfromPlugin(PluginMetaData);

private:
	explicit PluginManager(QObject *parent = nullptr);
	~PluginManager();

	PluginManagerPrivate *m_pluginPrivate;

};

#endif // GENERAL_DEMO_PLUGIN_MANAGER_H
