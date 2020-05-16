/****************************************************************************
** Meta object code from reading C++ file 'QXmppClient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../client/QXmppClient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QXmppClient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QXmppClient_t {
    QByteArrayData data[54];
    char stringdata0[679];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QXmppClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QXmppClient_t qt_meta_stringdata_QXmppClient = {
    {
QT_MOC_LITERAL(0, 0, 11), // "QXmppClient"
QT_MOC_LITERAL(1, 12, 9), // "connected"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 12), // "disconnected"
QT_MOC_LITERAL(4, 36, 5), // "error"
QT_MOC_LITERAL(5, 42, 18), // "QXmppClient::Error"
QT_MOC_LITERAL(6, 61, 13), // "loggerChanged"
QT_MOC_LITERAL(7, 75, 12), // "QXmppLogger*"
QT_MOC_LITERAL(8, 88, 6), // "logger"
QT_MOC_LITERAL(9, 95, 15), // "messageReceived"
QT_MOC_LITERAL(10, 111, 12), // "QXmppMessage"
QT_MOC_LITERAL(11, 124, 7), // "message"
QT_MOC_LITERAL(12, 132, 16), // "presenceReceived"
QT_MOC_LITERAL(13, 149, 13), // "QXmppPresence"
QT_MOC_LITERAL(14, 163, 8), // "presence"
QT_MOC_LITERAL(15, 172, 10), // "iqReceived"
QT_MOC_LITERAL(16, 183, 7), // "QXmppIq"
QT_MOC_LITERAL(17, 191, 2), // "iq"
QT_MOC_LITERAL(18, 194, 9), // "sslErrors"
QT_MOC_LITERAL(19, 204, 16), // "QList<QSslError>"
QT_MOC_LITERAL(20, 221, 6), // "errors"
QT_MOC_LITERAL(21, 228, 12), // "stateChanged"
QT_MOC_LITERAL(22, 241, 18), // "QXmppClient::State"
QT_MOC_LITERAL(23, 260, 5), // "state"
QT_MOC_LITERAL(24, 266, 15), // "connectToServer"
QT_MOC_LITERAL(25, 282, 18), // "QXmppConfiguration"
QT_MOC_LITERAL(26, 301, 15), // "initialPresence"
QT_MOC_LITERAL(27, 317, 3), // "jid"
QT_MOC_LITERAL(28, 321, 8), // "password"
QT_MOC_LITERAL(29, 330, 20), // "disconnectFromServer"
QT_MOC_LITERAL(30, 351, 10), // "sendPacket"
QT_MOC_LITERAL(31, 362, 11), // "QXmppStanza"
QT_MOC_LITERAL(32, 374, 11), // "sendMessage"
QT_MOC_LITERAL(33, 386, 7), // "bareJid"
QT_MOC_LITERAL(34, 394, 18), // "_q_elementReceived"
QT_MOC_LITERAL(35, 413, 11), // "QDomElement"
QT_MOC_LITERAL(36, 425, 7), // "element"
QT_MOC_LITERAL(37, 433, 5), // "bool&"
QT_MOC_LITERAL(38, 439, 7), // "handled"
QT_MOC_LITERAL(39, 447, 12), // "_q_reconnect"
QT_MOC_LITERAL(40, 460, 21), // "_q_socketStateChanged"
QT_MOC_LITERAL(41, 482, 28), // "QAbstractSocket::SocketState"
QT_MOC_LITERAL(42, 511, 18), // "_q_streamConnected"
QT_MOC_LITERAL(43, 530, 21), // "_q_streamDisconnected"
QT_MOC_LITERAL(44, 552, 14), // "_q_streamError"
QT_MOC_LITERAL(45, 567, 5), // "State"
QT_MOC_LITERAL(46, 573, 5), // "Error"
QT_MOC_LITERAL(47, 579, 7), // "NoError"
QT_MOC_LITERAL(48, 587, 11), // "SocketError"
QT_MOC_LITERAL(49, 599, 14), // "KeepAliveError"
QT_MOC_LITERAL(50, 614, 15), // "XmppStreamError"
QT_MOC_LITERAL(51, 630, 17), // "DisconnectedState"
QT_MOC_LITERAL(52, 648, 15), // "ConnectingState"
QT_MOC_LITERAL(53, 664, 14) // "ConnectedState"

    },
    "QXmppClient\0connected\0\0disconnected\0"
    "error\0QXmppClient::Error\0loggerChanged\0"
    "QXmppLogger*\0logger\0messageReceived\0"
    "QXmppMessage\0message\0presenceReceived\0"
    "QXmppPresence\0presence\0iqReceived\0"
    "QXmppIq\0iq\0sslErrors\0QList<QSslError>\0"
    "errors\0stateChanged\0QXmppClient::State\0"
    "state\0connectToServer\0QXmppConfiguration\0"
    "initialPresence\0jid\0password\0"
    "disconnectFromServer\0sendPacket\0"
    "QXmppStanza\0sendMessage\0bareJid\0"
    "_q_elementReceived\0QDomElement\0element\0"
    "bool&\0handled\0_q_reconnect\0"
    "_q_socketStateChanged\0"
    "QAbstractSocket::SocketState\0"
    "_q_streamConnected\0_q_streamDisconnected\0"
    "_q_streamError\0State\0Error\0NoError\0"
    "SocketError\0KeepAliveError\0XmppStreamError\0"
    "DisconnectedState\0ConnectingState\0"
    "ConnectedState"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QXmppClient[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       2,  178, // properties
       2,  186, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  119,    2, 0x06 /* Public */,
       3,    0,  120,    2, 0x06 /* Public */,
       4,    1,  121,    2, 0x06 /* Public */,
       6,    1,  124,    2, 0x06 /* Public */,
       9,    1,  127,    2, 0x06 /* Public */,
      12,    1,  130,    2, 0x06 /* Public */,
      15,    1,  133,    2, 0x06 /* Public */,
      18,    1,  136,    2, 0x06 /* Public */,
      21,    1,  139,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      24,    2,  142,    2, 0x0a /* Public */,
      24,    1,  147,    2, 0x2a /* Public | MethodCloned */,
      24,    2,  150,    2, 0x0a /* Public */,
      29,    0,  155,    2, 0x0a /* Public */,
      30,    1,  156,    2, 0x0a /* Public */,
      32,    2,  159,    2, 0x0a /* Public */,
      34,    2,  164,    2, 0x08 /* Private */,
      39,    0,  169,    2, 0x08 /* Private */,
      40,    1,  170,    2, 0x08 /* Private */,
      42,    0,  173,    2, 0x08 /* Private */,
      43,    0,  174,    2, 0x08 /* Private */,
      44,    1,  175,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void, 0x80000000 | 22,   23,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 25, 0x80000000 | 13,    2,   26,
    QMetaType::Void, 0x80000000 | 25,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   27,   28,
    QMetaType::Void,
    QMetaType::Bool, 0x80000000 | 31,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   33,   11,
    QMetaType::Void, 0x80000000 | 35, 0x80000000 | 37,   36,   38,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 41,   23,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    4,

 // properties: name, type, flags
       8, 0x80000000 | 7, 0x0049510b,
      23, 0x80000000 | 45, 0x00495009,

 // properties: notify_signal_id
       3,
       8,

 // enums: name, flags, count, data
      46, 0x0,    4,  194,
      45, 0x0,    3,  202,

 // enum data: key, value
      47, uint(QXmppClient::NoError),
      48, uint(QXmppClient::SocketError),
      49, uint(QXmppClient::KeepAliveError),
      50, uint(QXmppClient::XmppStreamError),
      51, uint(QXmppClient::DisconnectedState),
      52, uint(QXmppClient::ConnectingState),
      53, uint(QXmppClient::ConnectedState),

       0        // eod
};

void QXmppClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QXmppClient *_t = static_cast<QXmppClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connected(); break;
        case 1: _t->disconnected(); break;
        case 2: _t->error((*reinterpret_cast< QXmppClient::Error(*)>(_a[1]))); break;
        case 3: _t->loggerChanged((*reinterpret_cast< QXmppLogger*(*)>(_a[1]))); break;
        case 4: _t->messageReceived((*reinterpret_cast< const QXmppMessage(*)>(_a[1]))); break;
        case 5: _t->presenceReceived((*reinterpret_cast< const QXmppPresence(*)>(_a[1]))); break;
        case 6: _t->iqReceived((*reinterpret_cast< const QXmppIq(*)>(_a[1]))); break;
        case 7: _t->sslErrors((*reinterpret_cast< const QList<QSslError>(*)>(_a[1]))); break;
        case 8: _t->stateChanged((*reinterpret_cast< QXmppClient::State(*)>(_a[1]))); break;
        case 9: _t->connectToServer((*reinterpret_cast< const QXmppConfiguration(*)>(_a[1])),(*reinterpret_cast< const QXmppPresence(*)>(_a[2]))); break;
        case 10: _t->connectToServer((*reinterpret_cast< const QXmppConfiguration(*)>(_a[1]))); break;
        case 11: _t->connectToServer((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 12: _t->disconnectFromServer(); break;
        case 13: { bool _r = _t->sendPacket((*reinterpret_cast< const QXmppStanza(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 14: _t->sendMessage((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 15: _t->_q_elementReceived((*reinterpret_cast< const QDomElement(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 16: _t->_q_reconnect(); break;
        case 17: _t->_q_socketStateChanged((*reinterpret_cast< QAbstractSocket::SocketState(*)>(_a[1]))); break;
        case 18: _t->_q_streamConnected(); break;
        case 19: _t->_q_streamDisconnected(); break;
        case 20: _t->_q_streamError((*reinterpret_cast< QXmppClient::Error(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QXmppLogger* >(); break;
            }
            break;
        case 17:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketState >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (QXmppClient::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppClient::connected)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QXmppClient::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppClient::disconnected)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (QXmppClient::*_t)(QXmppClient::Error );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppClient::error)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (QXmppClient::*_t)(QXmppLogger * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppClient::loggerChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (QXmppClient::*_t)(const QXmppMessage & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppClient::messageReceived)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (QXmppClient::*_t)(const QXmppPresence & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppClient::presenceReceived)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (QXmppClient::*_t)(const QXmppIq & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppClient::iqReceived)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (QXmppClient::*_t)(const QList<QSslError> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppClient::sslErrors)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (QXmppClient::*_t)(QXmppClient::State );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppClient::stateChanged)) {
                *result = 8;
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
        QXmppClient *_t = static_cast<QXmppClient *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QXmppLogger**>(_v) = _t->logger(); break;
        case 1: *reinterpret_cast< State*>(_v) = _t->state(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        QXmppClient *_t = static_cast<QXmppClient *>(_o);
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

const QMetaObject QXmppClient::staticMetaObject = {
    { &QXmppLoggable::staticMetaObject, qt_meta_stringdata_QXmppClient.data,
      qt_meta_data_QXmppClient,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QXmppClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QXmppClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QXmppClient.stringdata0))
        return static_cast<void*>(this);
    return QXmppLoggable::qt_metacast(_clname);
}

int QXmppClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QXmppLoggable::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QXmppClient::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QXmppClient::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QXmppClient::error(QXmppClient::Error _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QXmppClient::loggerChanged(QXmppLogger * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QXmppClient::messageReceived(const QXmppMessage & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void QXmppClient::presenceReceived(const QXmppPresence & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void QXmppClient::iqReceived(const QXmppIq & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void QXmppClient::sslErrors(const QList<QSslError> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void QXmppClient::stateChanged(QXmppClient::State _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
