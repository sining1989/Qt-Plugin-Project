#include <QtWidgets/QApplication>
#include <QTextCodec>
#include <QFontDatabase>
#include <QTranslator>
#include <QSharedMemory>
#include <QMutex>
#include <QDateTime>

#include "PluginsManager\plugin_manager.h"
#include "visualizer_app.h"

void outputMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
	static QMutex mutex;
	mutex.lock();
	QString text;
	switch (type)
	{
	case QtDebugMsg:
		text = QString("Debug:");
		break;

	case QtWarningMsg:
		text = QString("Warning:");
		break;

	case QtCriticalMsg:
		text = QString("Critical:");
		break;

	case QtFatalMsg:
		text = QString("Fatal:");
	}
	QString context_info = QString("Func:%1 Line:%2").arg(context.function).arg(context.line);
	QString current_date_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");
	QString current_date = QString("(%1)").arg(current_date_time);
	QString message = QString("%1 %2 %3 %4").arg(current_date).arg(text).arg(context_info).arg(msg);
	QString rootPath = QCoreApplication::applicationDirPath();
	QFile file(rootPath + "/log/log.txt");
	if (!file.exists())
	{
		QDir path(rootPath + "/log");
		if (!path.exists())
		{
			path.mkdir(rootPath + "/log");
		}
	}
	file.open(QIODevice::WriteOnly | QIODevice::Append);
	QTextStream text_stream(&file);
	text_stream << message << "\r\n";
	file.flush();
	file.close();
	mutex.unlock();
}

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	qInstallMessageHandler(outputMessage);

	//QFontDatabase database;
	////QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB18030"));

	QTextCodec* codec = QTextCodec::codecForName("UTF-8");
	QTextCodec::setCodecForLocale(codec);

	//¼ÓÔØ²å¼þ
	PluginManager::getInstance().loadAllPlugins();
	PluginManager::getInstance().initSignalAndSlot();

	general_demo::VisualizerApp vapp;
	vapp.setApp(&app);
	if (vapp.init())
	{
		app.connect(&app, SIGNAL(lastWindowClosed()), &app, SLOT(quit()));
		return app.exec();
	}
	else
	{
		return 1;
	}
}
