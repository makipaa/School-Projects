/****************************************************************************
** Meta object code from reading C++ file 'mapwindow.hh'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "UI/mapwindow.hh"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mapwindow.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MapWindow_t {
    QByteArrayData data[24];
    char stringdata0[270];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MapWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MapWindow_t qt_meta_stringdata_MapWindow = {
    {
QT_MOC_LITERAL(0, 0, 9), // "MapWindow"
QT_MOC_LITERAL(1, 10, 11), // "setGridSize"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 4), // "size"
QT_MOC_LITERAL(4, 28, 9), // "setRounds"
QT_MOC_LITERAL(5, 38, 6), // "amount"
QT_MOC_LITERAL(6, 45, 9), // "getPlayer"
QT_MOC_LITERAL(7, 55, 46), // "std::vector<std::shared_ptr<S..."
QT_MOC_LITERAL(8, 102, 7), // "players"
QT_MOC_LITERAL(9, 110, 10), // "changeTurn"
QT_MOC_LITERAL(10, 121, 5), // "getId"
QT_MOC_LITERAL(11, 127, 2), // "Id"
QT_MOC_LITERAL(12, 130, 11), // "actionBuild"
QT_MOC_LITERAL(13, 142, 13), // "actionRecruit"
QT_MOC_LITERAL(14, 156, 11), // "resizeEvent"
QT_MOC_LITERAL(15, 168, 13), // "QResizeEvent*"
QT_MOC_LITERAL(16, 182, 5), // "event"
QT_MOC_LITERAL(17, 188, 18), // "updateBuildingInfo"
QT_MOC_LITERAL(18, 207, 12), // "buildingName"
QT_MOC_LITERAL(19, 220, 16), // "updateWorkerInfo"
QT_MOC_LITERAL(20, 237, 10), // "workerName"
QT_MOC_LITERAL(21, 248, 7), // "timeOut"
QT_MOC_LITERAL(22, 256, 8), // "exitGame"
QT_MOC_LITERAL(23, 265, 4) // "code"

    },
    "MapWindow\0setGridSize\0\0size\0setRounds\0"
    "amount\0getPlayer\0"
    "std::vector<std::shared_ptr<Student::Player> >\0"
    "players\0changeTurn\0getId\0Id\0actionBuild\0"
    "actionRecruit\0resizeEvent\0QResizeEvent*\0"
    "event\0updateBuildingInfo\0buildingName\0"
    "updateWorkerInfo\0workerName\0timeOut\0"
    "exitGame\0code"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MapWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x0a /* Public */,
       4,    1,   77,    2, 0x0a /* Public */,
       6,    1,   80,    2, 0x0a /* Public */,
       9,    0,   83,    2, 0x0a /* Public */,
      10,    1,   84,    2, 0x0a /* Public */,
      12,    0,   87,    2, 0x0a /* Public */,
      13,    0,   88,    2, 0x0a /* Public */,
      14,    1,   89,    2, 0x0a /* Public */,
      17,    1,   92,    2, 0x0a /* Public */,
      19,    1,   95,    2, 0x0a /* Public */,
      21,    0,   98,    2, 0x0a /* Public */,
      22,    1,   99,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   23,

       0        // eod
};

void MapWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MapWindow *_t = static_cast<MapWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setGridSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setRounds((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->getPlayer((*reinterpret_cast< std::vector<std::shared_ptr<Student::Player> >(*)>(_a[1]))); break;
        case 3: _t->changeTurn(); break;
        case 4: _t->getId((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 5: _t->actionBuild(); break;
        case 6: _t->actionRecruit(); break;
        case 7: _t->resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 8: _t->updateBuildingInfo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->updateWorkerInfo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->timeOut(); break;
        case 11: _t->exitGame((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MapWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MapWindow.data,
      qt_meta_data_MapWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MapWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MapWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MapWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MapWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
