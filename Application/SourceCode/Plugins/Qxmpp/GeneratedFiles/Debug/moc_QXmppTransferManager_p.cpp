/****************************************************************************
** Meta object code from reading C++ file 'QXmppTransferManager_p.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../client/QXmppTransferManager_p.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QXmppTransferManager_p.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QXmppTransferIncomingJob_t {
    QByteArrayData data[6];
    char stringdata0[100];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QXmppTransferIncomingJob_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QXmppTransferIncomingJob_t qt_meta_stringdata_QXmppTransferIncomingJob = {
    {
QT_MOC_LITERAL(0, 0, 24), // "QXmppTransferIncomingJob"
QT_MOC_LITERAL(1, 25, 24), // "_q_candidateDisconnected"
QT_MOC_LITERAL(2, 50, 0), // ""
QT_MOC_LITERAL(3, 51, 17), // "_q_candidateReady"
QT_MOC_LITERAL(4, 69, 15), // "_q_disconnected"
QT_MOC_LITERAL(5, 85, 14) // "_q_receiveData"

    },
    "QXmppTransferIncomingJob\0"
    "_q_candidateDisconnected\0\0_q_candidateReady\0"
    "_q_disconnected\0_q_receiveData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QXmppTransferIncomingJob[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    0,   36,    2, 0x08 /* Private */,
       5,    0,   37,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QXmppTransferIncomingJob::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QXmppTransferIncomingJob *_t = static_cast<QXmppTransferIncomingJob *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->_q_candidateDisconnected(); break;
        case 1: _t->_q_candidateReady(); break;
        case 2: _t->_q_disconnected(); break;
        case 3: _t->_q_receiveData(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject QXmppTransferIncomingJob::staticMetaObject = {
    { &QXmppTransferJob::staticMetaObject, qt_meta_stringdata_QXmppTransferIncomingJob.data,
      qt_meta_data_QXmppTransferIncomingJob,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QXmppTransferIncomingJob::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QXmppTransferIncomingJob::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QXmppTransferIncomingJob.stringdata0))
        return static_cast<void*>(this);
    return QXmppTransferJob::qt_metacast(_clname);
}

int QXmppTransferIncomingJob::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QXmppTransferJob::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_QXmppTransferOutgoingJob_t {
    QByteArrayData data[5];
    char stringdata0[68];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QXmppTransferOutgoingJob_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QXmppTransferOutgoingJob_t qt_meta_stringdata_QXmppTransferOutgoingJob = {
    {
QT_MOC_LITERAL(0, 0, 24), // "QXmppTransferOutgoingJob"
QT_MOC_LITERAL(1, 25, 15), // "_q_disconnected"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 13), // "_q_proxyReady"
QT_MOC_LITERAL(4, 56, 11) // "_q_sendData"

    },
    "QXmppTransferOutgoingJob\0_q_disconnected\0"
    "\0_q_proxyReady\0_q_sendData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QXmppTransferOutgoingJob[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x08 /* Private */,
       3,    0,   30,    2, 0x08 /* Private */,
       4,    0,   31,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QXmppTransferOutgoingJob::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QXmppTransferOutgoingJob *_t = static_cast<QXmppTransferOutgoingJob *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->_q_disconnected(); break;
        case 1: _t->_q_proxyReady(); break;
        case 2: _t->_q_sendData(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject QXmppTransferOutgoingJob::staticMetaObject = {
    { &QXmppTransferJob::staticMetaObject, qt_meta_stringdata_QXmppTransferOutgoingJob.data,
      qt_meta_data_QXmppTransferOutgoingJob,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QXmppTransferOutgoingJob::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QXmppTransferOutgoingJob::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QXmppTransferOutgoingJob.stringdata0))
        return static_cast<void*>(this);
    return QXmppTransferJob::qt_metacast(_clname);
}

int QXmppTransferOutgoingJob::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QXmppTransferJob::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
