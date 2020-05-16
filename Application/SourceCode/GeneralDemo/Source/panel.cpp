#include <stdio.h>

#include "panel.h"

namespace general_demo
{

Panel::Panel( QWidget* parent )
  : QWidget( parent )
{
}

Panel::~Panel()
{
}

void Panel::save( Config config ) const
{
  config.mapSetValue( "Class", getClassId() );
  config.mapSetValue( "Name", getName() );
}

void Panel::load( const Config& config )
{
  QString name;
  if( config.mapGetString( "Name", &name ))
  {
    setName( name );
  }
}

} // end namespace site_cps
