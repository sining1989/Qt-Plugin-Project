#ifndef GENERAL_DEMO_INTERFACE_PLUGIN_H
#define GENERAL_DEMO_INTERFACE_PLUGIN_H

#include <QString>
#include <QtPlugin>
#include <QObject>
#include <QtWidgets\qwidget.h>


#include "plugin_meta_data.h"

//定义接口
class InterfacePlugin
{

public:
    virtual ~InterfacePlugin() {}

	virtual QString toolName() = 0;
	virtual QString information() = 0;
	virtual QWidget *centerWidget() = 0;

	virtual void recMsgfromManager(PluginMetaData) = 0;
	virtual void sendMsg2Manager(PluginMetaData) = 0;
};

#define InterfacePlugin_iid "com.Interface.InterfacePlugin"
Q_DECLARE_INTERFACE(InterfacePlugin, InterfacePlugin_iid)

#endif // GENERAL_DEMO_INTERFACE_PLUGIN_H


