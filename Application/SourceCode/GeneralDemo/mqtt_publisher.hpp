#ifndef GENERAL_DEMO_MQTT_PUBLISHER_HPP
#define GENERAL_DEMO_MQTT_PUBLISHER_HPP
#include <qmqtt.h>
#include <QCoreApplication>
#include <QTimer>

const QHostAddress EXAMPLE_PUB_HOST = QHostAddress::LocalHost;
const quint16 EXAMPLE_PUB_PORT = 1883;
const QString EXAMPLE_PUB_TOPIC = "qmqtt/exampletopic";

namespace general_demo
{
	class MqttPublisher : public QMQTT::Client
	{
		Q_OBJECT
	public:
		explicit MqttPublisher(const QHostAddress& host = EXAMPLE_PUB_HOST,
			const quint16 port = EXAMPLE_PUB_PORT,
			QObject* parent = NULL)
			: QMQTT::Client(host, port, parent)
			, _number(0)
		{
			setClientId("clientId1");
			setUsername("client1");
			setPassword("123456");
			connect(this, &MqttPublisher::connected, this, &MqttPublisher::onConnected);
			connect(&_timer, &QTimer::timeout, this, &MqttPublisher::onTimeout);
			connect(this, &MqttPublisher::disconnected, this, &MqttPublisher::onDisconnected);
		}

		virtual ~MqttPublisher() {}

		QTimer _timer;
		quint16 _number;

		public slots:
		void onConnected()
		{
			subscribe(EXAMPLE_PUB_TOPIC, 0);
			_timer.start(1000);
		}

		void onTimeout()
		{
			QMQTT::Message message(_number, EXAMPLE_PUB_TOPIC,
				QString("Number is %1").arg(_number).toUtf8());
			publish(message);
			_number++;
			if (_number >= 10)
			{
				_timer.stop();
				disconnectFromHost();
			}
		}

		void onDisconnected()
		{
			QTimer::singleShot(0, qApp, &QCoreApplication::quit);
		}
	};
} // end namespace general_demo
#endif //GENERAL_DEMO_MQTT_PUBLISHER_HPP