/**
 * @file /include/general_demo/visualization_frame.h
 *
 * @brief Qt based gui for site cps.
 *
 * @date November 2010
 **/
#ifndef GENERAL_DEMO_VISUALOZATION_FRAME_H
#define GENERAL_DEMO_VISUALIZATION_FRAME_H

/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QProgressBar>
#include <QTimer>
#include <QTime>
#include <QScrollArea>
#include <QScrollBar>
#include <QVector>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QTcpSocket>
#include <QHostAddress>
#include <QTranslator>
#include <QToolButton>
#include <deque>

#include "common.h"
#include "common_config.h"
#include "config.h"

#include "panel_dock_widget.h"
#include "paintlabel.h"
#include "setting_panel.h"
#include "function_panel.h"
#include "widget_geometry_change_detector.h"
#include "screenshot_dialog.h"
#include "PluginsManager\interface_plugin.h"
#include "PluginsManager\plugin_manager.h"

/*****************************************************************************
** Namespace
*****************************************************************************/

namespace general_demo 
{
	/*****************************************************************************
	** Interface [MainWindow]
	*****************************************************************************/
	/**
	 * @brief Qt central, all operations relating to the view part here.
	 */
	class VisualizationFrame : public QMainWindow
	{
	Q_OBJECT

	public:
		VisualizationFrame(QWidget *parent = 0);
		~VisualizationFrame();

		void setApp( QApplication * app );

		void initialize();
		void loadPlugins();
		void setHideButtonVisibility( bool visible );

		QString getErrorMessage() const { return error_message_; }

	protected:
		void initMenus();
		void initToolbars();

		virtual void closeEvent(QCloseEvent *event); // Overloaded function

		void populateMenus(QObject * pluginInterface, InterfacePlugin* i);

		void hideDockImpl( Qt::DockWidgetArea area, bool hide );

	private:
		void createStatusBar();
		void translateLanguage();
		/*!
		 * \brief Saves the position and window states
		 */
		void writeSettings();
		/*!
		 * \brief Reeads the position and window states
		 */
		void readSettings();
		void sendGetTaskRequest(const QString &strTaskID);
		void changeLanguage(LANGUAGE language);
		void UpdateControls();

	Q_SIGNALS:
		/** @brief Emitted when the interface enters or leaves full screen mode. */
		void fullScreenChange( bool hidden );

	public Q_SLOTS:
		virtual void onDockPanelVisibilityChange( bool visible );  
		void updateStateTextSlot(const QString &strText);

	protected Q_SLOTS:
		void onSaveImage();
		void windowsTheme();
		void darculaTheme();
		void langEnglish();
		void langChinese();
		void onHelpWiki();
		void onHelpAbout();
		void hideLeftDock( bool hide );
		void hideRightDock( bool hide );

		void onDockPanelChange();

		void setImageSaveDirectory( const QString& directory);
		void setFullScreen(bool full_screen);
		void exitFullScreen();

	private Q_SLOTS:		
		void widgetActionTriggeredSlot();
		void getTaskResposeSlot(QNetworkReply*reply);
		void getTaskErrorSlot(QNetworkReply::NetworkError errorCode);

		void showFunctionSlot();
		void settingSlot();
		void openCameraSlot();
		void closeCameraSlot();
		void setDisplayConfigModified();
		void recMsgfromPluginManagerSlot(PluginMetaData metadata);

	protected:
		QApplication *app_;
		WidgetGeometryChangeDetector* geom_change_detector_;

		QMenu *file_menu_;
		QAction *save_image_action_;
		QAction *file_menu_quit_action_;
		QMenu *recent_configs_menu_;
		QMenu *view_menu_;
		QAction *fullscreen_action_;
		QMenu *plugin_menu_;
		QMenu *select_menu_;
		QMenu *theme_action_;
		QMenu *lang_action_;
		QAction *windows_theme_action_;
		QAction *darcula_theme_action_;
		QAction *english_action_;
		QAction *chinese_action_;
		QMenu *help_menu_;
		QAction *help_openwiki_action_;
		QAction *help_about_action_;

		QToolBar *toolbar_;
		QAction *action_visualization_;
		QAction *action_noDisplay_;
		QAction *m_action_setting_;
		QAction *m_action_tasklist_;
		QAction *m_action_opencamera_;
		QAction *m_action_closecamera_;
		QAction *m_action_function_;

		std::string last_config_dir_;
		std::string last_image_dir_;
		std::string home_dir_;
		bool initialized_;
		typedef std::deque<std::string> D_string;
		D_string recent_configs_;
		std::string package_path_;

	private:
		QTranslator* m_translator; //∑≠“Î∆˜
		LANGUAGE m_currentLanguage; //µ±«∞”Ô—‘
		QLabel *m_textStatus;
		QLabel *m_strTextStatus;
		QStatusBar* m_statusbar;
		
		QByteArray  m_imgData;
		int         m_imgSize;

		PaintLabel *m_imageLabel;
		QScrollArea *m_scrollArea;
		QNetworkAccessManager *m_pGetTaskManager;
		QDockWidget *m_dockWidgetA;
		QDockWidget *m_dockWidgetB;
		FunctionPanel* panel;
		QDockWidget *m_dockFunction;
		bool m_bLive;

		QToolButton* hide_left_dock_button_;
		QToolButton* hide_right_dock_button_;
		SettingPanel* m_taskPanel;
		QString error_message_; 
	
		bool toolbar_visible_;

	};

}  // namespace general_demo

#endif // GENERAL_DEMO_VISUALIZATION_FRAME_H
