#ifndef GENERAL_DEMO_SCREENSHOT_DIALOG_H
#define GENERAL_DEMO_SCREENSHOT_DIALOG_H

#include <QWidget>

class QPixmap;
class QAbstractButton;
class QDialogButtonBox;
class QTimer;
class QCheckBox;

namespace general_demo
{

	class ScaledImageWidget;

	/**
	 * \brief A dialog for grabbing a screen shot.
	 *
	 * Takes the screenshot while in the constructor, then shows a
	 * half-size view of the screenshot in the dialog with buttons for
	 * save/try-again/cancel.
	 */
	class ScreenshotDialog: public QWidget
	{
	Q_OBJECT
	public:
		ScreenshotDialog( QWidget* main_window, QWidget* render_window, const QString& default_save_dir = QString() );
		virtual ~ScreenshotDialog() {}

	Q_SIGNALS:
		/** @brief Emitted when the user saves a file. */
		void savedInDirectory( const QString& directory );

	protected Q_SLOTS:
		void takeScreenshot();
		void onTimeout();
		void takeScreenshotNow();
		void save();
		void onButtonClicked( QAbstractButton* clicked );
		void setSaveFullWindow( bool save_full_window );

	protected:
		virtual void showEvent( QShowEvent* event );

	private:
		ScaledImageWidget* image_widget_;
		QWidget* main_window_;
		QWidget* render_window_;
		QPixmap screenshot_;
		QDialogButtonBox* button_box_;
		bool save_full_window_;
		QTimer* delay_timer_;
		QSize saved_size_;
		bool first_time_;
		QString default_save_dir_;
	};

} // namespace general_demo

#endif // GENERAL_DEMO_SCREENSHOT_DIALOG_H
