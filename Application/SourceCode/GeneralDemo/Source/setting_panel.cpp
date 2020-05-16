/*!
 * \file    setting_panel.cpp
 * \date    2019.10.24
 * \author  zhusizhi
 * \version 1.0.0
 *
 * \brief   setting panel
 *
 */
#include "setting_panel.h"
#include "common_config.h"

namespace general_demo
{

	SettingPanel::SettingPanel(QWidget *parent) :
		Panel(parent)
	{
		ui.setupUi(this);

		connect(ui.resetBtn, SIGNAL(clicked()), this, SLOT(resetCountersSlot()));
		connect(ui.saveBtn, SIGNAL(clicked()), this, SLOT(saveCurSettingSlot()));


		initUI();

	}

	SettingPanel::~SettingPanel()
	{

	}


	void SettingPanel::resetCountersSlot()
	{
		initUI();

	}

	void SettingPanel::initUI()
	{
		if (NULL == m_pConfigInfo)
		{
			m_pConfigInfo = CConfigInfo::getInstace();
		}
		ui.lineEdit_1->setText(m_pConfigInfo->getInstace()->m_strXmppUrl);
		ui.lineEdit_2->setText(m_pConfigInfo->getInstace()->m_strXmppUserName);
		ui.lineEdit_3->setText(m_pConfigInfo->getInstace()->m_strXmppPassword);

		ui.lineEdit_4->setText(m_pConfigInfo->getInstace()->m_strTaskUrl);
		ui.lineEdit_5->setText(m_pConfigInfo->getInstace()->m_strTaskPort);
	}

	void SettingPanel::saveCurSettingSlot()
	{
		m_pConfigInfo->m_strXmppUrl = ui.lineEdit_1->text();
		m_pConfigInfo->m_strXmppUserName = ui.lineEdit_2->text();
		m_pConfigInfo->m_strXmppPassword = ui.lineEdit_3->text();
		m_pConfigInfo->m_strTaskUrl = ui.lineEdit_4->text();
		m_pConfigInfo->m_strTaskPort = ui.lineEdit_5->text();

		QString strRootPath = QCoreApplication::applicationDirPath();
		QString fullName = strRootPath + "/config.ini";
		QSettings *pCfg = new QSettings(fullName, QSettings::IniFormat);
		pCfg->setValue("/config/xmppAdress", m_pConfigInfo->m_strXmppUrl);
		pCfg->setValue("/config/xmppUserName", m_pConfigInfo->m_strXmppUserName);
		pCfg->setValue("/config/xmppPassWord", m_pConfigInfo->m_strXmppPassword);
		pCfg->setValue("/config/taskAdress", m_pConfigInfo->m_strTaskUrl);
		pCfg->setValue("/config/taskPort", m_pConfigInfo->m_strTaskPort);

		delete pCfg;

	}
} // namespace general_demo


