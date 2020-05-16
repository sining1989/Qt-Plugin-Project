#ifndef GENERAL_DEMO_LOGFILE_H
#define GENERAL_DEMO_LOGFILE_H

#include <QFile>
#include <QDateTime>
#include <QMutex>
#include <QTextStream>
#include "common.h"

namespace general_demo
{
	class qLogFile
	{
	public:
		qLogFile();
		~qLogFile();

	protected:
		static void LogMessage(QtMsgType type, const char *msg);
	private:
		static QFile*	q_pLogFile;
	};
}

#endif // GENERAL_DEMO_LOGFILE_H
