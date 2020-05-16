/****************************************************************************
** Meta object code from reading C++ file 'QXmppMamManager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../client/QXmppMamManager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QXmppMamManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QXmppMamManager_t {
    QByteArrayData data[10];
    char stringdata0[130];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QXmppMamManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QXmppMamManager_t qt_meta_stringdata_QXmppMamManager = {
    {
QT_MOC_LITERAL(0, 0, 15), // "QXmppMamManager"
QT_MOC_LITERAL(1, 16, 23), // "archivedMessageReceived"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 7), // "queryId"
QT_MOC_LITERAL(4, 49, 12), // "QXmppMessage"
QT_MOC_LITERAL(5, 62, 7), // "message"
QT_MOC_LITERAL(6, 70, 15), // "resultsRecieved"
QT_MOC_LITERAL(7, 86, 19), // "QXmppResultSetReply"
QT_MOC_LITERAL(8, 106, 14), // "resultSetReply"
QT_MOC_LITERAL(9, 121, 8) // "complete"

    },
    "QXmppMamManager\0archivedMessageReceived\0"
    "\0queryId\0QXmppMessage\0message\0"
    "resultsRecieved\0QXmppResultSetReply\0"
    "resultSetReply\0complete"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QXmppMamManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x06 /* Public */,
       6,    3,   29,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 7, QMetaType::Bool,    3,    8,    9,

       0        // eod
};

void QXmppMamManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QXmppMamManager *_t = static_cast<QXmppMamManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->archivedMessageReceived((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QXmppMessage(*)>(_a[2]))); break;
        case 1: _t->resultsRecieved((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QXmppResultSetReply(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (QXmppMamManager::*_t)(const QString & , const QXmppMessage & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppMamManager::archivedMessageReceived)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QXmppMamManager::*_t)(const QString & , const QXmppResultSetReply & , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppMamManager::resultsRecieved)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject QXmppMamManager::staticMetaObject = {
    { &QXmppClientExtension::staticMetaObject, qt_meta_stringdata_QXmppMamManager.data,
      qt_meta_data_QXmppMamManager,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QXmppMamManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QXmppMamManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QXmppMamManager.stringdata0))
        return static_cast<void*>(this);
    return QXmppClientExtension::qt_metacast(_clname);
}

int QXmppMamManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QXmppClientExtension::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QXmppMamManager::archivedMessageReceived(const QString & _t1, const QXmppMessage & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QXmppMamManager::resultsRecieved(const QString & _t1, const QXmppResultSetReply & _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
