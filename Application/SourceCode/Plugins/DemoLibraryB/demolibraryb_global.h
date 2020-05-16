#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(DEMOLIBRARYB_LIB)
#  define DEMOLIBRARYB_EXPORT Q_DECL_EXPORT
# else
#  define DEMOLIBRARYB_EXPORT Q_DECL_IMPORT
# endif
#else
# define DEMOLIBRARYB_EXPORT
#endif
