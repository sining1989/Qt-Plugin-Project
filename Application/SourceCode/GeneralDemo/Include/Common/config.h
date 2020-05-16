#ifndef GENERAL_DEMO_CONFIG_H
#define GENERAL_DEMO_CONFIG_H

#include <stdio.h>
#include <string>

#include <QMap>
#include <QString>
#include <QVariant>
#include <memory>

namespace general_demo
{
	class Config
	{
	private:
	  class Node;
	  typedef std::shared_ptr<Node> NodePtr;

	public:
	  /** @brief Default constructor.  Creates an empty config object. */
	  Config();
	  /** @brief Copy constructor.  Copies only the reference to the data, not the data itself. */
	  Config( const Config& source );
	  /** @brief Convenience constructor, makes a Value type Config object with the given value. */
	  Config( QVariant value );

	  /** @brief Make this a deep copy of source. */
	  void copy( const Config& source );

	  /** @brief Possible types a Config Node can have are Map, List,
	   * Value, and Empty.  Invalid means the Config object does not
	   * point to a Node at all.
	   *
	   * Invalid Config objects are returned by data access functions when
	   * the data does not exist, like listChildAt(7) on a list of length
	   * 3, or mapGetChild("foo") on a Value Node. */
	  enum Type { Map, List, Value, Empty, Invalid };

	  /** @brief Return the Type of the referenced Node, or Invalid if
		  this Config does not refer to a Node at all. */
	  Type getType() const;

	  /** @brief Set the type of this Config Node.
	   *
	   * If @a new_type is Invalid, this de-references the node and makes
	   * the Config object invalid.  If the new type is different from the
	   * old type, this deletes the existing data in the Node and changes
	   * the Node's type to @new_type.  If this does not change the type
	   * of the Node, no data is deleted and nothing is changed.
	   *
	   * If this Config is currently invalid and @a new_type is not
	   * Invalid, this will create a new Node and reference it.  */
	  void setType( Type new_type );

	  /** @brief Returns true if the internal Node reference is valid,
		  false if not.  Same as (getType() != Invalid). */
	  bool isValid() const;

	  /** @brief Set a named child to the given value.
	   *
	   * Since QVariant has constructors for int, float, bool, QString,
	   * and other supported types, you can call mapSetValue() directly
	   * with your data in most cases:
	   *
	   *  config.mapSetValue( "Size", 13 );
	   *  config.mapSetValue( "Name", "Humphrey" );
	   *
	   * mapSetValue( key, value ) is the same as mapMakeChild( key ).setValue( value ).
	   *
	   * This forces the referenced Node to have type Map. */
	  void mapSetValue( const QString& key, QVariant value );

	  /** @brief Create a child node stored with the given @a key, and return the child.
	   *
	   * This forces the referenced Node to have type Map. */
	  Config mapMakeChild( const QString& key );

	  /** @brief If the referenced Node is a Map and it has a child with
	   * the given key, return a reference to the child.  If the reference
	   * is invalid or the Node has a different Type, return an invalid
	   * Config. */
	  Config mapGetChild( const QString& key ) const;

	  /** @brief Convenience function for looking up a named value.
	   *
	   * If a Value Node with the given @key is a child of this Node, set
	   * value_out to the given value and return true.
	   *
	   * If the Config is invalid or the Node is not a Map, returns an
	   * Invalid Config. */
	  bool mapGetValue( const QString& key, QVariant *value_out ) const;

	  /** @brief Convenience function for looking up a named integer.
	   *
	   * If a Value Node with the given @key is a child of this Node, and
	   * the Value is either an int or a string-ified int, set value_out
	   * to the integer and return true.
	   *
	   * If the Config is invalid or the Node is not a Map, returns an
	   * Invalid Config. */
	  bool mapGetInt( const QString& key, int *value_out ) const;

	  /** @brief Convenience function for looking up a named float.
	   *
	   * If a Value Node with the given @key is a child of this Node, and
	   * the Value is either a float, a double or a string-ified float or
	   * double, set value_out to the float and return true.
	   *
	   * If the Config is invalid or the Node is not a Map, returns an
	   * Invalid Config. */
	  bool mapGetFloat( const QString& key, float *value_out ) const;

	  /** @brief Convenience function for looking up a named boolean.
	   *
	   * If a Value Node with the given @key is a child of this Node, and
	   * the Value is either a bool or a string-ified bool, set value_out
	   * to the bool and return true.
	   *
	   * If the Config is invalid or the Node is not a Map, returns an
	   * Invalid Config. */
	  bool mapGetBool( const QString& key, bool *value_out ) const;

	  /** @brief Convenience function for looking up a named string.
	   *
	   * If a Value Node with the given @key is a child of this Node, and
	   * the Value is a string, set value_out to the string and return
	   * true.
	   *
	   * If the Config is invalid or the Node is not a Map, returns an
	   * Invalid Config. */
	  bool mapGetString( const QString& key, QString *value_out ) const;

	  /** @brief Ensures this is a valid Config object, sets the type to
	   * Value then sets the value. */
	  void setValue( const QVariant& value );

	  /** @brief If this config object is valid and is a Value type, this returns its value.
	   * Otherwise it returns an invalid QVariant. */
	  QVariant getValue() const;

	  /** @brief Returns the length of the List in this Node, or 0 if this
	   * Node does not have type List. */
	  int listLength() const;

	  /** @brief Return the @a i'th child in the list, if the referenced
	   * Node has type List.  Returns an Invalid Config if the type is not
	   * List or if @a i is not a valid index into it. */
	  Config listChildAt( int i ) const;

	  /** @brief Ensure the referenced Node is of type List, append a new
	   * Empty Node to the end of the list, and return a reference to the
	   * new Node. */
	  Config listAppendNew();

	  /** @brief Iterator class for looping over all entries in a Map type Config Node.
	   *
	   * Typical usage:
	   *
	   * Config config;
	   * display->save( config ); // Write display's data into config.
	   * for( Config::MapIterator iter = config.mapIterator(); iter.isValid(); iter.advance() )
	   * {
	   *   QString key = iter.currentKey();
	   *   Config child = iter.currentChild();
	   *   printf( "key %s has value %s.\n", qPrintable( key ), qPrintable( child.getValue().toString() ));
	   * }
	   *
	   * Maps are stored in alphabetical order of their keys, and
	   * MapIterator uses this same order. */
	  class MapIterator
	  {
	  public:
		/** @brief Advance iterator to next entry. */
		void advance();

		/** @brief Return true if the iterator currently points to a valid entry, false if not.
		 *
		 * This is how you tell if your loop over entries is at the end. */
		bool isValid();

		/** @brief Resets the iterator to the start of the map. */
		void start();

		/** @brief Return the name of the current map entry. */
		QString currentKey();

		/** @brief Return a Config reference to the current map entry. */
		Config currentChild();

	  private:
		/** @brief Private constructor enforces that MapIterators are only
		 * made by their friend the Config class. */
		MapIterator();

		Config::NodePtr node_;
		QMap<QString, Config::NodePtr>::const_iterator iterator_;
		bool iterator_valid_;
		friend class Config;
	  };

	  /** @brief Return a new iterator for looping over key/value pairs.
	   *
	   * The returned MapIterator is initialized to point at the start of the map.
	   *
	   * If this Config is Invalid or if its Node is not a Map, this
	   * returns a MapIterator for which isValid() always returns
	   * false. */
	  MapIterator mapIterator() const;

	private:
	  Config( NodePtr node );
	  static Config invalidConfig();

	  /** @brief If the node pointer is NULL, this sets it to a new empty node. */
	  void makeValid();

	  NodePtr node_;

	  friend class MapIterator;
	};

} // end namespace general_demo

#endif // GENERAL_DEMO_CONFIG_H
