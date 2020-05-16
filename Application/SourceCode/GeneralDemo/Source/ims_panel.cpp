/*!
 * \file    ims_panel.cpp
 * \date    2019.10.24
 * \author  zhusizhi
 * \version 1.0.0
 *
 * \brief   IMS panel
 *
 */
#include "ims_panel.h"

namespace general_demo
{

	IMSPanel::IMSPanel(QWidget *parent) :
		Panel(parent)
		, m_number(0)
	{
		ui.setupUi(this);

		connect(ui.pushButton_xmpp_send, SIGNAL(clicked()), SLOT(sendXmppMsgSlot()));
		connect(ui.pushButton_publish, SIGNAL(clicked()), SLOT(pubMqttTopicSlot()));
		connect(ui.pushButton_mqtt_send, SIGNAL(clicked()), SLOT(pubMqttMsgSlot()));

		loadXmppServer();
		loadMqttServer();
	}

	IMSPanel::~IMSPanel()
	{
		m_xmppClient.disconnectFromServer();
		m_clientSub->disconnectFromHost();
		m_clientPub->disconnectFromHost();
	}

	void IMSPanel::resizeEvent(QResizeEvent *event)
	{
		ui.widget->resize(this->size());
	}

	void IMSPanel::loadXmppServer()
	{
		//login xmpp server
		bool check;
		Q_UNUSED(check);

		m_xmppClient.configuration().setJid("zsz1@103.252.196.208");
		m_xmppClient.configuration().setPassword("123456");
		m_xmppClient.configuration().setIgnoreSslErrors(true);
		m_xmppClient.connectToServer(m_xmppClient.configuration());
		check = connect(&m_xmppClient, SIGNAL(error(QXmppClient::Error)),
			this, SLOT(errorClient(QXmppClient::Error)));
		Q_ASSERT(check);

		check = connect(&m_xmppClient, SIGNAL(messageReceived(QXmppMessage)),
			SLOT(messageReceived(QXmppMessage)));
		Q_ASSERT(check);
		QXmppLogger::getLogger()->setLoggingType(QXmppLogger::SignalLogging);

		check = connect(&m_xmppClient, SIGNAL(connected()), SLOT(updateStatusWidget()));
		Q_ASSERT(check); 
	}

	void IMSPanel::errorClient(QXmppClient::Error error)
	{
		switch (error)
		{
		case QXmppClient::SocketError:
			ui.textBrowser_xmpp->append("Socket error");
			break;
		case QXmppClient::KeepAliveError:
			ui.textBrowser_xmpp->append("Keep alive error");
			break;
		case QXmppClient::XmppStreamError:
			switch (m_xmppClient.xmppStreamError())
			{
			case QXmppStanza::Error::NotAuthorized:
				ui.textBrowser_xmpp->append("Invalid password");
				break;
			default:
				ui.textBrowser_xmpp->append("Stream error");
				break;
			}
			break;
		default:
			break;
		}
	}

	void IMSPanel::messageReceived(const QXmppMessage& msg)
	{
		if (msg.body().isEmpty())
		{
			return;
		}

		//recevied from server
		QString strMsgInfo = msg.body();
		ui.textBrowser_xmpp->append(strMsgInfo);
	}

	void IMSPanel::updateStatusWidget()
	{
		const QString strUserName = m_xmppClient.configuration().jidBare();

		// initialise status widget
		QString strStatus = "";
		if (QXmppPresence::Available == m_xmppClient.clientPresence().type())
		{
			switch (m_xmppClient.clientPresence().availableStatusType())
			{
			case QXmppPresence::Online:
			case QXmppPresence::Chat:
				strStatus = XMPP_STATUS_ONLINE;
				break;
			case QXmppPresence::Away:
			case QXmppPresence::XA:
				strStatus = XMPP_STATUS_AWAY;
				break;
			case QXmppPresence::DND:
				strStatus = XMPP_STATUS_DND;
				break;
			case QXmppPresence::Invisible:
				strStatus = XMPP_STATUS_INVISIBLE;
				break;
			default:
				break;
			}
		}
		else if (QXmppPresence::Unavailable)
		{
			strStatus = XMPP_STATUS_INVISIBLE;
		}

		QString strLogin = QString("%1%2%3").arg(strUserName).arg(XMPP_LOGIN).arg(strStatus);
		ui.textBrowser_xmpp->append(strLogin);
	}

	void IMSPanel::sendXmppMsgSlot()
	{
		QString strJID = ui.lineEdit_id->text() + "@103.252.196.208";
		QString strSendInfo = ui.textEdit_xmpp->toPlainText();
		m_xmppClient.sendMessage(strJID, strSendInfo);
		//发送完后清除
		ui.textEdit_xmpp->clear();
	}

	void IMSPanel::loadMqttServer()
	{
		//cmd 进入E:\Qt\emqx-windows-v3.2.3\emqx\bin 输入emqx console启动 
		//打开浏览器输入http://127.0.0.1:18083	默认用户名 admin 默认密码 public
		m_clientPub = new QMQTT::Client(QHostAddress::LocalHost, PORT);
		m_clientSub = new QMQTT::Client(QHostAddress::LocalHost, PORT);
		m_clientSub->setClientId("clientId2");
		m_clientSub->setUsername("client2");
		m_clientSub->setPassword("123456");
		m_clientSub->connectToHost();
		m_clientPub->setClientId("clientId1");
		m_clientPub->setUsername("client1");
		m_clientPub->setPassword("123456");
		m_clientPub->connectToHost();

		connect(m_clientPub, SIGNAL(connected()), this, SLOT(onConnectedPub()));
		connect(m_clientSub, SIGNAL(connected()), this, SLOT(onConnectedSub()));
		connect(m_clientSub, SIGNAL(subscribed(const QString&)), this, SLOT(onSubscribed(const QString&)));
		connect(m_clientSub, SIGNAL(received(const QMQTT::Message&)), this, SLOT(onReceived(const QMQTT::Message&)));

	}

	void IMSPanel::onConnectedPub()
	{
		QString strTopic = ui.lineEdit_topic->text();
		if (strTopic.isEmpty())
			strTopic = TOPIC;
		QMQTT::Message message(m_number, strTopic, QString("mqtt client had connectted.").toLatin1());
		m_clientPub->publish(message);
		m_number++;
	}

	void IMSPanel::onConnectedSub()
	{
		QString strTopic = ui.lineEdit_topic->text();
		if (strTopic.isEmpty())
			strTopic = TOPIC;
		m_clientSub->subscribe(strTopic, 0);
	}

	void IMSPanel::onSubscribed(const QString& topic)
	{
		ui.textBrowser_mqtt->append(QString("subscribed topic is:%1").arg(topic));
	}

	void IMSPanel::onReceived(const QMQTT::Message& message)
	{
		ui.textBrowser_mqtt->append(QString::fromUtf8(message.payload()));
	}

	void IMSPanel::pubMqttTopicSlot()
	{
		QString strTopic = ui.lineEdit_topic->text();
		if (strTopic.isEmpty())
			strTopic = TOPIC;
		/*QoS Level 0：至多一次
		这是最简单的级别，无需客户端确认，其可靠性与基础网络层 TCP / IP 一致。

		QoS Level 1：至少一次，有可能重复
		确保至少向客户端发送一次信息，不过也可发送多次；在接收数据包时，需要客户端返回确认消息（ACK 包）。这种方式常用于传递确保交付的信息，但开发人员必须确保其系统可以处理重复的数据包。

		QoS Level 2：只有一次，确保消息只到达一次
		这是最不常见的服务质量级别，确保消息发送且仅发送一次。这种方法需要交换4个数据包，同时也会降低消息代理的性能。*/
		m_clientSub->subscribe(strTopic, 1);
	}

	void IMSPanel::pubMqttMsgSlot()
	{
		QString strTopic = ui.lineEdit_topic->text();
		if (strTopic.isEmpty())
			strTopic = TOPIC;
		QString strPubMsg = ui.textEdit_mqtt->toPlainText();

		if (m_clientPub->isConnectedToHost())
		{
			QMQTT::Message message(m_number, strTopic, QString("%1").arg(strPubMsg).toLatin1());
			quint16 iPub = m_clientPub->publish(message);
			m_number++;
		}
		
		//发送完后清除
		ui.textEdit_xmpp->clear();
	}
} // namespace general_demo


