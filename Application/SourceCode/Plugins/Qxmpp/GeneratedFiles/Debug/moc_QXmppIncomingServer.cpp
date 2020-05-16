/****************************************************************************
** Meta object code from reading C++ file 'QXmppIncomingServer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../server/QXmppIncomingServer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QXmppIncomingServer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QXmppIncomingServer_t {
    QByteArrayData data[11];
    char stringdata0[163];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QXmppIncomingServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QXmppIncomingServer_t qt_meta_stringdata_QXmppIncomingServer = {
    {
QT_MOC_LITERAL(0, 0, 19), // "QXmppIncomingServer"
QT_MOC_LITERAL(1, 20, 23), // "dialbackRequestReceived"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 13), // "QXmppDialback"
QT_MOC_LITERAL(4, 59, 6), // "result"
QT_MOC_LITERAL(5, 66, 15), // "elementReceived"
QT_MOC_LITERAL(6, 82, 11), // "QDomElement"
QT_MOC_LITERAL(7, 94, 7), // "element"
QT_MOC_LITERAL(8, 102, 28), // "slotDialbackResponseReceived"
QT_MOC_LITERAL(9, 131, 8), // "dialback"
QT_MOC_LITERAL(10, 140, 22) // "slotSocketDisconnected"

    },
    "QXmppIncomingServer\0dialbackRequestReceived\0"
    "\0QXmppDialback\0result\0elementReceived\0"
    "QDomElement\0element\0slotDialbackResponseReceived\0"
    "dialback\0slotSocketDisconnected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QXmppIncomingServer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       5,    1,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   40,    2, 0x08 /* Private */,
      10,    0,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    9,
    QMetaType::Void,

       0        // eod
};

void QXmppIncomingServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QXmppIncomingServer *_t = static_cast<QXmppIncomingServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dialbackRequestReceived((*reinterpret_cast< const QXmppDialback(*)>(_a[1]))); break;
        case 1: _t->elementReceived((*reinterpret_cast< const QDomElement(*)>(_a[1]))); break;
        case 2: _t->slotDialbackResponseReceived((*reinterpret_cast< const QXmppDialback(*)>(_a[1]))); break;
        case 3: _t->slotSocketDisconnected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (QXmppIncomingServer::*_t)(const QXmppDialback & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppIncomingServer::dialbackRequestReceived)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QXmppIncomingServer::*_t)(const QDomElement & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppIncomingServer::elementReceived)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject QXmppIncomingServer::staticMetaObject = {
    { &QXmppStream::staticMetaObject, qt_meta_stringdata_QXmppIncomingServer.data,
      qt_meta_data_QXmppIncomingServer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QXmppIncomingServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QXmppIncomingServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QXmppIncomingServer.stringdata0))
        return static_cast<void*>(this);
    return QXmppStream::qt_metacast(_clname);
}

int QXmppIncomingServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QXmppStream::qt_metacall(_c, _id, _a);
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
void QXmppIncomingServer::dialbackRequestReceived(const QXmppDialback & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QXmppIncomingServer::elementReceived(const QDomElement & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
