/****************************************************************************
** Meta object code from reading C++ file 'QXmppLogger.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../base/QXmppLogger.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QXmppLogger.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QXmppLogger_t {
    QByteArrayData data[31];
    char stringdata0[337];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QXmppLogger_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QXmppLogger_t qt_meta_stringdata_QXmppLogger = {
    {
QT_MOC_LITERAL(0, 0, 11), // "QXmppLogger"
QT_MOC_LITERAL(1, 12, 7), // "message"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 24), // "QXmppLogger::MessageType"
QT_MOC_LITERAL(4, 46, 4), // "type"
QT_MOC_LITERAL(5, 51, 4), // "text"
QT_MOC_LITERAL(6, 56, 8), // "setGauge"
QT_MOC_LITERAL(7, 65, 5), // "gauge"
QT_MOC_LITERAL(8, 71, 5), // "value"
QT_MOC_LITERAL(9, 77, 13), // "updateCounter"
QT_MOC_LITERAL(10, 91, 7), // "counter"
QT_MOC_LITERAL(11, 99, 6), // "amount"
QT_MOC_LITERAL(12, 106, 3), // "log"
QT_MOC_LITERAL(13, 110, 6), // "reopen"
QT_MOC_LITERAL(14, 117, 11), // "logFilePath"
QT_MOC_LITERAL(15, 129, 11), // "loggingType"
QT_MOC_LITERAL(16, 141, 11), // "LoggingType"
QT_MOC_LITERAL(17, 153, 12), // "messageTypes"
QT_MOC_LITERAL(18, 166, 12), // "MessageTypes"
QT_MOC_LITERAL(19, 179, 9), // "NoLogging"
QT_MOC_LITERAL(20, 189, 11), // "FileLogging"
QT_MOC_LITERAL(21, 201, 13), // "StdoutLogging"
QT_MOC_LITERAL(22, 215, 13), // "SignalLogging"
QT_MOC_LITERAL(23, 229, 11), // "MessageType"
QT_MOC_LITERAL(24, 241, 9), // "NoMessage"
QT_MOC_LITERAL(25, 251, 12), // "DebugMessage"
QT_MOC_LITERAL(26, 264, 18), // "InformationMessage"
QT_MOC_LITERAL(27, 283, 14), // "WarningMessage"
QT_MOC_LITERAL(28, 298, 15), // "ReceivedMessage"
QT_MOC_LITERAL(29, 314, 11), // "SentMessage"
QT_MOC_LITERAL(30, 326, 10) // "AnyMessage"

    },
    "QXmppLogger\0message\0\0QXmppLogger::MessageType\0"
    "type\0text\0setGauge\0gauge\0value\0"
    "updateCounter\0counter\0amount\0log\0"
    "reopen\0logFilePath\0loggingType\0"
    "LoggingType\0messageTypes\0MessageTypes\0"
    "NoLogging\0FileLogging\0StdoutLogging\0"
    "SignalLogging\0MessageType\0NoMessage\0"
    "DebugMessage\0InformationMessage\0"
    "WarningMessage\0ReceivedMessage\0"
    "SentMessage\0AnyMessage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QXmppLogger[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       3,   60, // properties
       3,   69, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    2,   44,    2, 0x0a /* Public */,
       9,    2,   49,    2, 0x0a /* Public */,
      12,    2,   54,    2, 0x0a /* Public */,
      13,    0,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Double,    7,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::LongLong,   10,   11,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,    5,
    QMetaType::Void,

 // properties: name, type, flags
      14, QMetaType::QString, 0x00095103,
      15, 0x80000000 | 16, 0x0009510b,
      17, 0x80000000 | 18, 0x0009510b,

 // enums: name, flags, count, data
      16, 0x0,    4,   81,
      23, 0x1,    7,   89,
      18, 0x1,    7,  103,

 // enum data: key, value
      19, uint(QXmppLogger::NoLogging),
      20, uint(QXmppLogger::FileLogging),
      21, uint(QXmppLogger::StdoutLogging),
      22, uint(QXmppLogger::SignalLogging),
      24, uint(QXmppLogger::NoMessage),
      25, uint(QXmppLogger::DebugMessage),
      26, uint(QXmppLogger::InformationMessage),
      27, uint(QXmppLogger::WarningMessage),
      28, uint(QXmppLogger::ReceivedMessage),
      29, uint(QXmppLogger::SentMessage),
      30, uint(QXmppLogger::AnyMessage),
      24, uint(QXmppLogger::NoMessage),
      25, uint(QXmppLogger::DebugMessage),
      26, uint(QXmppLogger::InformationMessage),
      27, uint(QXmppLogger::WarningMessage),
      28, uint(QXmppLogger::ReceivedMessage),
      29, uint(QXmppLogger::SentMessage),
      30, uint(QXmppLogger::AnyMessage),

       0        // eod
};

void QXmppLogger::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QXmppLogger *_t = static_cast<QXmppLogger *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->message((*reinterpret_cast< QXmppLogger::MessageType(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->setGauge((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 2: _t->updateCounter((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 3: _t->log((*reinterpret_cast< QXmppLogger::MessageType(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 4: _t->reopen(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (QXmppLogger::*_t)(QXmppLogger::MessageType , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppLogger::message)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        QXmppLogger *_t = static_cast<QXmppLogger *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->logFilePath(); break;
        case 1: *reinterpret_cast< LoggingType*>(_v) = _t->loggingType(); break;
        case 2: *reinterpret_cast<int*>(_v) = QFlag(_t->messageTypes()); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        QXmppLogger *_t = static_cast<QXmppLogger *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setLogFilePath(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setLoggingType(*reinterpret_cast< LoggingType*>(_v)); break;
        case 2: _t->setMessageTypes(QFlag(*reinterpret_cast<int*>(_v))); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject QXmppLogger::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QXmppLogger.data,
      qt_meta_data_QXmppLogger,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QXmppLogger::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QXmppLogger::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QXmppLogger.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QXmppLogger::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QXmppLogger::message(QXmppLogger::MessageType _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_QXmppLoggable_t {
    QByteArrayData data[12];
    char stringdata0[110];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QXmppLoggable_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QXmppLoggable_t qt_meta_stringdata_QXmppLoggable = {
    {
QT_MOC_LITERAL(0, 0, 13), // "QXmppLoggable"
QT_MOC_LITERAL(1, 14, 8), // "setGauge"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 5), // "gauge"
QT_MOC_LITERAL(4, 30, 5), // "value"
QT_MOC_LITERAL(5, 36, 10), // "logMessage"
QT_MOC_LITERAL(6, 47, 24), // "QXmppLogger::MessageType"
QT_MOC_LITERAL(7, 72, 4), // "type"
QT_MOC_LITERAL(8, 77, 3), // "msg"
QT_MOC_LITERAL(9, 81, 13), // "updateCounter"
QT_MOC_LITERAL(10, 95, 7), // "counter"
QT_MOC_LITERAL(11, 103, 6) // "amount"

    },
    "QXmppLoggable\0setGauge\0\0gauge\0value\0"
    "logMessage\0QXmppLogger::MessageType\0"
    "type\0msg\0updateCounter\0counter\0amount"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QXmppLoggable[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,
       5,    2,   39,    2, 0x06 /* Public */,
       9,    2,   44,    2, 0x06 /* Public */,
       9,    1,   49,    2, 0x26 /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Double,    3,    4,
    QMetaType::Void, 0x80000000 | 6, QMetaType::QString,    7,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::LongLong,   10,   11,
    QMetaType::Void, QMetaType::QString,   10,

       0        // eod
};

void QXmppLoggable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QXmppLoggable *_t = static_cast<QXmppLoggable *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setGauge((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 1: _t->logMessage((*reinterpret_cast< QXmppLogger::MessageType(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->updateCounter((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 3: _t->updateCounter((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (QXmppLoggable::*_t)(const QString & , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppLoggable::setGauge)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QXmppLoggable::*_t)(QXmppLogger::MessageType , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppLoggable::logMessage)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (QXmppLoggable::*_t)(const QString & , qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppLoggable::updateCounter)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject QXmppLoggable::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QXmppLoggable.data,
      qt_meta_data_QXmppLoggable,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QXmppLoggable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QXmppLoggable::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QXmppLoggable.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QXmppLoggable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void QXmppLoggable::setGauge(const QString & _t1, double _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QXmppLoggable::logMessage(QXmppLogger::MessageType _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QXmppLoggable::updateCounter(const QString & _t1, qint64 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
