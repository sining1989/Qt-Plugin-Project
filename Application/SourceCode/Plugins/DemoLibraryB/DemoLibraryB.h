#ifndef GENERAL_DEMO_DEMOLIBRARYB_H
#define GENERAL_DEMO_DEMOLIBRARYB_H

#include <QPropertyAnimation>
#include <QtWidgets\qpushbutton.h>
#include <QtWidgets\qlabel.h>
#include "demolibraryb_global.h"
#include "..\..\GeneralDemo\PluginsManager\interface_plugin.h"

namespace general_demo
{
	class DEMOLIBRARYB_EXPORT DemoLibraryB
		: public QWidget, public InterfacePlugin
	{
		Q_OBJECT
			Q_PLUGIN_METADATA(IID InterfacePlugin_iid)
			Q_INTERFACES(InterfacePlugin)
	public:
		explicit DemoLibraryB(QWidget *parent = nullptr);

		virtual QString toolName() Q_DECL_OVERRIDE;
		virtual QString information() Q_DECL_OVERRIDE;
		virtual QWidget *centerWidget() Q_DECL_OVERRIDE;

		virtual  void recMsgfromManager(PluginMetaData)  Q_DECL_OVERRIDE;

	signals:
		void sendMsg2Manager(PluginMetaData) Q_DECL_OVERRIDE;

		public slots:
		void animation(QWidget*);
	private:
		QLabel *m_tipsLabel;
	};

}
#endif //GENERAL_DEMO_DEMOLIBRARYB_H