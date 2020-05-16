/*!
 * \file    webengine_panel.cpp
 * \date    2019.10.24
 * \author  zhusizhi
 * \version 1.0.0
 *
 * \brief   WebEngineView panel
 *
 */
#include "webengine_panel.h"

namespace general_demo
{
	SWebEngineView::SWebEngineView(QWidget *parent) : QWebEngineView(parent)
	{
	}

	QList<QUrl> SWebEngineView::listUrl() const
	{
		return m_listUrl;
	}

	void SWebEngineView::addItemUrl(QUrl url)
	{
		m_listUrl << url;
	}

	QWebEngineView *SWebEngineView::createWindow(QWebEnginePage::WebWindowType type)
	{
		Q_UNUSED(type);
		m_listUrl << this->url();
		return this;
	}


	WebEnginePanel::WebEnginePanel(QWidget *parent)
		: Panel(parent)
	{
		this->resize(600, 320);

		m_webView = new QWebEngineView(this);
		m_webView->setStyleSheet("background-color:rgb(150,147,88); padding: 7px ; color:rgb(255,255,255)");
		QUrl url(QStringLiteral("http://map.baidu.com/")); //https://cdn.viewspread.com/website/models/model-22/index.html
		m_webView->load(url);
		//m_webView->addItemUrl(url);
		m_webView->show();

	}

	WebEnginePanel::~WebEnginePanel()
	{
		if (NULL != m_webView)
		{
			delete m_webView;
			m_webView = NULL;
		}
	}

	void WebEnginePanel::paintEvent(QPaintEvent *event)
	{
		QWidget::paintEvent(event);

		QPainter painter(this);
		painter.setPen(Qt::NoPen);
		painter.setBrush(Qt::white);
		painter.drawRect(QRect(0, 0, this->width(), this->height()));
	}

	void WebEnginePanel::resizeEvent(QResizeEvent *event)
	{
		m_webView->resize(this->size());
	}

} // namespace general_demo


