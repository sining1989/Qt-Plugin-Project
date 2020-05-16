/*!
 * \file    webengine_panel.h
 * \date    2019.10.24
 * \author  zhusizhi
 * \version 1.0.0
 *
 * \brief   WebEngineView panel
 *
 */
#ifndef GENERAL_DEMO_WEBENGINE_PANEL_H
#define GENERAL_DEMO_WEBENGINE_PANEL_H

#include "panel.h"
#include "common_config.h"

#include <qwebengineview.h>
#include <QUrl>

namespace general_demo
{	
	class SWebEngineView : public QWebEngineView
	{
		Q_OBJECT
	public:
		explicit SWebEngineView(QWidget *parent = 0);

		QList<QUrl> listUrl() const;
		void addItemUrl(QUrl url);
	protected:
		/**
		* @brief createWindow
		* @param type
		* @return
		*/
		QWebEngineView *createWindow(QWebEnginePage::WebWindowType type);
	private:
		QList<QUrl> m_listUrl;
	};




	class WebEnginePanel : public Panel
	{
		Q_OBJECT

	public:
		explicit WebEnginePanel(QWidget *parent = 0);
		~WebEnginePanel();

	protected:
		void paintEvent(QPaintEvent *event);

	protected:
		void resizeEvent(QResizeEvent *event);

	private:
		QWebEngineView *m_webView;



	};


} // namespace general_demo
#endif // GENERAL_DEMO_WEBENGINE_PANEL_H
