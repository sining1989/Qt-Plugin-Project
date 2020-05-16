
#ifndef GENERAL_DEMO_PAINTLABEL_H_
#define GENERAL_DEMO_PAINTLABEL_H_

/*****************************************************************************
** Includes
*****************************************************************************/

#include <QLabel>
#include <QImage>
#include <QPaintEvent>

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace general_demo 
{

	/*****************************************************************************
	** Class
	*****************************************************************************/
	class PaintLabel : public QLabel
	{
		Q_OBJECT
	public:
		explicit PaintLabel(QWidget *parent = 0);

		/*! Draws an QImage on the label */
		void setImage(QImage &image);

		/*! Draws an QImage on the label */
		void setImage(QImage &image, double scaleFactor = 1.0, bool adjustSize = false);

		/*! Draws an pixmap on the label */
		void setPixmap(const QPixmap &pixmap);

		/*! Adjusts the size of the widget to fit its contents.*/
		void adjustSize();

		/*! This property holds whether the label will scale its contents to fill all available space. */
		void setScaledContents(bool scaled);

		/*! This property holds whether the label will scale its contents to fill all available space. */
		bool scaledContents();

		/*! scales the current image and paints it */
		void scale(double factor);

	public Q_SLOTS:
		/*! Clears the previous paintings */
		void clear(bool repaint);

	protected:
		void paintEvent(QPaintEvent *ev);

	private:
		QImage m_Image;
		bool m_bScaledContent;
	};

}  // namespace general_demo

#endif /* GENERAL_DEMO_PAINTLABEL_H_ */
