#ifndef GENERAL_DEMO_LUGINMETADATA_H
#define GENERAL_DEMO_LUGINMETADATA_H
#include <QObject>
#include <QVariant>
#include <QMap>
#include <QString>
/**
 * 插件间消息封装体
 **/
struct PluginMetaData
{
    QString from;
    QString dest;
    int type;
    QMap<QString,QVariant> map;
    QObject *object = nullptr;
};
Q_DECLARE_METATYPE(PluginMetaData);

#endif //GENERAL_DEMO_LUGINMETADATA_H