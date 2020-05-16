#ifndef GENERAL_DEMO_FACTORY_H
#define GENERAL_DEMO_FACTORY_H

#include <QString>
#include <QStringList>
#include <QIcon>

namespace general_demo
{

	/** @brief Abstract superclass representing the ability to get a list
	 * of class IDs and the ability to get name, description, and package
	 * strings for each.  Actually instantiating objects must be done by
	 * subclasses specialized for specific types. */
	class Factory
	{
	public:
	  virtual ~Factory() {}

	  virtual QIcon getIcon( const QString& class_id ) const = 0;
	};

} // end namespace general_demo

#endif // GENERAL_DEMO_FACTORY_H
