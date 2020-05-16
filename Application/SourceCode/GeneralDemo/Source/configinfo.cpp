#include "configinfo.h"
#include <QCoreApplication>
#include <QSettings>

namespace general_demo
{
	CConfigInfo* CConfigInfo::instance = NULL;

	CConfigInfo::CConfigInfo()
	{

	}

	CConfigInfo& CConfigInfo::operator =(CConfigInfo& info)
	{
		this->m_strXmppUrl = info.m_strXmppUrl;
		this->m_strXmppUserName = info.m_strXmppUserName;
		this->m_strXmppPassword = info.m_strXmppPassword;
		this->m_strTaskUrl = info.m_strTaskUrl;
		this->m_strTaskPort = info.m_strTaskPort;
		this->m_strCreateTaskUrl = info.m_strCreateTaskUrl;

		return *this;
	}

	CConfigInfo* CConfigInfo::getInstace()
	{
		if (instance == NULL)
		{
			instance = new CConfigInfo();
		}
		QString rootPath = QCoreApplication::applicationDirPath();
		QString fullName = rootPath + "/config/config.ini";

		QSettings *pCfg = new QSettings(fullName, QSettings::IniFormat);
		instance->m_strXmppUrl = pCfg->value("/config/xmppAdress").toString().toUtf8();
		instance->m_strXmppUserName = pCfg->value("/config/xmppUserName").toString().toUtf8();
		instance->m_strXmppPassword = pCfg->value("/config/xmppPassWord").toString().toUtf8();
		instance->m_strTaskUrl = pCfg->value("/config/taskAdress").toString().toUtf8();
		instance->m_strTaskPort = pCfg->value("/config/taskPort").toString().toUtf8();
		instance->m_strCreateTaskUrl = pCfg->value("/config/createTaskUrl").toString().toUtf8();

		delete pCfg;
		return instance;
	}
} // namespace general_demo