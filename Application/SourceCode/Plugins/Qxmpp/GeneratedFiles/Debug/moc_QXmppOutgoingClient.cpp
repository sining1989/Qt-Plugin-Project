/****************************************************************************
** Meta object code from reading C++ file 'QXmppOutgoingClient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../client/QXmppOutgoingClient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QXmppOutgoingClient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QXmppOutgoingClient_t {
    QByteArrayData data[28];
    char stringdata0[368];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QXmppOutgoingClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QXmppOutgoingClient_t qt_meta_stringdata_QXmppOutgoingClient = {
    {
QT_MOC_LITERAL(0, 0, 19), // "QXmppOutgoingClient"
QT_MOC_LITERAL(1, 20, 5), // "error"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 18), // "QXmppClient::Error"
QT_MOC_LITERAL(4, 46, 15), // "elementReceived"
QT_MOC_LITERAL(5, 62, 11), // "QDomElement"
QT_MOC_LITERAL(6, 74, 7), // "element"
QT_MOC_LITERAL(7, 82, 5), // "bool&"
QT_MOC_LITERAL(8, 88, 7), // "handled"
QT_MOC_LITERAL(9, 96, 16), // "presenceReceived"
QT_MOC_LITERAL(10, 113, 13), // "QXmppPresence"
QT_MOC_LITERAL(11, 127, 15), // "messageReceived"
QT_MOC_LITERAL(12, 143, 12), // "QXmppMessage"
QT_MOC_LITERAL(13, 156, 10), // "iqReceived"
QT_MOC_LITERAL(14, 167, 7), // "QXmppIq"
QT_MOC_LITERAL(15, 175, 9), // "sslErrors"
QT_MOC_LITERAL(16, 185, 16), // "QList<QSslError>"
QT_MOC_LITERAL(17, 202, 6), // "errors"
QT_MOC_LITERAL(18, 209, 18), // "disconnectFromHost"
QT_MOC_LITERAL(19, 228, 20), // "_q_dnsLookupFinished"
QT_MOC_LITERAL(20, 249, 21), // "_q_socketDisconnected"
QT_MOC_LITERAL(21, 271, 11), // "socketError"
QT_MOC_LITERAL(22, 283, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(23, 312, 15), // "socketSslErrors"
QT_MOC_LITERAL(24, 328, 9), // "pingStart"
QT_MOC_LITERAL(25, 338, 8), // "pingStop"
QT_MOC_LITERAL(26, 347, 8), // "pingSend"
QT_MOC_LITERAL(27, 356, 11) // "pingTimeout"

    },
    "QXmppOutgoingClient\0error\0\0"
    "QXmppClient::Error\0elementReceived\0"
    "QDomElement\0element\0bool&\0handled\0"
    "presenceReceived\0QXmppPresence\0"
    "messageReceived\0QXmppMessage\0iqReceived\0"
    "QXmppIq\0sslErrors\0QList<QSslError>\0"
    "errors\0disconnectFromHost\0"
    "_q_dnsLookupFinished\0_q_socketDisconnected\0"
    "socketError\0QAbstractSocket::SocketError\0"
    "socketSslErrors\0pingStart\0pingStop\0"
    "pingSend\0pingTimeout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QXmppOutgoingClient[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,
       4,    2,   92,    2, 0x06 /* Public */,
       9,    1,   97,    2, 0x06 /* Public */,
      11,    1,  100,    2, 0x06 /* Public */,
      13,    1,  103,    2, 0x06 /* Public */,
      15,    1,  106,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      18,    0,  109,    2, 0x0a /* Public */,
      19,    0,  110,    2, 0x08 /* Private */,
      20,    0,  111,    2, 0x08 /* Private */,
      21,    1,  112,    2, 0x08 /* Private */,
      23,    1,  115,    2, 0x08 /* Private */,
      24,    0,  118,    2, 0x08 /* Private */,
      25,    0,  119,    2, 0x08 /* Private */,
      26,    0,  120,    2, 0x08 /* Private */,
      27,    0,  121,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 7,    6,    8,
    QMetaType::Void, 0x80000000 | 10,    2,
    QMetaType::Void, 0x80000000 | 12,    2,
    QMetaType::Void, 0x80000000 | 14,    2,
    QMetaType::Void, 0x80000000 | 16,   17,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 22,    2,
    QMetaType::Void, 0x80000000 | 16,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QXmppOutgoingClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QXmppOutgoingClient *_t = static_cast<QXmppOutgoingClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->error((*reinterpret_cast< QXmppClient::Error(*)>(_a[1]))); break;
        case 1: _t->elementReceived((*reinterpret_cast< const QDomElement(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: _t->presenceReceived((*reinterpret_cast< const QXmppPresence(*)>(_a[1]))); break;
        case 3: _t->messageReceived((*reinterpret_cast< const QXmppMessage(*)>(_a[1]))); break;
        case 4: _t->iqReceived((*reinterpret_cast< const QXmppIq(*)>(_a[1]))); break;
        case 5: _t->sslErrors((*reinterpret_cast< const QList<QSslError>(*)>(_a[1]))); break;
        case 6: _t->disconnectFromHost(); break;
        case 7: _t->_q_dnsLookupFinished(); break;
        case 8: _t->_q_socketDisconnected(); break;
        case 9: _t->socketError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 10: _t->socketSslErrors((*reinterpret_cast< const QList<QSslError>(*)>(_a[1]))); break;
        case 11: _t->pingStart(); break;
        case 12: _t->pingStop(); break;
        case 13: _t->pingSend(); break;
        case 14: _t->pingTimeout(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (QXmppOutgoingClient::*_t)(QXmppClient::Error );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppOutgoingClient::error)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QXmppOutgoingClient::*_t)(const QDomElement & , bool & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppOutgoingClient::elementReceived)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (QXmppOutgoingClient::*_t)(const QXmppPresence & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppOutgoingClient::presenceReceived)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (QXmppOutgoingClient::*_t)(const QXmppMessage & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppOutgoingClient::messageReceived)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (QXmppOutgoingClient::*_t)(const QXmppIq & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppOutgoingClient::iqReceived)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (QXmppOutgoingClient::*_t)(const QList<QSslError> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppOutgoingClient::sslErrors)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject QXmppOutgoingClient::staticMetaObject = {
    { &QXmppStream::staticMetaObject, qt_meta_stringdata_QXmppOutgoingClient.data,
      qt_meta_data_QXmppOutgoingClient,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QXmppOutgoingClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QXmppOutgoingClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QXmppOutgoingClient.stringdata0))
        return static_cast<void*>(this);
    return QXmppStream::qt_metacast(_clname);
}

int QXmppOutgoingClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QXmppStream::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void QXmppOutgoingClient::error(QXmppClient::Error _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QXmppOutgoingClient::elementReceived(const QDomElement & _t1, bool & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QXmppOutgoingClient::presenceReceived(const QXmppPresence & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QXmppOutgoingClient::messageReceived(const QXmppMessage & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QXmppOutgoingClient::iqReceived(const QXmppIq & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void QXmppOutgoingClient::sslErrors(const QList<QSslError> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
