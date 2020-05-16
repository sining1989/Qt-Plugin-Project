/*!
 * \file    other_panel.cpp
 * \date    2019.10.24
 * \author  zhusizhi
 * \version 1.0.0
 *
 * \brief   Other panel
 *
 */
#include "other_panel.h"

namespace general_demo
{
	OtherPanel::OtherPanel(QWidget *parent)
		: Panel(parent)
	{
		this->resize(800, 700);


	}

	OtherPanel::~OtherPanel()
	{

	}


	AnimationWidget::AnimationWidget(QWidget *parent)
		: DropShadowWidget(parent)
		, m_robot(NULL)
	{
		setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);

		m_iRet = -999;


	}

	AnimationWidget::~AnimationWidget()
	{
		if (NULL != m_robot)
		{
			delete m_robot;
			m_robot = NULL;
		}
	}

	void AnimationWidget::paintEvent(QPaintEvent *event)
	{
		DropShadowWidget::paintEvent(event);

		QPainter painter(this);
		painter.setPen(Qt::NoPen);
		painter.setBrush(Qt::white);
		painter.drawRect(QRect(0, 0, this->width(), this->height()));
	}

	void AnimationWidget::slotShowRobot()
	{
		if (-999 == m_iRet)
		{
			qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));

			QGraphicsScene scene(-400, -400, 800, 800);

			for (int i = 0; i < 10; ++i)
			{
				ColorItem *item = new ColorItem;
				item->setPos(::sin((i * 6.28) / 10.0) * 150,
					::cos((i * 6.28) / 10.0) * 150);

				scene.addItem(item);
			}

			m_robot = new Robot();
			m_robot->setTransform(QTransform::fromScale(1.2, 1.2), true);
			m_robot->setPos(0, -20);
			scene.addItem(m_robot);

			QGraphicsView view(&scene);
			view.setRenderHint(QPainter::Antialiasing);
			view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
			view.setBackgroundBrush(QColor(230, 200, 167));
			view.setParent(this);

			QVBoxLayout *vLayout = new QVBoxLayout();
			vLayout->addWidget(&view);
			vLayout->setSpacing(0);
			vLayout->setContentsMargins(0, 0, 0, 0);
			this->setLayout(vLayout);
			m_iRet = this->exec();
		}
		else
		{
			this->close();
			this->destroy();
			m_iRet = -999;
			this->resize(1065, 1032);
			slotShowRobot();
		}
	}

	void AnimationWidget::resizeEvent(QResizeEvent *event)
	{
		this->resize(this->size());
	}

} // namespace general_demo


