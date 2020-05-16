#include <QApplication>
#include <QTimer>

#include "common_config.h"
#include "visualizer_app.h"
#include "visualization_frame.h"


namespace general_demo
{

	VisualizerApp::VisualizerApp()
		: app_(0)
		, frame_(0)
	{
	}

	void VisualizerApp::setApp(QApplication * app)
	{
		app_ = app;
	}

	bool VisualizerApp::init()
	{
		frame_ = new VisualizationFrame();
		frame_->setApp(this->app_);
		frame_->show();

		return true;
	}

	VisualizerApp::~VisualizerApp()
	{
		delete frame_;
	}


} // namespace general_demo
