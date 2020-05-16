/****************************************************************************
** Meta object code from reading C++ file 'QXmppVCardManager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../client/QXmppVCardManager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QXmppVCardManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QXmppVCardManager_t {
    QByteArrayData data[5];
    char stringdata0[66];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QXmppVCardManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QXmppVCardManager_t qt_meta_stringdata_QXmppVCardManager = {
    {
QT_MOC_LITERAL(0, 0, 17), // "QXmppVCardManager"
QT_MOC_LITERAL(1, 18, 13), // "vCardReceived"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 12), // "QXmppVCardIq"
QT_MOC_LITERAL(4, 46, 19) // "clientVCardReceived"

    },
    "QXmppVCardManager\0vCardReceived\0\0"
    "QXmppVCardIq\0clientVCardReceived"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QXmppVCardManager[] = {

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
       1,    1,   24,    2, 0x06 /* Public */,
       4,    0,   27,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,

       0        // eod
};

void QXmppVCardManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QXmppVCardManager *_t = static_cast<QXmppVCardManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->vCardReceived((*reinterpret_cast< const QXmppVCardIq(*)>(_a[1]))); break;
        case 1: _t->clientVCardReceived(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (QXmppVCardManager::*_t)(const QXmppVCardIq & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppVCardManager::vCardReceived)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QXmppVCardManager::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppVCardManager::clientVCardReceived)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject QXmppVCardManager::staticMetaObject = {
    { &QXmppClientExtension::staticMetaObject, qt_meta_stringdata_QXmppVCardManager.data,
      qt_meta_data_QXmppVCardManager,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QXmppVCardManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QXmppVCardManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QXmppVCardManager.stringdata0))
        return static_cast<void*>(this);
    return QXmppClientExtension::qt_metacast(_clname);
}

int QXmppVCardManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void QXmppVCardManager::vCardReceived(const QXmppVCardIq & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QXmppVCardManager::clientVCardReceived()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
