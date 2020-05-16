/*!
 * \file    functionpanel.cpp
 * \date    2019.10.24
 * \author  zhusizhi
 * \version 1.0.0
 *
 * \brief   setting information panel
 *
 */
#include "function_panel.h"
#include "common_config.h"

namespace general_demo
{

	FunctionPanel::FunctionPanel(QWidget *parent) :
		QWidget(parent)
		, m_imsPanel(NULL)
	{
		setMinimumSize(800, 700);

		QStringList string_list;
		string_list << ":/toolWidget/ims" << ":/toolWidget/cv" << ":/toolWidget/3d" << ":/toolWidget/web" << ":/toolWidget/other";

		QHBoxLayout *button_layout = new QHBoxLayout();
		QSignalMapper *signal_mapper = new QSignalMapper(this);
		for (int i = 0; i<string_list.size(); i++)
		{
			ToolButton *tool_button = new ToolButton(string_list.at(i));
			button_list.append(tool_button);
			connect(tool_button, SIGNAL(clicked()), signal_mapper, SLOT(map()));
			signal_mapper->setMapping(tool_button, QString::number(i, 10));

			button_layout->addWidget(tool_button, 0, Qt::AlignBottom);
		}
		connect(signal_mapper, SIGNAL(mapped(QString)), this, SLOT(turnPageMappedSlot(QString)));

		m_imsPanel = new IMSPanel();
		m_opencvPanel = new OpenCVPanel();
		m_vtkViewPanel = new VtkViewPanel();
		m_webenginePanel = new WebEnginePanel();
		m_otherPanel = new AnimationWidget();
		connect(this, SIGNAL(signalShowRobot()), m_otherPanel, SLOT(slotShowRobot()));

		m_statked_widget = new QStackedWidget();
		QPalette palette;
		palette.setBrush(QPalette::Window, QBrush(Qt::white));
		m_statked_widget->setPalette(palette);
		m_statked_widget->setAutoFillBackground(true);
		// 添加页面（用于切换）
		m_statked_widget->addWidget(m_imsPanel);
		m_statked_widget->addWidget(m_opencvPanel);
		m_statked_widget->addWidget(m_vtkViewPanel);
		m_statked_widget->addWidget(m_webenginePanel);
		m_statked_widget->addWidget(m_otherPanel);

		QVBoxLayout *center_layout = new QVBoxLayout();
		center_layout->addLayout(button_layout);
		center_layout->addWidget(m_statked_widget);
		center_layout->setSpacing(0);
		center_layout->setContentsMargins(0, 0, 0, 0);
		setLayout(center_layout);
		connect(this, SIGNAL(turnPage(int)), this, SLOT(turnPageSlot(int)));

		translateLanguage();
	}

	FunctionPanel::~FunctionPanel()
	{

	}
	void FunctionPanel::translateLanguage()
	{
		button_list.at(0)->setText(TOOLWIDGET_IMS);
		button_list.at(1)->setText(TOOLWIDGET_CV);
		button_list.at(2)->setText(TOOLWIDGET_3D);
		button_list.at(3)->setText(TOOLWIDGET_WEB);
		button_list.at(4)->setText(TOOLWIDGET_OTHER);
	}

	void FunctionPanel::turnPageMappedSlot(QString current_page)
	{
		bool ok;
		int current_index = current_page.toInt(&ok, 10);

		for (int i = 0; i<button_list.count(); i++)
		{
			ToolButton *tool_button = button_list.at(i);
			if (current_index == i)
			{
				tool_button->setMousePress(true);
			}
			else
			{
				tool_button->setMousePress(false);
			}
		}

		emit turnPage(current_index);
	}


	void FunctionPanel::turnPageSlot(int current_page)
	{
		if (current_page == 0)
		{
			m_statked_widget->setCurrentWidget(m_imsPanel);
		}
		else if (current_page == 1)
		{
			m_statked_widget->setCurrentWidget(m_opencvPanel);
		}
		else if (current_page == 2)
		{
			m_statked_widget->setCurrentWidget(m_vtkViewPanel);
		}
		else if (current_page == 3)
		{
			m_statked_widget->setCurrentWidget(m_webenginePanel);
		}
		else if (current_page == 4)
		{
			m_statked_widget->setCurrentWidget(m_otherPanel);
			emit signalShowRobot();
		}
	}




} // namespace general_demo


