/*!
 * \file    robot_panel.h
 * \date    2019.10.24
 * \author  zhusizhi
 * \version 1.0.0
 *
 * \brief   robot panel
 *
 */
#ifndef GENERAL_DEMO_ROBOT_PANEL_H
#define GENERAL_DEMO_ROBOT_PANEL_H

#include <QWidget>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QPushButton>

//#include "cps.h"
//#include "config.h"
#include "common_config.h"

namespace general_demo
{

	/*! \brief setting dialog class declaration */
	class RobotPanel : public QWidget
	{
		Q_OBJECT

	public:
		/*! \brief std constructor */
		RobotPanel(QWidget *parent = 0);
		/*! \brief std destructor */
		virtual ~RobotPanel();

		void setTitle(const QString &strTitle);
	Q_SIGNALS:


	private Q_SLOTS:


	private:
		QGroupBox* m_robotStatusGroup;
		QGroupBox* m_robotLogGroup;
	};
} // namespace general_demo
#endif // GENERAL_DEMO_ROBOT_PANEL_H
