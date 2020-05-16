#ifndef GENERAL_DEMO_MQTT_SUBSCRIBER_HPP
#define GENERAL_DEMO_MQTT_SUBSCRIBER_HPP
#include <qmqtt.h>
#include <QCoreApplication>
#include <QTimer>

const QHostAddress EXAMPLE_SUB_HOST = QHostAddress::LocalHost;
const quint16 EXAMPLE_SUB_PORT = 1883;
const QString EXAMPLE_SUB_TOPIC = "qmqtt/exampletopic";

namespace general_demo
{
	class MqttSubscriber : public QMQTT::Client
	{
		Q_OBJECT
	public:
		explicit MqttSubscriber(const QHostAddress& host = EXAMPLE_SUB_HOST,
			const quint16 port = EXAMPLE_SUB_PORT,
			QObject* parent = NULL)
			: QMQTT::Client(host, port, parent)
			, _qout(stdout)
		{
			setClientId("clientId2");
			setUsername("client2");
			setPassword("123456");
			connect(this, &MqttSubscriber::connected, this, &MqttSubscriber::onConnected);
			connect(this, &MqttSubscriber::subscribed, this, &MqttSubscriber::onSubscribed);
			connect(this, &MqttSubscriber::received, this, &MqttSubscriber::onReceived);
		}
		virtual ~MqttSubscriber() {}

		QTextStream _qout;

	public slots:
		void onConnected()
		{
			_qout << "connected" << endl;
			subscribe(EXAMPLE_SUB_TOPIC, 0);
		}

		void onSubscribed(const QString& topic)
		{
			_qout << "subscribed " << topic << endl;
		}

		void onReceived(const QMQTT::Message& message)
		{
			_qout << "publish received: \"" << QString::fromUtf8(message.payload())
				<< "\"" << endl;
		}
	};
}
#endif //GENERAL_DEMO_MQTT_SUBSCRIBER_HPP