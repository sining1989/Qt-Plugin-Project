#include "DemoLibraryB.h"
#include "qdebug.h"

namespace general_demo
{
	DemoLibraryB::DemoLibraryB(QWidget *parent)
		: QWidget(parent)
		, m_tipsLabel(NULL)
	{
		m_tipsLabel = new QLabel();
		m_tipsLabel->setGeometry(QRect(100, 20, 200, 50));
	}

	QString DemoLibraryB::toolName()
	{
		return "two";
	}

	QString DemoLibraryB::information()
	{
		return "two_info";
	}

	QWidget *DemoLibraryB::centerWidget()
	{
		return m_tipsLabel;
	}

	void DemoLibraryB::recMsgfromManager(PluginMetaData metadata)
	{
		QString strText = QString("from %1 to %2").arg(metadata.from).arg(metadata.dest);
		m_tipsLabel->setText(strText);
		if (metadata.object)
		{
			animation((QWidget*)metadata.object);
			qDebug() << "metedata.object:" << metadata.object->objectName();
		}
	}

	void DemoLibraryB::animation(QWidget *widget)
	{
		QPropertyAnimation *pScaleAnimation = new QPropertyAnimation(widget, "geometry");
		pScaleAnimation->setDuration(1000);
		pScaleAnimation->setStartValue(QRect(0, 0, 0, 0));
		pScaleAnimation->setEndValue(QRect(100, 100, 200, 200));
		pScaleAnimation->start();
	}
}