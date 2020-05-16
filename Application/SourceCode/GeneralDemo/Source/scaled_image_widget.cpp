#include <QWidget>
#include <QPainter>

#include "scaled_image_widget.h"

namespace general_demo
{

	ScaledImageWidget::ScaledImageWidget(float scale, QWidget* parent)
		: QWidget(parent)
		, scale_(scale)
	{
	}

	void ScaledImageWidget::setImage(QPixmap image)
	{
		image_ = image;
		update();
	}

	QSize ScaledImageWidget::sizeHint() const
	{
		return image_.size() * scale_;
	}

	void ScaledImageWidget::paintEvent(QPaintEvent* event)
	{
		if (!image_.isNull())
		{
			QSize dest_size = image_.size();
			dest_size.scale(width(), height(), Qt::KeepAspectRatio);
			QRect dest_rect(width() / 2 - dest_size.width() / 2,
				height() / 2 - dest_size.height() / 2,
				dest_size.width(),
				dest_size.height());

			QPainter painter(this);
			painter.drawPixmap(dest_rect, image_);
		}
	}

} // end namespace general_demo
