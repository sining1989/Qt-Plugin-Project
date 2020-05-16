/****************************************************************************
** Meta object code from reading C++ file 'QXmppServer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../server/QXmppServer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QXmppServer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QXmppServer_t {
    QByteArrayData data[22];
    char stringdata0[322];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QXmppServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QXmppServer_t qt_meta_stringdata_QXmppServer = {
    {
QT_MOC_LITERAL(0, 0, 11), // "QXmppServer"
QT_MOC_LITERAL(1, 12, 15), // "clientConnected"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 3), // "jid"
QT_MOC_LITERAL(4, 33, 18), // "clientDisconnected"
QT_MOC_LITERAL(5, 52, 13), // "loggerChanged"
QT_MOC_LITERAL(6, 66, 12), // "QXmppLogger*"
QT_MOC_LITERAL(7, 79, 6), // "logger"
QT_MOC_LITERAL(8, 86, 13), // "handleElement"
QT_MOC_LITERAL(9, 100, 11), // "QDomElement"
QT_MOC_LITERAL(10, 112, 7), // "element"
QT_MOC_LITERAL(11, 120, 19), // "_q_clientConnection"
QT_MOC_LITERAL(12, 140, 11), // "QSslSocket*"
QT_MOC_LITERAL(13, 152, 6), // "socket"
QT_MOC_LITERAL(14, 159, 18), // "_q_clientConnected"
QT_MOC_LITERAL(15, 178, 21), // "_q_clientDisconnected"
QT_MOC_LITERAL(16, 200, 26), // "_q_dialbackRequestReceived"
QT_MOC_LITERAL(17, 227, 13), // "QXmppDialback"
QT_MOC_LITERAL(18, 241, 8), // "dialback"
QT_MOC_LITERAL(19, 250, 29), // "_q_outgoingServerDisconnected"
QT_MOC_LITERAL(20, 280, 19), // "_q_serverConnection"
QT_MOC_LITERAL(21, 300, 21) // "_q_serverDisconnected"

    },
    "QXmppServer\0clientConnected\0\0jid\0"
    "clientDisconnected\0loggerChanged\0"
    "QXmppLogger*\0logger\0handleElement\0"
    "QDomElement\0element\0_q_clientConnection\0"
    "QSslSocket*\0socket\0_q_clientConnected\0"
    "_q_clientDisconnected\0_q_dialbackRequestReceived\0"
    "QXmppDialback\0dialback\0"
    "_q_outgoingServerDisconnected\0"
    "_q_serverConnection\0_q_serverDisconnected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QXmppServer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       1,   94, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       4,    1,   72,    2, 0x06 /* Public */,
       5,    1,   75,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   78,    2, 0x0a /* Public */,
      11,    1,   81,    2, 0x08 /* Private */,
      14,    0,   84,    2, 0x08 /* Private */,
      15,    0,   85,    2, 0x08 /* Private */,
      16,    1,   86,    2, 0x08 /* Private */,
      19,    0,   89,    2, 0x08 /* Private */,
      20,    1,   90,    2, 0x08 /* Private */,
      21,    0,   93,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 6,    7,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,

 // properties: name, type, flags
       7, 0x80000000 | 6, 0x0049510b,

 // properties: notify_signal_id
       2,

       0        // eod
};

void QXmppServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QXmppServer *_t = static_cast<QXmppServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clientConnected((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->clientDisconnected((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->loggerChanged((*reinterpret_cast< QXmppLogger*(*)>(_a[1]))); break;
        case 3: _t->handleElement((*reinterpret_cast< const QDomElement(*)>(_a[1]))); break;
        case 4: _t->_q_clientConnection((*reinterpret_cast< QSslSocket*(*)>(_a[1]))); break;
        case 5: _t->_q_clientConnected(); break;
        case 6: _t->_q_clientDisconnected(); break;
        case 7: _t->_q_dialbackRequestReceived((*reinterpret_cast< const QXmppDialback(*)>(_a[1]))); break;
        case 8: _t->_q_outgoingServerDisconnected(); break;
        case 9: _t->_q_serverConnection((*reinterpret_cast< QSslSocket*(*)>(_a[1]))); break;
        case 10: _t->_q_serverDisconnected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QXmppLogger* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (QXmppServer::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppServer::clientConnected)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QXmppServer::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppServer::clientDisconnected)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (QXmppServer::*_t)(QXmppLogger * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppServer::loggerChanged)) {
                *result = 2;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QXmppLogger* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        QXmppServer *_t = static_cast<QXmppServer *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QXmppLogger**>(_v) = _t->logger(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        QXmppServer *_t = static_cast<QXmppServer *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setLogger(*reinterpret_cast< QXmppLogger**>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject QXmppServer::staticMetaObject = {
    { &QXmppLoggable::staticMetaObject, qt_meta_stringdata_QXmppServer.data,
      qt_meta_data_QXmppServer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QXmppServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QXmppServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QXmppServer.stringdata0))
        return static_cast<void*>(this);
    return QXmppLoggable::qt_metacast(_clname);
}

int QXmppServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QXmppLoggable::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QXmppServer::clientConnected(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QXmppServer::clientDisconnected(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QXmppServer::loggerChanged(QXmppLogger * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
struct qt_meta_stringdata_QXmppSslServer_t {
    QByteArrayData data[5];
    char stringdata0[49];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QXmppSslServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QXmppSslServer_t qt_meta_stringdata_QXmppSslServer = {
    {
QT_MOC_LITERAL(0, 0, 14), // "QXmppSslServer"
QT_MOC_LITERAL(1, 15, 13), // "newConnection"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 11), // "QSslSocket*"
QT_MOC_LITERAL(4, 42, 6) // "socket"

    },
    "QXmppSslServer\0newConnection\0\0QSslSocket*\0"
    "socket"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QXmppSslServer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void QXmppSslServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QXmppSslServer *_t = static_cast<QXmppSslServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newConnection((*reinterpret_cast< QSslSocket*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (QXmppSslServer::*_t)(QSslSocket * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppSslServer::newConnection)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject QXmppSslServer::staticMetaObject = {
    { &QTcpServer::staticMetaObject, qt_meta_stringdata_QXmppSslServer.data,
      qt_meta_data_QXmppSslServer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QXmppSslServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QXmppSslServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QXmppSslServer.stringdata0))
        return static_cast<void*>(this);
    return QTcpServer::qt_metacast(_clname);
}

int QXmppSslServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void QXmppSslServer::newConnection(QSslSocket * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
