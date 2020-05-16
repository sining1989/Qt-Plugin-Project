#ifndef GENERAL_DEMO_DEMOLIBRARYA_H
#define GENERAL_DEMO_DEMOLIBRARYA_H
#include <QtWidgets\qwidget.h>
#include <QtWidgets\qpushbutton.h>
#include <QtWidgets\qfiledialog.h>
#include <QPixmap>
#include "demolibrarya_global.h"
#include "..\..\GeneralDemo\PluginsManager\interface_plugin.h"
#include "ui_DemoLibraryA.h"

namespace Ui {
	class DemoLibraryA;
}

namespace general_demo
{
	class DEMOLIBRARYA_EXPORT DemoLibraryA
		: public QWidget
		, public InterfacePlugin

	{
		Q_OBJECT
			Q_INTERFACES(InterfacePlugin)
			Q_PLUGIN_METADATA(IID InterfacePlugin_iid)

	public:
		explicit DemoLibraryA(QWidget *parent = nullptr);
		~DemoLibraryA();

		virtual QString toolName() Q_DECL_OVERRIDE;
		virtual QString information() Q_DECL_OVERRIDE;
		virtual QWidget *centerWidget() Q_DECL_OVERRIDE;

		virtual  void recMsgfromManager(PluginMetaData)  Q_DECL_OVERRIDE;

	signals:
		void sendMsg2Manager(PluginMetaData) Q_DECL_OVERRIDE;

		public slots:
		void click2MainProcess();
		void clickOpenImg();
		void click2Animation();

	private:
		Ui::PluginA m_ui;
	};
}
#endif //GENERAL_DEMO_DEMOLIBRARYB_H

