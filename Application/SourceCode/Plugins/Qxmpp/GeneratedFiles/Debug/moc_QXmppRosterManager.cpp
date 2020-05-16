/****************************************************************************
** Meta object code from reading C++ file 'QXmppRosterManager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../client/QXmppRosterManager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QSet>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QXmppRosterManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QXmppRosterManager_t {
    QByteArrayData data[25];
    char stringdata0[309];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QXmppRosterManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QXmppRosterManager_t qt_meta_stringdata_QXmppRosterManager = {
    {
QT_MOC_LITERAL(0, 0, 18), // "QXmppRosterManager"
QT_MOC_LITERAL(1, 19, 14), // "rosterReceived"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 15), // "presenceChanged"
QT_MOC_LITERAL(4, 51, 7), // "bareJid"
QT_MOC_LITERAL(5, 59, 8), // "resource"
QT_MOC_LITERAL(6, 68, 20), // "subscriptionReceived"
QT_MOC_LITERAL(7, 89, 9), // "itemAdded"
QT_MOC_LITERAL(8, 99, 11), // "itemChanged"
QT_MOC_LITERAL(9, 111, 11), // "itemRemoved"
QT_MOC_LITERAL(10, 123, 18), // "acceptSubscription"
QT_MOC_LITERAL(11, 142, 6), // "reason"
QT_MOC_LITERAL(12, 149, 18), // "refuseSubscription"
QT_MOC_LITERAL(13, 168, 7), // "addItem"
QT_MOC_LITERAL(14, 176, 4), // "name"
QT_MOC_LITERAL(15, 181, 13), // "QSet<QString>"
QT_MOC_LITERAL(16, 195, 6), // "groups"
QT_MOC_LITERAL(17, 202, 10), // "removeItem"
QT_MOC_LITERAL(18, 213, 10), // "renameItem"
QT_MOC_LITERAL(19, 224, 9), // "subscribe"
QT_MOC_LITERAL(20, 234, 11), // "unsubscribe"
QT_MOC_LITERAL(21, 246, 12), // "_q_connected"
QT_MOC_LITERAL(22, 259, 15), // "_q_disconnected"
QT_MOC_LITERAL(23, 275, 19), // "_q_presenceReceived"
QT_MOC_LITERAL(24, 295, 13) // "QXmppPresence"

    },
    "QXmppRosterManager\0rosterReceived\0\0"
    "presenceChanged\0bareJid\0resource\0"
    "subscriptionReceived\0itemAdded\0"
    "itemChanged\0itemRemoved\0acceptSubscription\0"
    "reason\0refuseSubscription\0addItem\0"
    "name\0QSet<QString>\0groups\0removeItem\0"
    "renameItem\0subscribe\0unsubscribe\0"
    "_q_connected\0_q_disconnected\0"
    "_q_presenceReceived\0QXmppPresence"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QXmppRosterManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  124,    2, 0x06 /* Public */,
       3,    2,  125,    2, 0x06 /* Public */,
       6,    1,  130,    2, 0x06 /* Public */,
       7,    1,  133,    2, 0x06 /* Public */,
       8,    1,  136,    2, 0x06 /* Public */,
       9,    1,  139,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    2,  142,    2, 0x0a /* Public */,
      10,    1,  147,    2, 0x2a /* Public | MethodCloned */,
      12,    2,  150,    2, 0x0a /* Public */,
      12,    1,  155,    2, 0x2a /* Public | MethodCloned */,
      13,    3,  158,    2, 0x0a /* Public */,
      13,    2,  165,    2, 0x2a /* Public | MethodCloned */,
      13,    1,  170,    2, 0x2a /* Public | MethodCloned */,
      17,    1,  173,    2, 0x0a /* Public */,
      18,    2,  176,    2, 0x0a /* Public */,
      19,    2,  181,    2, 0x0a /* Public */,
      19,    1,  186,    2, 0x2a /* Public | MethodCloned */,
      20,    2,  189,    2, 0x0a /* Public */,
      20,    1,  194,    2, 0x2a /* Public | MethodCloned */,
      21,    0,  197,    2, 0x08 /* Private */,
      22,    0,  198,    2, 0x08 /* Private */,
      23,    1,  199,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    4,    5,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,

 // slots: parameters
    QMetaType::Bool, QMetaType::QString, QMetaType::QString,    4,   11,
    QMetaType::Bool, QMetaType::QString,    4,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString,    4,   11,
    QMetaType::Bool, QMetaType::QString,    4,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, 0x80000000 | 15,    4,   14,   16,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString,    4,   14,
    QMetaType::Bool, QMetaType::QString,    4,
    QMetaType::Bool, QMetaType::QString,    4,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString,    4,   14,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString,    4,   11,
    QMetaType::Bool, QMetaType::QString,    4,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString,    4,   11,
    QMetaType::Bool, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 24,    2,

       0        // eod
};

void QXmppRosterManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QXmppRosterManager *_t = static_cast<QXmppRosterManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->rosterReceived(); break;
        case 1: _t->presenceChanged((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->subscriptionReceived((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->itemAdded((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->itemChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->itemRemoved((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: { bool _r = _t->acceptSubscription((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 7: { bool _r = _t->acceptSubscription((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 8: { bool _r = _t->refuseSubscription((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 9: { bool _r = _t->refuseSubscription((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 10: { bool _r = _t->addItem((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QSet<QString>(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: { bool _r = _t->addItem((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 12: { bool _r = _t->addItem((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 13: { bool _r = _t->removeItem((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 14: { bool _r = _t->renameItem((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 15: { bool _r = _t->subscribe((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 16: { bool _r = _t->subscribe((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 17: { bool _r = _t->unsubscribe((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 18: { bool _r = _t->unsubscribe((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 19: _t->_q_connected(); break;
        case 20: _t->_q_disconnected(); break;
        case 21: _t->_q_presenceReceived((*reinterpret_cast< const QXmppPresence(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QSet<QString> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (QXmppRosterManager::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppRosterManager::rosterReceived)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QXmppRosterManager::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppRosterManager::presenceChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (QXmppRosterManager::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppRosterManager::subscriptionReceived)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (QXmppRosterManager::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppRosterManager::itemAdded)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (QXmppRosterManager::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppRosterManager::itemChanged)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (QXmppRosterManager::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppRosterManager::itemRemoved)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject QXmppRosterManager::staticMetaObject = {
    { &QXmppClientExtension::staticMetaObject, qt_meta_stringdata_QXmppRosterManager.data,
      qt_meta_data_QXmppRosterManager,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QXmppRosterManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QXmppRosterManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QXmppRosterManager.stringdata0))
        return static_cast<void*>(this);
    return QXmppClientExtension::qt_metacast(_clname);
}

int QXmppRosterManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QXmppClientExtension::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    }
    return _id;
}

// SIGNAL 0
void QXmppRosterManager::rosterReceived()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QXmppRosterManager::presenceChanged(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QXmppRosterManager::subscriptionReceived(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QXmppRosterManager::itemAdded(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QXmppRosterManager::itemChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void QXmppRosterManager::itemRemoved(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
