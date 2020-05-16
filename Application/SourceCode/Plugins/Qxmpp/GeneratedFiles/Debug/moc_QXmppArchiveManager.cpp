/****************************************************************************
** Meta object code from reading C++ file 'QXmppArchiveManager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../client/QXmppArchiveManager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QXmppArchiveManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QXmppArchiveManager_t {
    QByteArrayData data[8];
    char stringdata0[126];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QXmppArchiveManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QXmppArchiveManager_t qt_meta_stringdata_QXmppArchiveManager = {
    {
QT_MOC_LITERAL(0, 0, 19), // "QXmppArchiveManager"
QT_MOC_LITERAL(1, 20, 19), // "archiveListReceived"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 23), // "QList<QXmppArchiveChat>"
QT_MOC_LITERAL(4, 65, 19), // "QXmppResultSetReply"
QT_MOC_LITERAL(5, 85, 3), // "rsm"
QT_MOC_LITERAL(6, 89, 19), // "archiveChatReceived"
QT_MOC_LITERAL(7, 109, 16) // "QXmppArchiveChat"

    },
    "QXmppArchiveManager\0archiveListReceived\0"
    "\0QList<QXmppArchiveChat>\0QXmppResultSetReply\0"
    "rsm\0archiveChatReceived\0QXmppArchiveChat"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QXmppArchiveManager[] = {

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
       1,    1,   39,    2, 0x26 /* Public | MethodCloned */,
       6,    2,   42,    2, 0x06 /* Public */,
       6,    1,   47,    2, 0x26 /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    5,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 4,    2,    5,
    QMetaType::Void, 0x80000000 | 7,    2,

       0        // eod
};

void QXmppArchiveManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QXmppArchiveManager *_t = static_cast<QXmppArchiveManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->archiveListReceived((*reinterpret_cast< const QList<QXmppArchiveChat>(*)>(_a[1])),(*reinterpret_cast< const QXmppResultSetReply(*)>(_a[2]))); break;
        case 1: _t->archiveListReceived((*reinterpret_cast< const QList<QXmppArchiveChat>(*)>(_a[1]))); break;
        case 2: _t->archiveChatReceived((*reinterpret_cast< const QXmppArchiveChat(*)>(_a[1])),(*reinterpret_cast< const QXmppResultSetReply(*)>(_a[2]))); break;
        case 3: _t->archiveChatReceived((*reinterpret_cast< const QXmppArchiveChat(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (QXmppArchiveManager::*_t)(const QList<QXmppArchiveChat> & , const QXmppResultSetReply & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppArchiveManager::archiveListReceived)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QXmppArchiveManager::*_t)(const QXmppArchiveChat & , const QXmppResultSetReply & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppArchiveManager::archiveChatReceived)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject QXmppArchiveManager::staticMetaObject = {
    { &QXmppClientExtension::staticMetaObject, qt_meta_stringdata_QXmppArchiveManager.data,
      qt_meta_data_QXmppArchiveManager,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QXmppArchiveManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QXmppArchiveManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QXmppArchiveManager.stringdata0))
        return static_cast<void*>(this);
    return QXmppClientExtension::qt_metacast(_clname);
}

int QXmppArchiveManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QXmppClientExtension::qt_metacall(_c, _id, _a);
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
void QXmppArchiveManager::archiveListReceived(const QList<QXmppArchiveChat> & _t1, const QXmppResultSetReply & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 2
void QXmppArchiveManager::archiveChatReceived(const QXmppArchiveChat & _t1, const QXmppResultSetReply & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
