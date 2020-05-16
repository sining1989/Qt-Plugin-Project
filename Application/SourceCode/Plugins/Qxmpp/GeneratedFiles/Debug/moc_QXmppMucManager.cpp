/****************************************************************************
** Meta object code from reading C++ file 'QXmppMucManager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../client/QXmppMucManager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QXmppMucManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QXmppMucManager_t {
    QByteArrayData data[16];
    char stringdata0[179];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QXmppMucManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QXmppMucManager_t qt_meta_stringdata_QXmppMucManager = {
    {
QT_MOC_LITERAL(0, 0, 15), // "QXmppMucManager"
QT_MOC_LITERAL(1, 16, 18), // "invitationReceived"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 7), // "roomJid"
QT_MOC_LITERAL(4, 44, 7), // "inviter"
QT_MOC_LITERAL(5, 52, 6), // "reason"
QT_MOC_LITERAL(6, 59, 9), // "roomAdded"
QT_MOC_LITERAL(7, 69, 13), // "QXmppMucRoom*"
QT_MOC_LITERAL(8, 83, 4), // "room"
QT_MOC_LITERAL(9, 88, 18), // "_q_messageReceived"
QT_MOC_LITERAL(10, 107, 12), // "QXmppMessage"
QT_MOC_LITERAL(11, 120, 7), // "message"
QT_MOC_LITERAL(12, 128, 16), // "_q_roomDestroyed"
QT_MOC_LITERAL(13, 145, 6), // "object"
QT_MOC_LITERAL(14, 152, 5), // "rooms"
QT_MOC_LITERAL(15, 158, 20) // "QList<QXmppMucRoom*>"

    },
    "QXmppMucManager\0invitationReceived\0\0"
    "roomJid\0inviter\0reason\0roomAdded\0"
    "QXmppMucRoom*\0room\0_q_messageReceived\0"
    "QXmppMessage\0message\0_q_roomDestroyed\0"
    "object\0rooms\0QList<QXmppMucRoom*>"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QXmppMucManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       1,   50, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   34,    2, 0x06 /* Public */,
       6,    1,   41,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   44,    2, 0x08 /* Private */,
      12,    1,   47,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,
    QMetaType::Void, 0x80000000 | 7,    8,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, QMetaType::QObjectStar,   13,

 // properties: name, type, flags
      14, 0x80000000 | 15, 0x00495009,

 // properties: notify_signal_id
       1,

       0        // eod
};

void QXmppMucManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QXmppMucManager *_t = static_cast<QXmppMucManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->invitationReceived((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 1: _t->roomAdded((*reinterpret_cast< QXmppMucRoom*(*)>(_a[1]))); break;
        case 2: _t->_q_messageReceived((*reinterpret_cast< const QXmppMessage(*)>(_a[1]))); break;
        case 3: _t->_q_roomDestroyed((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QXmppMucRoom* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (QXmppMucManager::*_t)(const QString & , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppMucManager::invitationReceived)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QXmppMucManager::*_t)(QXmppMucRoom * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppMucManager::roomAdded)) {
                *result = 1;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QXmppMucRoom*> >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        QXmppMucManager *_t = static_cast<QXmppMucManager *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QList<QXmppMucRoom*>*>(_v) = _t->rooms(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject QXmppMucManager::staticMetaObject = {
    { &QXmppClientExtension::staticMetaObject, qt_meta_stringdata_QXmppMucManager.data,
      qt_meta_data_QXmppMucManager,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QXmppMucManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QXmppMucManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QXmppMucManager.stringdata0))
        return static_cast<void*>(this);
    return QXmppClientExtension::qt_metacast(_clname);
}

int QXmppMucManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
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
void QXmppMucManager::invitationReceived(const QString & _t1, const QString & _t2, const QString & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QXmppMucManager::roomAdded(QXmppMucRoom * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_QXmppMucRoom_t {
    QByteArrayData data[64];
    char stringdata0[820];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QXmppMucRoom_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QXmppMucRoom_t qt_meta_stringdata_QXmppMucRoom = {
    {
QT_MOC_LITERAL(0, 0, 12), // "QXmppMucRoom"
QT_MOC_LITERAL(1, 13, 21), // "allowedActionsChanged"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 21), // "QXmppMucRoom::Actions"
QT_MOC_LITERAL(4, 58, 7), // "actions"
QT_MOC_LITERAL(5, 66, 21), // "configurationReceived"
QT_MOC_LITERAL(6, 88, 13), // "QXmppDataForm"
QT_MOC_LITERAL(7, 102, 13), // "configuration"
QT_MOC_LITERAL(8, 116, 5), // "error"
QT_MOC_LITERAL(9, 122, 18), // "QXmppStanza::Error"
QT_MOC_LITERAL(10, 141, 6), // "joined"
QT_MOC_LITERAL(11, 148, 6), // "kicked"
QT_MOC_LITERAL(12, 155, 3), // "jid"
QT_MOC_LITERAL(13, 159, 6), // "reason"
QT_MOC_LITERAL(14, 166, 15), // "isJoinedChanged"
QT_MOC_LITERAL(15, 182, 4), // "left"
QT_MOC_LITERAL(16, 187, 15), // "messageReceived"
QT_MOC_LITERAL(17, 203, 12), // "QXmppMessage"
QT_MOC_LITERAL(18, 216, 7), // "message"
QT_MOC_LITERAL(19, 224, 11), // "nameChanged"
QT_MOC_LITERAL(20, 236, 4), // "name"
QT_MOC_LITERAL(21, 241, 15), // "nickNameChanged"
QT_MOC_LITERAL(22, 257, 8), // "nickName"
QT_MOC_LITERAL(23, 266, 16), // "participantAdded"
QT_MOC_LITERAL(24, 283, 18), // "participantChanged"
QT_MOC_LITERAL(25, 302, 18), // "participantRemoved"
QT_MOC_LITERAL(26, 321, 19), // "participantsChanged"
QT_MOC_LITERAL(27, 341, 19), // "permissionsReceived"
QT_MOC_LITERAL(28, 361, 19), // "QList<QXmppMucItem>"
QT_MOC_LITERAL(29, 381, 11), // "permissions"
QT_MOC_LITERAL(30, 393, 14), // "subjectChanged"
QT_MOC_LITERAL(31, 408, 7), // "subject"
QT_MOC_LITERAL(32, 416, 3), // "ban"
QT_MOC_LITERAL(33, 420, 4), // "join"
QT_MOC_LITERAL(34, 425, 4), // "kick"
QT_MOC_LITERAL(35, 430, 5), // "leave"
QT_MOC_LITERAL(36, 436, 20), // "requestConfiguration"
QT_MOC_LITERAL(37, 457, 18), // "requestPermissions"
QT_MOC_LITERAL(38, 476, 16), // "setConfiguration"
QT_MOC_LITERAL(39, 493, 4), // "form"
QT_MOC_LITERAL(40, 498, 14), // "setPermissions"
QT_MOC_LITERAL(41, 513, 14), // "sendInvitation"
QT_MOC_LITERAL(42, 528, 11), // "sendMessage"
QT_MOC_LITERAL(43, 540, 4), // "text"
QT_MOC_LITERAL(44, 545, 15), // "_q_disconnected"
QT_MOC_LITERAL(45, 561, 24), // "_q_discoveryInfoReceived"
QT_MOC_LITERAL(46, 586, 16), // "QXmppDiscoveryIq"
QT_MOC_LITERAL(47, 603, 2), // "iq"
QT_MOC_LITERAL(48, 606, 18), // "_q_messageReceived"
QT_MOC_LITERAL(49, 625, 19), // "_q_presenceReceived"
QT_MOC_LITERAL(50, 645, 13), // "QXmppPresence"
QT_MOC_LITERAL(51, 659, 8), // "presence"
QT_MOC_LITERAL(52, 668, 18), // "participantFullJid"
QT_MOC_LITERAL(53, 687, 14), // "allowedActions"
QT_MOC_LITERAL(54, 702, 8), // "isJoined"
QT_MOC_LITERAL(55, 711, 12), // "participants"
QT_MOC_LITERAL(56, 724, 8), // "password"
QT_MOC_LITERAL(57, 733, 6), // "Action"
QT_MOC_LITERAL(58, 740, 8), // "NoAction"
QT_MOC_LITERAL(59, 749, 13), // "SubjectAction"
QT_MOC_LITERAL(60, 763, 19), // "ConfigurationAction"
QT_MOC_LITERAL(61, 783, 17), // "PermissionsAction"
QT_MOC_LITERAL(62, 801, 10), // "KickAction"
QT_MOC_LITERAL(63, 812, 7) // "Actions"

    },
    "QXmppMucRoom\0allowedActionsChanged\0\0"
    "QXmppMucRoom::Actions\0actions\0"
    "configurationReceived\0QXmppDataForm\0"
    "configuration\0error\0QXmppStanza::Error\0"
    "joined\0kicked\0jid\0reason\0isJoinedChanged\0"
    "left\0messageReceived\0QXmppMessage\0"
    "message\0nameChanged\0name\0nickNameChanged\0"
    "nickName\0participantAdded\0participantChanged\0"
    "participantRemoved\0participantsChanged\0"
    "permissionsReceived\0QList<QXmppMucItem>\0"
    "permissions\0subjectChanged\0subject\0"
    "ban\0join\0kick\0leave\0requestConfiguration\0"
    "requestPermissions\0setConfiguration\0"
    "form\0setPermissions\0sendInvitation\0"
    "sendMessage\0text\0_q_disconnected\0"
    "_q_discoveryInfoReceived\0QXmppDiscoveryIq\0"
    "iq\0_q_messageReceived\0_q_presenceReceived\0"
    "QXmppPresence\0presence\0participantFullJid\0"
    "allowedActions\0isJoined\0participants\0"
    "password\0Action\0NoAction\0SubjectAction\0"
    "ConfigurationAction\0PermissionsAction\0"
    "KickAction\0Actions"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QXmppMucRoom[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      32,   14, // methods
       8,  260, // properties
       2,  292, // enums/sets
       0,    0, // constructors
       0,       // flags
      16,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  174,    2, 0x06 /* Public */,
       5,    1,  177,    2, 0x06 /* Public */,
       8,    1,  180,    2, 0x06 /* Public */,
      10,    0,  183,    2, 0x06 /* Public */,
      11,    2,  184,    2, 0x06 /* Public */,
      14,    0,  189,    2, 0x06 /* Public */,
      15,    0,  190,    2, 0x06 /* Public */,
      16,    1,  191,    2, 0x06 /* Public */,
      19,    1,  194,    2, 0x06 /* Public */,
      21,    1,  197,    2, 0x06 /* Public */,
      23,    1,  200,    2, 0x06 /* Public */,
      24,    1,  203,    2, 0x06 /* Public */,
      25,    1,  206,    2, 0x06 /* Public */,
      26,    0,  209,    2, 0x06 /* Public */,
      27,    1,  210,    2, 0x06 /* Public */,
      30,    1,  213,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      32,    2,  216,    2, 0x0a /* Public */,
      33,    0,  221,    2, 0x0a /* Public */,
      34,    2,  222,    2, 0x0a /* Public */,
      35,    1,  227,    2, 0x0a /* Public */,
      35,    0,  230,    2, 0x2a /* Public | MethodCloned */,
      36,    0,  231,    2, 0x0a /* Public */,
      37,    0,  232,    2, 0x0a /* Public */,
      38,    1,  233,    2, 0x0a /* Public */,
      40,    1,  236,    2, 0x0a /* Public */,
      41,    2,  239,    2, 0x0a /* Public */,
      42,    1,  244,    2, 0x0a /* Public */,
      44,    0,  247,    2, 0x08 /* Private */,
      45,    1,  248,    2, 0x08 /* Private */,
      48,    1,  251,    2, 0x08 /* Private */,
      49,    1,  254,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
      52,    1,  257,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 9,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   12,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void, QMetaType::QString,   22,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 28,   29,
    QMetaType::Void, QMetaType::QString,   31,

 // slots: parameters
    QMetaType::Bool, QMetaType::QString, QMetaType::QString,   12,   13,
    QMetaType::Bool,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString,   12,   13,
    QMetaType::Bool, QMetaType::QString,   18,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool, 0x80000000 | 6,   39,
    QMetaType::Bool, 0x80000000 | 28,   29,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString,   12,   13,
    QMetaType::Bool, QMetaType::QString,   43,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 46,   47,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, 0x80000000 | 50,   51,

 // methods: parameters
    QMetaType::QString, QMetaType::QString,   12,

 // properties: name, type, flags
      53, 0x80000000 | 3, 0x00495009,
      54, QMetaType::Bool, 0x00495001,
      12, QMetaType::QString, 0x00095401,
      20, QMetaType::QString, 0x00495001,
      22, QMetaType::QString, 0x00495103,
      55, QMetaType::QStringList, 0x00495001,
      56, QMetaType::QString, 0x00095103,
      31, QMetaType::QString, 0x00495103,

 // properties: notify_signal_id
       0,
       5,
       0,
       8,
       9,
      13,
       0,
      15,

 // enums: name, flags, count, data
      57, 0x1,    5,  300,
      63, 0x1,    5,  310,

 // enum data: key, value
      58, uint(QXmppMucRoom::NoAction),
      59, uint(QXmppMucRoom::SubjectAction),
      60, uint(QXmppMucRoom::ConfigurationAction),
      61, uint(QXmppMucRoom::PermissionsAction),
      62, uint(QXmppMucRoom::KickAction),
      58, uint(QXmppMucRoom::NoAction),
      59, uint(QXmppMucRoom::SubjectAction),
      60, uint(QXmppMucRoom::ConfigurationAction),
      61, uint(QXmppMucRoom::PermissionsAction),
      62, uint(QXmppMucRoom::KickAction),

       0        // eod
};

void QXmppMucRoom::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QXmppMucRoom *_t = static_cast<QXmppMucRoom *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->allowedActionsChanged((*reinterpret_cast< QXmppMucRoom::Actions(*)>(_a[1]))); break;
        case 1: _t->configurationReceived((*reinterpret_cast< const QXmppDataForm(*)>(_a[1]))); break;
        case 2: _t->error((*reinterpret_cast< const QXmppStanza::Error(*)>(_a[1]))); break;
        case 3: _t->joined(); break;
        case 4: _t->kicked((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 5: _t->isJoinedChanged(); break;
        case 6: _t->left(); break;
        case 7: _t->messageReceived((*reinterpret_cast< const QXmppMessage(*)>(_a[1]))); break;
        case 8: _t->nameChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->nickNameChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->participantAdded((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->participantChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->participantRemoved((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->participantsChanged(); break;
        case 14: _t->permissionsReceived((*reinterpret_cast< const QList<QXmppMucItem>(*)>(_a[1]))); break;
        case 15: _t->subjectChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 16: { bool _r = _t->ban((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 17: { bool _r = _t->join();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 18: { bool _r = _t->kick((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 19: { bool _r = _t->leave((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 20: { bool _r = _t->leave();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 21: { bool _r = _t->requestConfiguration();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 22: { bool _r = _t->requestPermissions();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 23: { bool _r = _t->setConfiguration((*reinterpret_cast< const QXmppDataForm(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 24: { bool _r = _t->setPermissions((*reinterpret_cast< const QList<QXmppMucItem>(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 25: { bool _r = _t->sendInvitation((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 26: { bool _r = _t->sendMessage((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 27: _t->_q_disconnected(); break;
        case 28: _t->_q_discoveryInfoReceived((*reinterpret_cast< const QXmppDiscoveryIq(*)>(_a[1]))); break;
        case 29: _t->_q_messageReceived((*reinterpret_cast< const QXmppMessage(*)>(_a[1]))); break;
        case 30: _t->_q_presenceReceived((*reinterpret_cast< const QXmppPresence(*)>(_a[1]))); break;
        case 31: { QString _r = _t->participantFullJid((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (QXmppMucRoom::*_t)(QXmppMucRoom::Actions ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppMucRoom::allowedActionsChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QXmppMucRoom::*_t)(const QXmppDataForm & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppMucRoom::configurationReceived)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (QXmppMucRoom::*_t)(const QXmppStanza::Error & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppMucRoom::error)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (QXmppMucRoom::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppMucRoom::joined)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (QXmppMucRoom::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppMucRoom::kicked)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (QXmppMucRoom::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppMucRoom::isJoinedChanged)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (QXmppMucRoom::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppMucRoom::left)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (QXmppMucRoom::*_t)(const QXmppMessage & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppMucRoom::messageReceived)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (QXmppMucRoom::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppMucRoom::nameChanged)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (QXmppMucRoom::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppMucRoom::nickNameChanged)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (QXmppMucRoom::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppMucRoom::participantAdded)) {
                *result = 10;
                return;
            }
        }
        {
            typedef void (QXmppMucRoom::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppMucRoom::participantChanged)) {
                *result = 11;
                return;
            }
        }
        {
            typedef void (QXmppMucRoom::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppMucRoom::participantRemoved)) {
                *result = 12;
                return;
            }
        }
        {
            typedef void (QXmppMucRoom::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppMucRoom::participantsChanged)) {
                *result = 13;
                return;
            }
        }
        {
            typedef void (QXmppMucRoom::*_t)(const QList<QXmppMucItem> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppMucRoom::permissionsReceived)) {
                *result = 14;
                return;
            }
        }
        {
            typedef void (QXmppMucRoom::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QXmppMucRoom::subjectChanged)) {
                *result = 15;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        QXmppMucRoom *_t = static_cast<QXmppMucRoom *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QXmppMucRoom::Actions*>(_v) = _t->allowedActions(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->isJoined(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->jid(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->name(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->nickName(); break;
        case 5: *reinterpret_cast< QStringList*>(_v) = _t->participants(); break;
        case 6: *reinterpret_cast< QString*>(_v) = _t->password(); break;
        case 7: *reinterpret_cast< QString*>(_v) = _t->subject(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        QXmppMucRoom *_t = static_cast<QXmppMucRoom *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 4: _t->setNickName(*reinterpret_cast< QString*>(_v)); break;
        case 6: _t->setPassword(*reinterpret_cast< QString*>(_v)); break;
        case 7: _t->setSubject(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject QXmppMucRoom::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QXmppMucRoom.data,
      qt_meta_data_QXmppMucRoom,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QXmppMucRoom::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QXmppMucRoom::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QXmppMucRoom.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QXmppMucRoom::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 32)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 32;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 32)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 32;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 8;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QXmppMucRoom::allowedActionsChanged(QXmppMucRoom::Actions _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< QXmppMucRoom *>(this), &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QXmppMucRoom::configurationReceived(const QXmppDataForm & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QXmppMucRoom::error(const QXmppStanza::Error & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QXmppMucRoom::joined()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void QXmppMucRoom::kicked(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void QXmppMucRoom::isJoinedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void QXmppMucRoom::left()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void QXmppMucRoom::messageReceived(const QXmppMessage & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void QXmppMucRoom::nameChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void QXmppMucRoom::nickNameChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void QXmppMucRoom::participantAdded(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void QXmppMucRoom::participantChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void QXmppMucRoom::participantRemoved(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void QXmppMucRoom::participantsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}

// SIGNAL 14
void QXmppMucRoom::permissionsReceived(const QList<QXmppMucItem> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void QXmppMucRoom::subjectChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
