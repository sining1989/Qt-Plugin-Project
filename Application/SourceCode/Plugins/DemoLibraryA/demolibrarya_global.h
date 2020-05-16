#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(DEMOLIBRARYA_LIB)
#  define DEMOLIBRARYA_EXPORT Q_DECL_EXPORT
# else
#  define DEMOLIBRARYA_EXPORT Q_DECL_IMPORT
# endif
#else
# define DEMOLIBRARYA_EXPORT
#endif
