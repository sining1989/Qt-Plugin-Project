#include "logfile.h"
#include <QtDebug>
#include <QFile>
#include <QTextStream>
#include <QtWidgets/QApplication>
#include <QTextCodec>
#include <QFontDatabase>
#include <QTranslator>
#include <QSharedMemory>
#include <QMutex>
#include <QDateTime>
namespace general_demo
{
	QFile* qLogFile::q_pLogFile = NULL;
	qLogFile::qLogFile()
	{
		//ÈÕÖ¾¼ÇÂ¼
		QString file = GetModulePath() + "log/" ;
		QDir dir(file);
		if( !dir.exists() )
		{
			dir.mkdir(file);
		}
		file += QString("Demo-%1.log").arg(QDateTime::currentDateTime().toString("yyyyMMdd-hhmm-sszzz"));
		
		q_pLogFile = new QFile(file);
		q_pLogFile->open(QIODevice::WriteOnly | QIODevice::Text);
		qInstallMsgHandler(LogMessage);
	}

	qLogFile::~qLogFile()
	{

	}

	void qLogFile::LogMessage(QtMsgType type, const char *msg)
	{
		static QMutex mutex;
		QMutexLocker locker(&mutex); 
	
		QString text;
		switch(type)
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
			break;
		}
		QString message = QString("[%1] %2 %3").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz")).arg(text).arg(msg);
	
		if( q_pLogFile )
		{
			QTextStream text_stream(q_pLogFile);
			text_stream << message << endl;
		}
	}
}