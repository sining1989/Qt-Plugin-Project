#ifndef GENERAL_DEMO_CLASS_ID_RECORDING_FACTORY_H
#define GENERAL_DEMO_CLASS_ID_RECORDING_FACTORY_H

#include "factory.h"

namespace general_demo
{

	template<class Type>
	/** @brief Templated factory which informs objects created by it what their class identifier string was.
	calls a setClassId() function on
	 * any instances created by a protected makeRaw() function (pure
	 * virtual in this class).*/
	class ClassIdRecordingFactory: public Factory
	{
	public:
	  /** @brief Instantiate and return a instance of a subclass of Type using makeRaw().
	   * @param class_id A string identifying the class uniquely among
	   *        classes of its parent class.  cps::GridDisplay might be
	   *        cps/Grid, for example.
	   * @param error_return If non-NULL and there is an error, *error_return is set to a description of the problem.
	   * @return A new instance of the class identified by class_id, or NULL if there was an error.
	   *
	   * If make() returns NULL and error_return is not NULL,
	   * *error_return will be set.  On success, *error_return will not be
	   * changed. */
	  virtual Type* make( const QString& class_id, QString* error_return = NULL )
		{
		  Type* obj = makeRaw( class_id, error_return );
		  if( obj != NULL )
		  {
			obj->setClassId( class_id );
		  }
		  return obj;
		}

	protected:
	  virtual Type* makeRaw( const QString& class_id, QString* error_return = NULL ) = 0;
	};

} // end namespace general_demo

#endif // GENERAL_DEMO_CLASS_ID_RECORDING_FACTORY_H
