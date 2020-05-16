/*!
 * \file    ims_panel.h
 * \date    2019.10.24
 * \author  zhusizhi
 * \version 1.0.0
 *
 * \brief   IMS panel
 *
 */
#ifndef GENERAL_DEMO_IMS_PANEL_H
#define GENERAL_DEMO_IMS_PANEL_H

#include "panel.h"
#include "ui_ims.h"
#include "QXmppMessage.h"
#include "QXmppClient.h"
#include "qmqtt.h"
#include "common_config.h"

namespace general_demo
{
	const quint16 PORT = 1883;
	const QString TOPIC = "qmqtt/topic";

	class IMSPanel : public Panel
	{
		Q_OBJECT

	public:
		IMSPanel(QWidget *parent = 0);
		virtual ~IMSPanel();

	protected:
		void resizeEvent(QResizeEvent *event);

	private:
		void loadXmppServer();
		void loadMqttServer();

	private Q_SLOTS:
		void errorClient(QXmppClient::Error error);
		void messageReceived(const QXmppMessage& msg);
		void updateStatusWidget();
		void sendXmppMsgSlot();
		void pubMqttTopicSlot();
		void pubMqttMsgSlot();
		void onConnectedPub();
		void onConnectedSub();
		void onSubscribed(const QString&);
		void onReceived(const QMQTT::Message&);

	private:
		/*! \brief dialogs GUI member class, build by Qt */
		Ui::imsPanelClass ui;

		QXmppClient m_xmppClient;
		QMQTT::Client *m_clientPub;
		QMQTT::Client *m_clientSub;
		quint16 m_number;
	}; 
} // namespace general_demo
#endif // GENERAL_DEMO_IMS_PANEL_H
