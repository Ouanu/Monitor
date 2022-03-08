/****************************************************************************
** Meta object code from reading C++ file 'cmythread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "cmythread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cmythread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_cmythread_t {
    QByteArrayData data[7];
    char stringdata[51];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cmythread_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cmythread_t qt_meta_stringdata_cmythread = {
    {
QT_MOC_LITERAL(0, 0, 9), // "cmythread"
QT_MOC_LITERAL(1, 10, 8), // "turnLeft"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 9), // "turnRight"
QT_MOC_LITERAL(4, 30, 6), // "turnUp"
QT_MOC_LITERAL(5, 37, 8), // "turnDown"
QT_MOC_LITERAL(6, 46, 4) // "init"

    },
    "cmythread\0turnLeft\0\0turnRight\0turnUp\0"
    "turnDown\0init"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cmythread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x0a /* Public */,
       3,    0,   40,    2, 0x0a /* Public */,
       4,    0,   41,    2, 0x0a /* Public */,
       5,    0,   42,    2, 0x0a /* Public */,
       6,    0,   43,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void cmythread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        cmythread *_t = static_cast<cmythread *>(_o);
        switch (_id) {
        case 0: _t->turnLeft(); break;
        case 1: _t->turnRight(); break;
        case 2: _t->turnUp(); break;
        case 3: _t->turnDown(); break;
        case 4: _t->init(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject cmythread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_cmythread.data,
      qt_meta_data_cmythread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *cmythread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cmythread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_cmythread.stringdata))
        return static_cast<void*>(const_cast< cmythread*>(this));
    return QThread::qt_metacast(_clname);
}

int cmythread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
