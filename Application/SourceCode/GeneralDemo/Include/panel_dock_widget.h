#ifndef GENERAL_DEMO_PANEL_DOCK_WIDGET_H
#define GENERAL_DEMO_PANEL_DOCK_WIDGET_H

#include <QDockWidget>
#include <QLabel>

namespace general_demo
{
	class PanelDockWidget: public QDockWidget
	{
	Q_OBJECT
	public:
	  PanelDockWidget( const QString& name = "");

	  void setContentWidget( QWidget* child );

	  void setCollapsed( bool collapsed );

	  virtual void setVisible( bool visible );

	protected:

	  virtual void closeEvent ( QCloseEvent * event );

	public Q_SLOTS:

	  void setWindowTitle( QString title );

	  /** @ Override the visibility of the widget. **/
	  virtual void overrideVisibility( bool hide );

	Q_SIGNALS:
	  void closed();

	private:
	  // set to true if this panel was collapsed
	  bool collapsed_;
	  bool requested_visibility_;
	  bool forced_hidden_;
	  QLabel *icon_label_;
	  QLabel *title_label_;
	};


} // end namespace PanelDockWidget

#endif // GENERAL_DEMO_PANEL_DOCK_WIDGET_H
