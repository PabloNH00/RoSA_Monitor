/****************************************************************************
** Meta object code from reading C++ file 'simulationwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../RoSA_Monitor/simulationwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'simulationwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SimulationWindow_t {
    QByteArrayData data[13];
    char stringdata0[277];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SimulationWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SimulationWindow_t qt_meta_stringdata_SimulationWindow = {
    {
QT_MOC_LITERAL(0, 0, 16), // "SimulationWindow"
QT_MOC_LITERAL(1, 17, 12), // "windowClosed"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 23), // "on_GazeboButton_clicked"
QT_MOC_LITERAL(4, 55, 21), // "on_SlamButton_clicked"
QT_MOC_LITERAL(5, 77, 22), // "on_RvizzButton_clicked"
QT_MOC_LITERAL(6, 100, 22), // "on_graphButton_clicked"
QT_MOC_LITERAL(7, 123, 20), // "on_rqtButton_clicked"
QT_MOC_LITERAL(8, 144, 25), // "on_mainMenuButton_clicked"
QT_MOC_LITERAL(9, 170, 27), // "on_navigationButton_clicked"
QT_MOC_LITERAL(10, 198, 26), // "on_selectMapButton_clicked"
QT_MOC_LITERAL(11, 225, 27), // "on_viewFramesButton_clicked"
QT_MOC_LITERAL(12, 253, 23) // "on_TeleopButton_clicked"

    },
    "SimulationWindow\0windowClosed\0\0"
    "on_GazeboButton_clicked\0on_SlamButton_clicked\0"
    "on_RvizzButton_clicked\0on_graphButton_clicked\0"
    "on_rqtButton_clicked\0on_mainMenuButton_clicked\0"
    "on_navigationButton_clicked\0"
    "on_selectMapButton_clicked\0"
    "on_viewFramesButton_clicked\0"
    "on_TeleopButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SimulationWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    0,   79,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SimulationWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SimulationWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->windowClosed(); break;
        case 1: _t->on_GazeboButton_clicked(); break;
        case 2: _t->on_SlamButton_clicked(); break;
        case 3: _t->on_RvizzButton_clicked(); break;
        case 4: _t->on_graphButton_clicked(); break;
        case 5: _t->on_rqtButton_clicked(); break;
        case 6: _t->on_mainMenuButton_clicked(); break;
        case 7: _t->on_navigationButton_clicked(); break;
        case 8: _t->on_selectMapButton_clicked(); break;
        case 9: _t->on_viewFramesButton_clicked(); break;
        case 10: _t->on_TeleopButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SimulationWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SimulationWindow::windowClosed)) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject SimulationWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_SimulationWindow.data,
    qt_meta_data_SimulationWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SimulationWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SimulationWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SimulationWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int SimulationWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void SimulationWindow::windowClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE