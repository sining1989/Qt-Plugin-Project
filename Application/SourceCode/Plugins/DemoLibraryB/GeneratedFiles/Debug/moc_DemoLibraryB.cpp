/****************************************************************************
** Meta object code from reading C++ file 'DemoLibraryB.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DemoLibraryB.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/qplugin.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DemoLibraryB.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_general_demo__DemoLibraryB_t {
    QByteArrayData data[6];
    char stringdata0[78];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_general_demo__DemoLibraryB_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_general_demo__DemoLibraryB_t qt_meta_stringdata_general_demo__DemoLibraryB = {
    {
QT_MOC_LITERAL(0, 0, 26), // "general_demo::DemoLibraryB"
QT_MOC_LITERAL(1, 27, 15), // "sendMsg2Manager"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 14), // "PluginMetaData"
QT_MOC_LITERAL(4, 59, 9), // "animation"
QT_MOC_LITERAL(5, 69, 8) // "QWidget*"

    },
    "general_demo::DemoLibraryB\0sendMsg2Manager\0"
    "\0PluginMetaData\0animation\0QWidget*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_general_demo__DemoLibraryB[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   27,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    2,

       0        // eod
};

void general_demo::DemoLibraryB::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DemoLibraryB *_t = static_cast<DemoLibraryB *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendMsg2Manager((*reinterpret_cast< PluginMetaData(*)>(_a[1]))); break;
        case 1: _t->animation((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< PluginMetaData >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (DemoLibraryB::*_t)(PluginMetaData );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DemoLibraryB::sendMsg2Manager)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject general_demo::DemoLibraryB::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_general_demo__DemoLibraryB.data,
      qt_meta_data_general_demo__DemoLibraryB,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *general_demo::DemoLibraryB::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *general_demo::DemoLibraryB::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_general_demo__DemoLibraryB.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "InterfacePlugin"))
        return static_cast< InterfacePlugin*>(this);
    if (!strcmp(_clname, "com.Interface.InterfacePlugin"))
        return static_cast< InterfacePlugin*>(this);
    return QWidget::qt_metacast(_clname);
}

int general_demo::DemoLibraryB::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void general_demo::DemoLibraryB::sendMsg2Manager(PluginMetaData _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

QT_PLUGIN_METADATA_SECTION const uint qt_section_alignment_dummy = 42;

#ifdef QT_NO_DEBUG

QT_PLUGIN_METADATA_SECTION
static const unsigned char qt_pluginMetaData[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', ' ',
    'q',  'b',  'j',  's',  0x01, 0x00, 0x00, 0x00,
    0xa4, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00,
    0x90, 0x00, 0x00, 0x00, 0x1b, 0x03, 0x00, 0x00,
    0x03, 0x00, 'I',  'I',  'D',  0x00, 0x00, 0x00,
    0x1d, 0x00, 'c',  'o',  'm',  '.',  'I',  'n', 
    't',  'e',  'r',  'f',  'a',  'c',  'e',  '.', 
    'I',  'n',  't',  'e',  'r',  'f',  'a',  'c', 
    'e',  'P',  'l',  'u',  'g',  'i',  'n',  0x00,
    0x1b, 0x09, 0x00, 0x00, 0x09, 0x00, 'c',  'l', 
    'a',  's',  's',  'N',  'a',  'm',  'e',  0x00,
    0x0c, 0x00, 'D',  'e',  'm',  'o',  'L',  'i', 
    'b',  'r',  'a',  'r',  'y',  'B',  0x00, 0x00,
    0xba, ' ',  0xa1, 0x00, 0x07, 0x00, 'v',  'e', 
    'r',  's',  'i',  'o',  'n',  0x00, 0x00, 0x00,
    0x11, 0x00, 0x00, 0x00, 0x05, 0x00, 'd',  'e', 
    'b',  'u',  'g',  0x00, 0x95, 0x10, 0x00, 0x00,
    0x08, 0x00, 'M',  'e',  't',  'a',  'D',  'a', 
    't',  'a',  0x00, 0x00, 0x0c, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0c, 0x00, 0x00, 0x00, 't',  0x00, 0x00, 0x00,
    '8',  0x00, 0x00, 0x00, 'h',  0x00, 0x00, 0x00,
    'X',  0x00, 0x00, 0x00
};

#else // QT_NO_DEBUG

QT_PLUGIN_METADATA_SECTION
static const unsigned char qt_pluginMetaData[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', ' ',
    'q',  'b',  'j',  's',  0x01, 0x00, 0x00, 0x00,
    0xa4, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00,
    0x90, 0x00, 0x00, 0x00, 0x1b, 0x03, 0x00, 0x00,
    0x03, 0x00, 'I',  'I',  'D',  0x00, 0x00, 0x00,
    0x1d, 0x00, 'c',  'o',  'm',  '.',  'I',  'n', 
    't',  'e',  'r',  'f',  'a',  'c',  'e',  '.', 
    'I',  'n',  't',  'e',  'r',  'f',  'a',  'c', 
    'e',  'P',  'l',  'u',  'g',  'i',  'n',  0x00,
    0x15, 0x09, 0x00, 0x00, 0x08, 0x00, 'M',  'e', 
    't',  'a',  'D',  'a',  't',  'a',  0x00, 0x00,
    0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x9b, 0x0c, 0x00, 0x00,
    0x09, 0x00, 'c',  'l',  'a',  's',  's',  'N', 
    'a',  'm',  'e',  0x00, 0x0c, 0x00, 'D',  'e', 
    'm',  'o',  'L',  'i',  'b',  'r',  'a',  'r', 
    'y',  'B',  0x00, 0x00, '1',  0x00, 0x00, 0x00,
    0x05, 0x00, 'd',  'e',  'b',  'u',  'g',  0x00,
    0xba, ' ',  0xa1, 0x00, 0x07, 0x00, 'v',  'e', 
    'r',  's',  'i',  'o',  'n',  0x00, 0x00, 0x00,
    0x0c, 0x00, 0x00, 0x00, '8',  0x00, 0x00, 0x00,
    'T',  0x00, 0x00, 0x00, 't',  0x00, 0x00, 0x00,
    0x80, 0x00, 0x00, 0x00
};
#endif // QT_NO_DEBUG

using namespace general_demo;
QT_MOC_EXPORT_PLUGIN(general_demo::DemoLibraryB, DemoLibraryB)

QT_WARNING_POP
QT_END_MOC_NAMESPACE
