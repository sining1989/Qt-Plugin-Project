#ifndef GENERAL_DEMO_PLUGINMANAGERPRIVATE_H
#define GENERAL_DEMO_PLUGINMANAGERPRIVATE_H

#include <QVariant>
#include <QHash>
#include <QDebug>
#include <QPluginLoader>

class PluginManagerPrivate
{
public:
    PluginManagerPrivate();

    bool check(const QString& path); //检测插件依赖

    QHash<QString, QVariant> m_names; //插件路径 - 名称
    QHash<QString, QVariant> m_versions; //插件路径 - 版本
    QHash<QString, QVariantList> m_dependencies; //插件路径 - 其额外依赖的插件
    QHash<QString, QPluginLoader *> m_loaders; //插件路径 - QPluginLoader实例
};

#endif // GENERAL_DEMO_PLUGINMANAGERPRIVATE_H
