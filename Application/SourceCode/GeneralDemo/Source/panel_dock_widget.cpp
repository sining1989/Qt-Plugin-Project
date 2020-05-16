#include <QChildEvent>
#include <QHBoxLayout>
#include <QLabel>
#include <QToolButton>
#include <QCloseEvent>
#include "common_config.h"
#include "panel_dock_widget.h"

namespace general_demo
{
	PanelDockWidget::PanelDockWidget( const QString& name)
	  : QDockWidget( name)
	  , collapsed_(false)
	{

	}

	void PanelDockWidget::setWindowTitle( QString title )
	{
		QDockWidget::setWindowTitle( title );
	}


	void PanelDockWidget::setCollapsed( bool collapse )
	{
		if ( collapsed_ == collapse || isFloating() ) return;


		if ( collapse )
		{
		if ( isVisible() )
		{
			PanelDockWidget::setVisible( false );
			collapsed_ = collapse;
		}
		}
		else
		{
			PanelDockWidget::setVisible( true );
			collapsed_ = collapse;
		}
	}

	void PanelDockWidget::setContentWidget( QWidget* child )
	{
		setWidget( child );
	}

	void PanelDockWidget::closeEvent ( QCloseEvent * event )
	{
		Q_EMIT closed();
	}

	void PanelDockWidget::setVisible( bool visible )
	{
		requested_visibility_ = visible;
		QDockWidget::setVisible(requested_visibility_ && !forced_hidden_);
	}

	void PanelDockWidget::overrideVisibility( bool hidden )
	{
		forced_hidden_ = hidden;
		setVisible(requested_visibility_);
	}

} // end namespace site_cps
