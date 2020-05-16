/*!
 * \file    other_panel.h
 * \date    2019.10.24
 * \author  zhusizhi
 * \version 1.0.0
 *
 * \brief   Other panel
 *
 */
#ifndef GENERAL_DEMO_OTHER_PANEL_H
#define GENERAL_DEMO_OTHER_PANEL_H

#include <QtGui>
#include <QDialog>
#include <QWidget>
#include <QGraphicsView>
#include <QTime>
#include <math.h>
#include <QVBoxLayout>
#include <QQmlApplicationEngine>
#include <QPainter>

#include "panel.h"
#include "common_config.h"
#include "./dragdroprobot/coloritem.h"
#include "./dragdroprobot/robot.h"
#include "drop_shadow_widget.h"

namespace general_demo
{	
	class OtherPanel : public Panel
	{
		Q_OBJECT

	public:
		explicit OtherPanel(QWidget *parent = 0);
		~OtherPanel();

	};

	class AnimationWidget : public DropShadowWidget
	{
		Q_OBJECT

	public:
		explicit AnimationWidget(QWidget *parent = 0);
		~AnimationWidget();

	protected:
		void paintEvent(QPaintEvent *event);
		void resizeEvent(QResizeEvent *event);

	public slots:
		void slotShowRobot();

	private:
		int m_iRet;
		Robot *m_robot;

	};

} // namespace general_demo
#endif // GENERAL_DEMO_OTHER_PANEL_H
