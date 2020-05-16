#ifndef GENERAL_DEMO_PLUGINLIB_FACTORY_H
#define GENERAL_DEMO_PLUGINLIB_FACTORY_H

#include <QHash>
#include <QString>
#include <QStringList>

#include <string>
#include <vector>

#include "class_id_recording_factory.h"
#include "load_resource.h"

namespace general_demo
{

	template<class Type>
	class PluginlibFactory: public ClassIdRecordingFactory<Type>
	{
	private:
	  struct BuiltInClassRecord
	  {
		QString class_id_;
		QString package_;
		QString name_;
		QString description_;
		Type*(*factory_function_)();
	  };

	public:
	  PluginlibFactory( const QString& package, const QString& base_class_type )
		{

		}
	  virtual ~PluginlibFactory()
		{

		}


	  virtual QIcon getIcon( const QString& class_name ) const
	  {
		QIcon icon = QIcon( ":/icons/"+class_name+".png" );
		if ( icon.isNull() )
		{
		  icon = QIcon( ":/icons/default_class_icon.png");
		}

		return icon;
	  }

	  virtual void addBuiltInClass( const QString& package, const QString& name, const QString& description,
									Type* (*factory_function)() )
		{
		  BuiltInClassRecord record;
		  record.class_id_ = package + "/" + name;
		  record.package_ = package;
		  record.name_ = name;
		  record.description_ = description;
		  record.factory_function_ = factory_function;
		  built_ins_[ record.class_id_ ] = record;
		}

	protected:
	  /** @brief Instantiate and return a instance of a subclass of Type using our
	   *         pluginlib::ClassLoader.
	   * @param class_id A string identifying the class uniquely among
	   *        classes of its parent class.  cps::GridDisplay might be
	   *        cps/Grid, for example.
	   * @param error_return If non-NULL and there is an error, *error_return is set to a description of the problem.
	   * @return A new instance of the class identified by class_id, or NULL if there was an error.
	   *
	   * If makeRaw() returns NULL and error_return is not NULL,
	   * *error_return will be set.  On success, *error_return will not be
	   * changed. */
	  virtual Type* makeRaw( const QString& class_id, QString* error_return = NULL )
		{
		  typename QHash<QString, BuiltInClassRecord>::const_iterator iter = built_ins_.find( class_id );
		  if( iter != built_ins_.end() )
		  {
			Type* instance = iter->factory_function_();
			if( instance == NULL && error_return != NULL )
			{
			  *error_return = "Factory function for built-in class '" + class_id + "' returned NULL.";
			}
			return instance;
		  }
		  return NULL;
		}

	private:
	  QHash<QString, BuiltInClassRecord> built_ins_;
	};

} // end namespace general_demo

#endif // GENERAL_DEMO_PLUGINLIB_FACTORY_H
