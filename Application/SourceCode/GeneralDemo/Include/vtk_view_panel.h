/*!
 * \file    vtk_view_panel.h
 * \date    2019.10.24
 * \author  zhusizhi
 * \version 1.0.0
 *
 * \brief   VtkView panel
 *
 */
#ifndef GENERAL_DEMO_VTKVIEW_PANEL_H
#define GENERAL_DEMO_VTKVIEW_PANEL_H

#include <vtkAutoInit.h> 
VTK_MODULE_INIT(vtkRenderingOpenGL2);
VTK_MODULE_INIT(vtkInteractionStyle);

#include "panel.h"
#include "common_config.h"
#include "ui_vtk_view.h"

#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/io/vtk_io.h>
#include <pcl/io/obj_io.h>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/visualization/common/common.h>
#include <pcl/common/common.h> 
#include <pcl/common/impl/io.hpp>
#include <pcl/common/transforms.h>
#include "QVTKWidget.h"
#include <vtkRenderWindow.h>

#include <QThread>
#include <QDir>

namespace general_demo
{	
	typedef pcl::PointXYZRGBA PointTRGBA;
	typedef pcl::PointCloud<PointTRGBA> PointCloudTRGBA;

	class WorkerThread;
	class VtkViewPanel : public Panel
	{
		Q_OBJECT

	public:
		explicit VtkViewPanel(QWidget *parent = 0);
		~VtkViewPanel();

		void openRun();

	private slots:
		bool prepareEventThread();
		void workThreadStarted();
		void workThreadFinished();

	protected:
		void resizeEvent(QResizeEvent *event);

	private:
		void setCloudColor(unsigned int r, unsigned int g, unsigned int b);
		void setAlpha(unsigned int a);

	private:
		/*! \brief dialogs GUI member class, build by Qt */
		Ui::vtkViewPanelClass ui;

		WorkerThread *m_workThread;

		boost::shared_ptr<pcl::visualization::PCLVisualizer> m_mainViewer;
		PointCloudTRGBA::Ptr m_pointCloudFile;  //µãÔÆÖ¸Õë
	};


	class WorkerThread : public QThread
	{
		Q_OBJECT
	public:
		WorkerThread(VtkViewPanel *mainWindow)
			: m_mainWindowWorker(mainWindow) {};
		virtual ~WorkerThread() {};

		void run() { m_mainWindowWorker->openRun(); }
	protected:
		VtkViewPanel *m_mainWindowWorker;

	};

} // namespace general_demo
#endif // GENERAL_DEMO_VTKVIEW_PANEL_H
