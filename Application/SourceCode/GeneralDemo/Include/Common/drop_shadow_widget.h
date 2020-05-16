#ifndef GENERAL_DEMO_DROPSHADOWWIDGET_H
#define GENERAL_DEMO_DROPSHADOWWIDGET_H

#include <QDialog>
#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <qmath.h>

namespace general_demo
{
	class DropShadowWidget : public QDialog
	{
		Q_OBJECT

	public:

		explicit DropShadowWidget(QWidget *parent = 0);
		~DropShadowWidget();

	protected:

		void mousePressEvent(QMouseEvent *event);
		void mouseReleaseEvent(QMouseEvent *event);
		void mouseMoveEvent(QMouseEvent *event);
		virtual void paintEvent(QPaintEvent *event);

	private:

		QPoint move_point; //移动的距离
		bool mouse_press; //按下鼠标左键

	};

	class DropNoShadowWidget : public QDialog
	{
		Q_OBJECT

	public:

		explicit DropNoShadowWidget(QWidget *parent = 0);
		~DropNoShadowWidget();

	protected:

		void mousePressEvent(QMouseEvent *event);
		void mouseReleaseEvent(QMouseEvent *event);
		void mouseMoveEvent(QMouseEvent *event);
		virtual void paintEvent(QPaintEvent *event);

	private:

		QPoint move_point; //移动的距离
		bool mouse_press; //按下鼠标左键

	};
} // namespace general_demo

#endif //GENERAL_DEMO_DROPSHADOWWIDGET_H