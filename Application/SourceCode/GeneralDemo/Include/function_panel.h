/*!
 * \file    functionpanel.h
 * \date    2019.10.24
 * \author  zhusizhi
 * \version 1.0.0
 *
 * \brief   function panel
 *
 */
#ifndef GENERAL_DEMO_FUNCTION_PANEL_H
#define GENERAL_DEMO_FUNCTION_PANEL_H

#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/QLabel>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QSignalMapper>
#include "tool_button.h"
#include "ims_panel.h"
#include "opencv_panel.h"
#include "vtk_view_panel.h"
#include "webengine_panel.h"
#include "other_panel.h"

/*! \brief setting panel class declaration */
namespace general_demo
{

	class FunctionPanel : public QWidget
	{
		Q_OBJECT

	public:
		/*! \brief std constructor */
		FunctionPanel(QWidget *parent = 0);
		/*! \brief std destructor */
		virtual ~FunctionPanel();
	
		void translateLanguage();

	signals:
		void turnPage(int current_page);
		void signalShowRobot();

	public slots:
		void turnPageMappedSlot(QString current_page);
		void turnPageSlot(int current_page);

	private:
		QWidget *kill_mummy_widget;
		QStackedWidget *m_statked_widget;
		QList<ToolButton *> button_list;
		IMSPanel *m_imsPanel;
		OpenCVPanel *m_opencvPanel;
		VtkViewPanel *m_vtkViewPanel;
		WebEnginePanel *m_webenginePanel;
		AnimationWidget *m_otherPanel;
	}; 
} // namespace general_demo
#endif // GENERAL_DEMO_FUNCTION_PANEL_H
