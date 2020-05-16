#ifndef GENERAL_DEMO_PANEL_H
#define GENERAL_DEMO_PANEL_H

#include <QWidget>

#include "config.h"

namespace general_demo
{

class Panel: public QWidget
{
Q_OBJECT
public:
  Panel( QWidget* parent = 0);
  virtual ~Panel();

  virtual QString getName() const { return name_; }
  virtual void setName( const QString& name ) { name_ = name; }

  /** @brief Return a description of this Panel. */
  virtual QString getDescription() const { return description_; }

  /** @brief Set a description of this Panel.  Called by the factory which creates it. */
  virtual void setDescription( const QString& description ) { description_ = description; }

  /** @brief Return the class identifier which was used to create this
   * instance.  This version just returns whatever was set with
   * setClassId(). */
  virtual QString getClassId() const { return class_id_; }

  /** @brief Set the class identifier used to create this instance.
   * Typically this will be set by the factory object which created it. */
  virtual void setClassId( const QString& class_id ) { class_id_ = class_id; }

  /** @brief Override to load configuration data.  This version loads the name of the panel. */
   virtual void load( const Config& config );

   /** @brief Override to save configuration data.  This version saves the name and class ID of the panel. */
   virtual void save( Config config ) const;

Q_SIGNALS:
  /** @brief Subclasses must emit this whenever a configuration change
   *         happens.
   *
   * This is used to let the system know that changes have been made
   * since the last time the config was saved. */
  void configChanged();

private:
  QString class_id_;
  QString name_;
  QString description_;
};

} // end namespace general_demo

#endif // GENERAL_DEMO_PANEL_H
