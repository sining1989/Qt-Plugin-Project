#ifndef GENERAL_DEMO_RESOURCE_RETRIEVING_H_
#define GENERAL_DEMO_RESOURCE_RETRIEVING_H_

#include <QPixmap>
#include <QCursor>
#include <QString>

namespace general_demo
{

	// Helper functions to load resources based on their resource url,

	/* @brief Try to load the pixmap url from disk or the cache.
	 *        In case of a failure, the result will be an empty QPixmap.
	 *        If fill_cache is set to true (default), the image will be
	 *        stored in the cache after loading it from disk.
	 */
	QPixmap loadPixmap( QString url, bool fill_cache=true );

	/* @brief Load the default cursor: an arrow.
	 *        The fill_cache parameter is ignored.
	 */
	QCursor getDefaultCursor( bool fill_cache=true );

	/* @brief Create a cursor using a shape in a file/url.
	 *        In case of a failure, the result will be the default arrow cursor.
	 *        If fill_cache is set to true (default), the image will be
	 *        stored in the cache after loading it from disk.
	 */
	QCursor makeIconCursor( QString icon_url, bool fill_cache=true );

	/* @brief Create a cursor using the shape in the icon QPixmap.
	 *        If fill_cache is set to true (default), the image will be
	 *        stored in the cache using \e cache_key.
	 */
	QCursor makeIconCursor( QPixmap icon, QString cache_key="", bool fill_cache=true );


} // namespace general_demo

#endif /* GENERAL_DEMO_RESOURCE_RETRIEVING_H_ */
