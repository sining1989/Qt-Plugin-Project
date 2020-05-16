/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui>
#include <iostream>
#include <QtDebug>
#include <QSettings>
#include <wchar.h>
#include <QAction>
#include <QShortcut>
#include <QApplication>
#include <QCloseEvent>
#include <QDesktopServices>
#include <QDockWidget>
#include <QDir>
#include <QFileDialog>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QTimer>
#include <QToolBar>
#include <QToolButton>
#include <QUrl>
#include <QStatusBar>
#include <QLabel>
#include <QToolButton>
#include <QHBoxLayout>
#include <QTabBar>

#include "visualization_frame.h"

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace general_demo {

	using namespace Qt;

	/*****************************************************************************
	** Implementation [MainWindow]
	*****************************************************************************/
	VisualizationFrame::VisualizationFrame(QWidget *parent)
		: QMainWindow(parent)
		, app_(NULL)
		, file_menu_(NULL)
		, save_image_action_(NULL)
		, file_menu_quit_action_(NULL)
		, recent_configs_menu_(NULL)
		, view_menu_(NULL)
		, fullscreen_action_(NULL)
		, plugin_menu_(NULL)
		, select_menu_(NULL)
		, theme_action_(NULL)
		, lang_action_(NULL)
		, windows_theme_action_(NULL)
		, darcula_theme_action_(NULL)
		, english_action_(NULL)
		, chinese_action_(NULL)
		, help_menu_(NULL)
		, help_openwiki_action_(NULL)
		, help_about_action_(NULL)
		, toolbar_(NULL)
		, m_statusbar(NULL)
		, m_pGetTaskManager(NULL)
		, m_bLive(true)
		, geom_change_detector_(new WidgetGeometryChangeDetector(this))
		, initialized_(false)
		, action_visualization_(NULL)
		, action_noDisplay_(NULL)
		, m_action_setting_(NULL)
		, m_action_tasklist_(NULL)
		, m_action_opencamera_(NULL)
		, m_action_closecamera_(NULL)
	{
		installEventFilter(geom_change_detector_);
		connect(geom_change_detector_, SIGNAL(changed()), this, SLOT(setDisplayConfigModified()));
				
		setWindowIcon(QIcon(":/images/icon.png"));

		createStatusBar();
		initialize();
		translateLanguage();		
		loadPlugins();
		readSettings();

		qDebug(u8"主程序启动完成");
	}

	VisualizationFrame::~VisualizationFrame()
	{
		writeSettings();
	}

	void VisualizationFrame::setApp(QApplication * app)
	{
		app_ = app;
	}

	void VisualizationFrame::createStatusBar()
	{
		m_textStatus = new QLabel();
		m_strTextStatus = new QLabel();

		statusBar()->addPermanentWidget(m_textStatus, 0);
		statusBar()->addPermanentWidget(m_strTextStatus, 1);
		m_statusbar = statusBar();

	}

	void VisualizationFrame::initialize()
	{
		if (app_) app_->processEvents();
		initMenus();

		if (app_) app_->processEvents();
		initToolbars();

		QPalette palette;
		palette.setColor(QPalette::Background, QColor(220, 220, 220));

		m_imageLabel = new PaintLabel(this);
		m_imageLabel->setPalette(palette);
		m_imageLabel->setBackgroundRole(QPalette::Background);
		m_imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
		m_imageLabel->setPixmap(QPixmap(":/images/demo_bg.jpg"));
		m_imageLabel->setScaledContents(true);
		m_imageLabel->setAlignment(Qt::AlignCenter);

		m_scrollArea = new QScrollArea;
		m_scrollArea->setPalette(palette);
		m_scrollArea->setBackgroundRole(QPalette::Background);
		m_scrollArea->setAlignment(Qt::AlignCenter);
		m_scrollArea->setWidget(m_imageLabel);
		m_scrollArea->setWidgetResizable(true);

		QWidget* central_widget = new QWidget(this);
		QHBoxLayout* central_layout = new QHBoxLayout;
		central_layout->setSpacing(0);
		central_layout->setMargin(0);

		hide_left_dock_button_ = new QToolButton();
		hide_left_dock_button_->setContentsMargins(0, 0, 0, 0);
		hide_left_dock_button_->setArrowType(Qt::LeftArrow);
		hide_left_dock_button_->setSizePolicy(QSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding));
		hide_left_dock_button_->setFixedWidth(16);
		hide_left_dock_button_->setAutoRaise(true);
		hide_left_dock_button_->setCheckable(true);

		connect(hide_left_dock_button_, SIGNAL(toggled(bool)), this, SLOT(hideLeftDock(bool)));

		hide_right_dock_button_ = new QToolButton();
		hide_right_dock_button_->setContentsMargins(0, 0, 0, 0);
		hide_right_dock_button_->setArrowType(Qt::RightArrow);
		hide_right_dock_button_->setSizePolicy(QSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding));
		hide_right_dock_button_->setFixedWidth(16);
		hide_right_dock_button_->setAutoRaise(true);
		hide_right_dock_button_->setCheckable(true);

		connect(hide_right_dock_button_, SIGNAL(toggled(bool)), this, SLOT(hideRightDock(bool)));

		//停靠窗口A
		m_dockWidgetA = new QDockWidget(); 
		m_dockWidgetA->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetClosable | QDockWidget::DockWidgetFloatable);//可移动可关闭可浮动
		m_dockWidgetA->setAllowedAreas(Qt::AllDockWidgetAreas);
		addDockWidget(Qt::LeftDockWidgetArea, m_dockWidgetA);//初始位置

		//停靠窗口B
		m_dockWidgetB = new QDockWidget();
		m_dockWidgetB->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetClosable | QDockWidget::DockWidgetFloatable);
		m_dockWidgetB->setAllowedAreas(Qt::AllDockWidgetAreas);
		addDockWidget(Qt::RightDockWidgetArea, m_dockWidgetB);//初始位置

		QAction* toggle_action1 = m_dockWidgetA->toggleViewAction();
		QAction* toggle_action2 = m_dockWidgetB->toggleViewAction();
		view_menu_->addAction(toggle_action1);
		view_menu_->addAction(toggle_action2);
		connect(m_dockWidgetA, SIGNAL(dockLocationChanged(Qt::DockWidgetArea)), this, SLOT(onDockPanelChange()));
		connect(m_dockWidgetB, SIGNAL(dockLocationChanged(Qt::DockWidgetArea)), this, SLOT(onDockPanelChange()));

		central_layout->addWidget(hide_left_dock_button_, 0);
		central_layout->addWidget(m_scrollArea, 1);
		central_layout->addWidget(hide_right_dock_button_, 0);
		central_widget->setLayout(central_layout);
		setCentralWidget(central_widget);

		//初始隐藏按钮状态
		hide_left_dock_button_->setChecked(true);
		hide_right_dock_button_->setChecked(true);
		hideLeftDock(true);
		hideRightDock(true);

		////// repair/update visibility status
		//Qt::DockWidgetArea area = Qt::LeftDockWidgetArea;
		//hideLeftDock(area == Qt::LeftDockWidgetArea ? false : hide_left_dock_button_->isChecked());
		//hideRightDock(area == Qt::RightDockWidgetArea ? false : hide_right_dock_button_->isChecked());

		if (app_) app_->processEvents();

		panel = new FunctionPanel();
		connect(panel, SIGNAL(configChanged()), this, SLOT(setDisplayConfigModified()));

		
		m_dockFunction = new QDockWidget();
		m_dockFunction->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetClosable | QDockWidget::DockWidgetFloatable);//可移动可关闭可浮动
		m_dockFunction->setAllowedAreas(Qt::AllDockWidgetAreas);
		addDockWidget(Qt::LeftDockWidgetArea, m_dockFunction);//初始位置		
		m_dockFunction->setWidget(panel);
		m_dockFunction->setFloating(true);
		m_dockFunction->setVisible(true);
		connect(m_dockFunction, SIGNAL(visibilityChanged(bool)), this, SLOT(onDockPanelVisibilityChange(bool)));
		connect(this, SIGNAL(fullScreenChange(bool)), m_dockFunction, SLOT(overrideVisibility(bool)));
		m_action_function_ = m_dockFunction->toggleViewAction();
		view_menu_->addAction(m_action_function_);

		connect(m_action_function_, SIGNAL(triggered(bool)), this, SLOT(setDisplayConfigModified()));
		connect(m_dockFunction, SIGNAL(closed()), this, SLOT(setDisplayConfigModified()));
		m_dockFunction->installEventFilter(geom_change_detector_);

		initialized_ = true;

	}

	void VisualizationFrame::loadPlugins()
	{
		connect(&PluginManager::getInstance(), SIGNAL(sendMsg2MainProcess(PluginMetaData)), this, SLOT(recMsgfromPluginManagerSlot(PluginMetaData)));
		QList<QPluginLoader *> pluginList = PluginManager::getInstance().getAllPlugins();
		for (int i = 0; i < pluginList.size(); ++i)
		{
			QPluginLoader *plugin = pluginList[i];
			//加载插件后生成menu
			auto centerInterface = qobject_cast<InterfacePlugin*>(plugin->instance());
			populateMenus(plugin->instance(), centerInterface);
		}
	}

	/*****************************************************************************
	** Implementation [Menu]
	*****************************************************************************/
	void VisualizationFrame::initMenus()
	{
		//文件
		file_menu_ = menuBar()->addMenu("");

		save_image_action_ = new QAction(this);
		save_image_action_->setIcon(QIcon(":/icons/Image.png"));

		file_menu_->addSeparator();

		file_menu_quit_action_ = new QAction(this);
		file_menu_quit_action_->setShortcut(QKeySequence("Ctrl+Q"));
		file_menu_quit_action_->setIcon(QIcon(":/images/exit.png"));
		file_menu_->addAction(save_image_action_);
		file_menu_->addAction(file_menu_quit_action_);
		QObject::connect(save_image_action_, &QAction::triggered, this, &VisualizationFrame::onSaveImage);
		QObject::connect(file_menu_quit_action_, &QAction::triggered, this, &VisualizationFrame::close);

		//视图
		view_menu_ = menuBar()->addMenu(""); 
		fullscreen_action_ = new QAction(this);
		fullscreen_action_->setShortcut(Qt::Key_F11); 
		fullscreen_action_->setIcon(QIcon(":/icons/FullScreen.png"));
		fullscreen_action_->setCheckable(true);
		view_menu_->addAction(fullscreen_action_);
		QObject::connect(fullscreen_action_, SIGNAL(toggled(bool)), this, SLOT(setFullScreen(bool)));
		this->addAction(fullscreen_action_); // Also add to window, or the shortcut doest work when the menu is hidden.
		QObject::connect(this, SIGNAL(fullScreenChange(bool)), this, SLOT(setChecked(bool)));
		new QShortcut(Qt::Key_Escape, this, SLOT(exitFullScreen()));
		view_menu_->addSeparator();

		//插件窗口
		plugin_menu_ = menuBar()->addMenu("");

		//选择
		select_menu_ = menuBar()->addMenu("");
		theme_action_ = new QMenu(select_menu_);
		lang_action_ = new QMenu(select_menu_);
		windows_theme_action_ = new QAction(theme_action_);
		darcula_theme_action_ = new QAction(theme_action_);
		english_action_ = new QAction(lang_action_);
		chinese_action_ = new QAction(lang_action_);
		select_menu_->addAction(theme_action_->menuAction());
		select_menu_->addAction(lang_action_->menuAction());
		theme_action_->addAction(windows_theme_action_);
		theme_action_->addAction(darcula_theme_action_);
		lang_action_->addAction(english_action_);
		lang_action_->addAction(chinese_action_);
		QObject::connect(windows_theme_action_, &QAction::triggered, this, &VisualizationFrame::windowsTheme);
		QObject::connect(darcula_theme_action_, &QAction::triggered, this, &VisualizationFrame::darculaTheme);
		QObject::connect(english_action_, &QAction::triggered, this, &VisualizationFrame::langEnglish);
		QObject::connect(chinese_action_, &QAction::triggered, this, &VisualizationFrame::langChinese);

		// 设置默认主题
		//darcula_theme_action_->setCheckable(true);
		darcula_theme_action_->setChecked(true);
		QFile qss(":/qss/Windows.qss");
		qss.open(QFile::ReadOnly);
		qApp->setStyleSheet(qss.readAll());
		qss.close();

		//帮助
		help_menu_ = menuBar()->addMenu("");
		help_openwiki_action_ = new QAction(help_menu_); 
		help_menu_->addSeparator();
		help_about_action_ = new QAction(help_menu_);
		help_menu_->addAction(help_openwiki_action_);
		help_menu_->addAction(help_about_action_);
		QObject::connect(help_openwiki_action_, &QAction::triggered, this, &VisualizationFrame::onHelpWiki);
		QObject::connect(help_about_action_, &QAction::triggered, this, &VisualizationFrame::onHelpAbout);
	}

	void VisualizationFrame::populateMenus(QObject * pluginInterface, InterfacePlugin* i)
	{
		auto act = new QAction(i->toolName(), pluginInterface);
		//单击menu调用插件
		connect(act, &QAction::triggered, this, &VisualizationFrame::widgetActionTriggeredSlot);
		plugin_menu_->addAction(act);
	}

	/*********************
	** toolbar
	**********************/
	void VisualizationFrame::initToolbars()
	{
		QFont font;
		font.setPointSize(font.pointSizeF()*0.9);

		// make toolbar with plugin tools
		toolbar_ = addToolBar("Tools");
		toolbar_->setFont(font);
		toolbar_->setContentsMargins(0, 0, 0, 0);
		toolbar_->setObjectName("Tools");
		toolbar_->setIconSize(QSize(50, 30));
		toolbar_->setToolButtonStyle(Qt::ToolButtonIconOnly);
		//toolbar_actions_ = new QActionGroup( this );
		//connect( toolbar_actions_, SIGNAL( triggered( QAction* )), this, SLOT( onToolbarActionTriggered( QAction* )));
		//view_menu_->addAction( toolbar_->toggleViewAction() );

		action_visualization_ = new QAction("", toolbar_);		
		action_visualization_->setIcon(QIcon(":/images/media_play.png"));
		toolbar_->addAction(action_visualization_);

		action_noDisplay_ = new QAction("", toolbar_);
		action_noDisplay_->setIcon(QIcon(":/images/display_no.png"));
		toolbar_->addAction(action_noDisplay_);

		toolbar_->addSeparator();

		m_action_setting_ = new QAction("", toolbar_);		
		m_action_setting_->setIcon(QIcon(":/images/setting.png"));
		toolbar_->addAction(m_action_setting_);
		QObject::connect(m_action_setting_, SIGNAL(triggered()), this, SLOT(settingSlot()));

		m_action_tasklist_ = new QAction("", toolbar_);		
		m_action_tasklist_->setIcon(QIcon(":/images/load_task.png"));
		toolbar_->addAction(m_action_tasklist_);
		QObject::connect(m_action_tasklist_, SIGNAL(triggered()), this, SLOT(showFunctionSlot()));

		toolbar_->addSeparator();

		m_action_opencamera_ = new QAction("", toolbar_);		
		m_action_opencamera_->setIcon(QIcon(":/images/openplay.png")); 
		toolbar_->addAction(m_action_opencamera_);
		QObject::connect(m_action_opencamera_, SIGNAL(triggered()), this, SLOT(openCameraSlot()));

		m_action_closecamera_ = new QAction("", toolbar_);		
		m_action_closecamera_->setIcon(QIcon(":/images/openstop.png"));
		toolbar_->addAction(m_action_closecamera_);
		QObject::connect(m_action_closecamera_, SIGNAL(triggered()), this, SLOT(closeCameraSlot()));
	}

	void VisualizationFrame::translateLanguage()
	{
		setWindowTitle(APP_NAME);
		file_menu_->setTitle(FILE_MENU);
		save_image_action_->setText(FILE_SAVEIMAGE_ACTION);
		file_menu_quit_action_->setText(FILE_QUIT_ACTION);
		view_menu_->setTitle(PANELS_MENU);
		fullscreen_action_->setText(PANELS_FULLSCREEN_ACTION);
		plugin_menu_->setTitle(PLUGIN_MENU);
		select_menu_->setTitle(SELECT_MENU);
		theme_action_->setTitle(THEME_MENU);
		lang_action_->setTitle(LANGUAGE_MENU);
		windows_theme_action_->setText(THEME_WINDOWS_ACTION);
		darcula_theme_action_->setText(THEME_DARCULA_ACTION);
		english_action_->setText(LANGUAGE_CHINESE_ACTION);
		chinese_action_->setText(LANGUAGE_ENGLISH_ACTION);
		help_menu_->setTitle(HELP_MENU);
		help_openwiki_action_->setText(HELP_OPENWIKI_ACTION);
		help_about_action_->setText(HELP_ABOUTUS_ACTION);

		action_visualization_->setToolTip(TOOL_OPENVISUALIZATION);
		action_noDisplay_->setToolTip(TOOL_CLOSEVISUALIZATION);
		m_action_setting_->setToolTip(TOOL_SETTING);
		m_action_tasklist_->setToolTip(TOOL_FUNCTION);
		m_action_opencamera_->setToolTip(TOOL_OPENVIDEO);
		m_action_closecamera_->setToolTip(TOOL_CLOSEVIDEO);

		m_dockWidgetA->setWindowTitle(DOCK_WIDGET_A);
		m_dockWidgetB->setWindowTitle(DOCK_WIDGET_B);
		m_dockFunction->setWindowTitle(PANEL_FUNCTION);

		m_textStatus->setText(STATUS_NAME);
	}

	void VisualizationFrame::writeSettings()
	{
		// saves window positions and states
		QSettings settings("general_demo", "visualizationFrame");

		settings.beginGroup("mainWindow");
		settings.setValue("geometry", saveGeometry());
		settings.setValue("state", saveState());
		settings.endGroup();
	}
	
	void VisualizationFrame::readSettings()
	{
		// reads window positions and states
		QSettings settings("general_demo", "visualizationFrame");

		settings.beginGroup("mainWindow");
		restoreGeometry(settings.value("geometry").toByteArray());
		restoreState(settings.value("state").toByteArray());
		settings.endGroup();
	}

	void VisualizationFrame::setFullScreen(bool full_screen)
	{
		Q_EMIT(fullScreenChange(full_screen));

		if (full_screen)
			toolbar_visible_ = toolbar_->isVisible();
		menuBar()->setVisible(!full_screen);
		toolbar_->setVisible(!full_screen && toolbar_visible_);
		statusBar()->setVisible(!full_screen);
		setHideButtonVisibility(!full_screen);

		if (full_screen)
			setWindowState(windowState() | Qt::WindowFullScreen);
		else
			setWindowState(windowState() & ~Qt::WindowFullScreen);
		show();
	}

	void VisualizationFrame::setImageSaveDirectory(const QString& directory)
	{
		last_image_dir_ = directory.toStdString();
	}

	void VisualizationFrame::exitFullScreen()
	{
		setFullScreen(false);
	}

	/*****************************************************************************
	** Implementation [Configuration]
	*****************************************************************************/
	void VisualizationFrame::closeEvent(QCloseEvent *event)
	{
		//if( prepareToExit() )
		{
			event->accept();
		}
		//  else
		//  {
		//    event->ignore();
		//  }
	}

	void VisualizationFrame::sendGetTaskRequest(const QString &strTaskID)
	{
		//CPS_TASK data;

		//QByteArray rqByte;
		//rqByte.clear();

		////序列化
		//rqByte = "";//m_cpsTask->jsonSerializer(strTaskID);

		////编辑HTTP头部
		//QString url = CUrlUtil::getTaskDataUrl();
		//QNetworkRequest request = QNetworkRequest(QUrl(url));

		//request.setRawHeader(QString("Content-Type").toLatin1(),QString("application/json; charset=utf-8").toLatin1());
		//request.setRawHeader(QString("Content-Length").toLatin1(),QString::number(rqByte.length()).toLatin1());
		//qDebug("get task url: %s", qPrintable(url));

		////执行post请求
		//m_pGetTaskManager = new QNetworkAccessManager(this);
		//if (m_pGetTaskManager)
		//{
		//  QNetworkReply *reply = m_pGetTaskManager->post(request,rqByte);
		//  connect(m_pGetTaskManager,SIGNAL(finished(QNetworkReply*)),this,SLOT(getTaskResposeSlot(QNetworkReply*)));
		//  connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(getTaskErrorSlot(QNetworkReply::NetworkError)));
		//}

	}

	/*****************************************************************************
	** Implementation [Slots]
	*****************************************************************************/
	void VisualizationFrame::onSaveImage()
	{
		ScreenshotDialog* dialog = new ScreenshotDialog(this, this, QString::fromStdString(last_image_dir_));
		connect(dialog, SIGNAL(savedInDirectory(const QString&)),
			this, SLOT(setImageSaveDirectory(const QString&)));
		dialog->show();
	}

	void VisualizationFrame::windowsTheme()
	{
		//加载QSS样式表
		QFile qss(":/qss/Windows.qss");
		qss.open(QFile::ReadOnly);
		qApp->setStyleSheet(qss.readAll());
		qss.close();

	/*	if (windows_theme_action_->isChecked())
			windows_theme_action_->setChecked(false);
		else
			windows_theme_action_->setChecked(true);*/
		g_iThemeId = 0;
	}

	void VisualizationFrame::darculaTheme()
	{
		QFile qss(":/qss/Darcula.qss");
		qss.open(QFile::ReadOnly);
		qApp->setStyleSheet(qss.readAll());
		qss.close();

		//if (darcula_theme_action_->isChecked())
		//	darcula_theme_action_->setChecked(false);
		//else
		//	darcula_theme_action_->setChecked(true);
		g_iThemeId = 1;
	}

	// Change language: English/Chinese
	void VisualizationFrame::langEnglish()
	{
		changeLanguage(UI_EN);
	}

	void VisualizationFrame::langChinese()
	{
		changeLanguage(UI_ZH);
	}

	void VisualizationFrame::onHelpWiki()
	{
		QDesktopServices::openUrl(QUrl("http://www.ros.org/wiki"));
	}

	void VisualizationFrame::onHelpAbout()
	{
		QMessageBox::information(this, ABOUTUS, ABOUTINFO), QMessageBox::Ok);
	}

	void VisualizationFrame::widgetActionTriggeredSlot()
	{
		auto obj = qobject_cast<InterfacePlugin*>(sender()->parent())->centerWidget();
		m_dockWidgetB->setWidget(obj);
		//setCentralWidget(obj);
		if (obj->isWidgetType())
		{
			QWidget *widget = qobject_cast<QWidget*>(obj);
			widget->show();
		}

		QPluginLoader *loader = PluginManager::getInstance().getPlugin("DemoLibraryA");
		if (loader)
		{
			auto obj = loader->instance();
			if (obj->isWidgetType())
			{
				QWidget *widget = qobject_cast<QWidget*>(obj);
				widget->show();
				m_dockWidgetA->setWidget(widget);
			}
		}
		else
		{
			m_strTextStatus->setText("未能找到插件A");
		}
	}

	void VisualizationFrame::recMsgfromPluginManagerSlot(PluginMetaData metadata)
	{
		QString strText = QString("from %1 to %2").arg(metadata.from).arg(metadata.dest);
		m_strTextStatus->setText(strText);
	}

	void VisualizationFrame::getTaskResposeSlot(QNetworkReply* reply)
	{
		if (reply->error() == QNetworkReply::NoError)
		{
			QByteArray bytes = reply->readAll();

		}

		reply->deleteLater();
	}

	void VisualizationFrame::getTaskErrorSlot(QNetworkReply::NetworkError errorCode)
	{
		QString strError = "";//QString("%1%2").arg(GET_SERVER_TASK).arg(QString::number(errorCode, 10));
		m_strTextStatus->setText(strError);
	}


	void VisualizationFrame::updateStateTextSlot(const QString &strText)
	{
		if (m_statusbar == statusBar())
			m_strTextStatus->setText(strText);

	}

	void VisualizationFrame::showFunctionSlot()
	{
		if (m_dockFunction->isVisible())
		{
			m_dockFunction->setVisible(false);
			m_action_function_->setChecked(false);
		}
		else
		{
			m_dockFunction->setVisible(true);
			m_action_function_->setChecked(true);
		}
	}

	static int iCount = 2;
	void VisualizationFrame::settingSlot()
	{
		FunctionPanel *pa = new FunctionPanel();
		pa->showNormal();
		//iCount++;
		//QMQTT::Message message(iCount, EXAMPLE_PUB_TOPIC,
		//	QString("Number is %1").arg(iCount).toUtf8());
		//clientPub->publish(message);
	}

	void VisualizationFrame::openCameraSlot()
	{

	}

	void VisualizationFrame::closeCameraSlot()
	{

	}

	void VisualizationFrame::changeLanguage(LANGUAGE language)
	{
		if (m_currentLanguage == language)
		{
			return;
		}
		m_currentLanguage = language;


		if (m_translator != NULL)
		{
			qApp->removeTranslator(m_translator);
		}

		QTranslator *l_translator = new QTranslator(qApp);
		switch (language)
		{
		case UI_EN:
			l_translator->load(QString(":/Resources/qm/lang_en"));
			break;

		case UI_ZH:
			l_translator->load(QString(":/Resources/qm/lang_zh_CN"));
			break;

		default:
			l_translator->load(QString(":/Resources/qm/lang_zh_CN"));
		}
		qApp->installTranslator(l_translator);
		//ui.retranslateUi(this);
		m_translator = l_translator;
	}

	void VisualizationFrame::UpdateControls()
	{
		if (m_bLive)
		{
			m_imageLabel->setScaledContents(false);
			m_imageLabel->setPixmap(QPixmap(":/images/demo_bg.jpg"));
			m_imageLabel->setAlignment(Qt::AlignCenter);
			m_scrollArea->setWidgetResizable(true);
		}
		else
		{
			m_imageLabel->setScaledContents(true);
		}
	}

	void VisualizationFrame::setDisplayConfigModified()
	{
		if (!isWindowModified())
		{
			setWindowModified(true);
		}
	}

	void VisualizationFrame::onDockPanelVisibilityChange(bool visible)
	{
		// if a dock widget becomes visible and is resting inside the
		// left or right dock area, we want to unhide the whole area
		if (visible)
		{
			QDockWidget* dock_widget = dynamic_cast<QDockWidget*>(sender());
			if (dock_widget)
			{
				Qt::DockWidgetArea area = dockWidgetArea(dock_widget);
				if (area == Qt::LeftDockWidgetArea)
				{
					hide_left_dock_button_->setChecked(false);
				}
				if (area == Qt::RightDockWidgetArea)
				{
					hide_right_dock_button_->setChecked(false);
				}
			}
		}

	}

	void VisualizationFrame::hideDockImpl(Qt::DockWidgetArea area, bool hide)
	{
		QList<QDockWidget *> dock_widgets = findChildren<QDockWidget *>();

		for (QList<QDockWidget *>::iterator it = dock_widgets.begin(); it != dock_widgets.end(); it++)
		{
			Qt::DockWidgetArea curr_area = dockWidgetArea(*it);
			if (area == curr_area)
			{
				(*it)->setVisible(hide);
			}
			// allow/disallow docking to this area for all widgets
			if (hide)
			{
				(*it)->setAllowedAreas((*it)->allowedAreas() & ~area);
			}
			else
			{
				(*it)->setAllowedAreas((*it)->allowedAreas() | area);
			}
		}
	}

	void VisualizationFrame::setHideButtonVisibility(bool visible)
	{
		hide_left_dock_button_->setVisible(visible);
		hide_right_dock_button_->setVisible(visible);
	}

	void VisualizationFrame::hideLeftDock(bool hide)
	{
		hideDockImpl(Qt::LeftDockWidgetArea, hide);
		hide_left_dock_button_->setArrowType(hide ? Qt::RightArrow : Qt::LeftArrow);
	}

	void VisualizationFrame::hideRightDock(bool hide)
	{
		hideDockImpl(Qt::RightDockWidgetArea, hide);
		hide_right_dock_button_->setArrowType(hide ? Qt::LeftArrow : Qt::RightArrow);
	}

	void VisualizationFrame::onDockPanelChange()
	{
		QList<QTabBar *> tab_bars = findChildren<QTabBar *>(QString());
		for (QList<QTabBar *>::iterator it = tab_bars.begin(); it != tab_bars.end(); it++)
		{
			(*it)->setElideMode(Qt::ElideNone);
		}
	}

	

}  // namespace general_demo


