/*!
 * \file    robot_panel.cpp
 * \date    2019.10.24
 * \author  zhusizhi
 * \version 1.0.0
 *
 * \brief   robot panel
 *
 */
#include "robot_panel.h"


namespace general_demo
{
	RobotPanel::RobotPanel(QWidget *parent) :
		QWidget(parent)
		, m_robotStatusGroup(NULL)
		, m_robotLogGroup(NULL)
	{
		this->setMinimumSize(500, 400);

		m_robotStatusGroup = new QGroupBox();
		m_robotLogGroup = new QGroupBox();

		//m_robotStatusGroup->setTitle(ROBOT_SENSOR_STATUS);
		//m_robotLogGroup->setTitle(ROBOT_RUN_LOG);
		QVBoxLayout* vLayout = new QVBoxLayout();
		vLayout->addWidget(m_robotStatusGroup);
		vLayout->addWidget(m_robotLogGroup);
		setLayout(vLayout);


	}

	RobotPanel::~RobotPanel()
	{
		if (NULL != m_robotStatusGroup)
		{
			delete m_robotStatusGroup;
			m_robotStatusGroup = NULL;
		}

		if (NULL != m_robotLogGroup)
		{
			delete m_robotLogGroup;
			m_robotLogGroup = NULL;
		}
	}

	void RobotPanel::setTitle(const QString &strTitle)
	{
		this->setWindowTitle(strTitle);
	}


} // namespace general_demo
