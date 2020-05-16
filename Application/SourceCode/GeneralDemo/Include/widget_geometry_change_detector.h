#ifndef GENERAL_DEMO_WIDGET_GEOMETRY_CHANGE_DETECTOR_H
#define GENERAL_DEMO_WIDGET_GEOMETRY_CHANGE_DETECTOR_H

#include <QObject>

namespace general_demo
{

	/** @brief Utility class for watching for events which indicate that widget geometry has changed. */
	class WidgetGeometryChangeDetector: public QObject
	{
	Q_OBJECT
	public:
	  WidgetGeometryChangeDetector( QObject* parent = NULL );

	  virtual bool eventFilter( QObject* watched, QEvent* event );

	Q_SIGNALS:
	  /** @brief This signal is emitted whenever any filtered events are detected. */
	  void changed();
	};

} // end namespace general_demo

#endif // GENERAL_DEMO_WIDGET_GEOMETRY_CHANGE_DETECTOR_H
