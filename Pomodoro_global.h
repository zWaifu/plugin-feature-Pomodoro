#ifndef POMODORO_GLOBAL_H
#define POMODORO_GLOBAL_H

#include <QtCore/qglobal.h>
#include "QTypesFormatter.h"

#if defined(POMODORO_LIBRARY)
#  define POMODORO_EXPORT Q_DECL_EXPORT
#else
#  define POMODORO_EXPORT Q_DECL_IMPORT
#endif

#endif // POMODORO_GLOBAL_H
