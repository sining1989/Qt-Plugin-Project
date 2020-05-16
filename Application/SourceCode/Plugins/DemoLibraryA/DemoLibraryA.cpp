#include "DemoLibraryA.h"
#include "qdebug.h"

namespace general_demo
{
	DemoLibraryA::DemoLibraryA(QWidget *parent) :
		QWidget(parent)
	{
		m_ui.setupUi(this);

		connect(m_ui.pushButton, SIGNAL(clicked()), this, SLOT(clickOpenImg()));
		connect(m_ui.pushButton2, SIGNAL(clicked()), this, SLOT(click2Animation()));
		connect(m_ui.pushButton_2, SIGNAL(clicked()), this, SLOT(click2MainProcess()));
	}

	DemoLibraryA::~DemoLibraryA()
	{

	}

	QString DemoLibraryA::toolName()
	{
		return "one";
	}

	QString DemoLibraryA::information()
	{
		return "one_info";
	}

	QWidget *DemoLibraryA::centerWidget()
	{
		//auto btn = new QPushButton("test_one");
		return this;
	}

	void DemoLibraryA::click2MainProcess()
	{
		PluginMetaData metadata;
		metadata.from = "DemoLibraryA";
		metadata.dest = "MainProcess";
		metadata.type = 1;
		metadata.object = m_ui.label;
		emit sendMsg2Manager(metadata);
	}

	void DemoLibraryA::recMsgfromManager(PluginMetaData metadata)
	{
		QString strText = QString("from %1 to %2").arg(metadata.from).arg(metadata.dest);
		m_ui.label_2->setText(strText);
		if (metadata.object)
		{
			qDebug() << "metadata.object:" << metadata.object->objectName();
		}
	}

	void DemoLibraryA::clickOpenImg()
	{
		QString path = QFileDialog::getOpenFileName(this, tr("111"), ".", tr("Image Files(*.jpg *.png)"));
		m_ui.label->setPixmap(QPixmap(path));
	}

	void DemoLibraryA::click2Animation()
	{
		PluginMetaData metadata;
		metadata.from = "DemoLibraryA";
		metadata.dest = "DemoLibraryB";
		metadata.type = 1;
		metadata.object = m_ui.label;
		emit sendMsg2Manager(metadata);
		qDebug() << "click2Animation";
	}
}