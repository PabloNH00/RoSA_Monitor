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
    QByteArrayData data[15];
    char stringdata0[318];
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
QT_MOC_LITERAL(3, 31, 14), // "showMainWindow"
QT_MOC_LITERAL(4, 46, 23), // "on_GazeboButton_clicked"
QT_MOC_LITERAL(5, 70, 21), // "on_SlamButton_clicked"
QT_MOC_LITERAL(6, 92, 22), // "on_RvizzButton_clicked"
QT_MOC_LITERAL(7, 115, 22), // "on_graphButton_clicked"
QT_MOC_LITERAL(8, 138, 20), // "on_rqtButton_clicked"
QT_MOC_LITERAL(9, 159, 25), // "on_mainMenuButton_clicked"
QT_MOC_LITERAL(10, 185, 27), // "on_navigationButton_clicked"
QT_MOC_LITERAL(11, 213, 26), // "on_selectMapButton_clicked"
QT_MOC_LITERAL(12, 240, 27), // "on_viewFramesButton_clicked"
QT_MOC_LITERAL(13, 268, 23), // "on_TeleopButton_clicked"
QT_MOC_LITERAL(14, 292, 25) // "on_nodeListButton_clicked"

    },
    "SimulationWindow\0windowClosed\0\0"
    "showMainWindow\0on_GazeboButton_clicked\0"
    "on_SlamButton_clicked\0on_RvizzButton_clicked\0"
    "on_graphButton_clicked\0on_rqtButton_clicked\0"
    "on_mainMenuButton_clicked\0"
    "on_navigationButton_clicked\0"
    "on_selectMapButton_clicked\0"
    "on_viewFramesButton_clicked\0"
    "on_TeleopButton_clicked\0"
    "on_nodeListButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SimulationWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    0,   80,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   81,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    0,   83,    2, 0x08 /* Private */,
       7,    0,   84,    2, 0x08 /* Private */,
       8,    0,   85,    2, 0x08 /* Private */,
       9,    0,   86,    2, 0x08 /* Private */,
      10,    0,   87,    2, 0x08 /* Private */,
      11,    0,   88,    2, 0x08 /* Private */,
      12,    0,   89,    2, 0x08 /* Private */,
      13,    0,   90,    2, 0x08 /* Private */,
      14,    0,   91,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
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
        case 1: _t->showMainWindow(); break;
        case 2: _t->on_GazeboButton_clicked(); break;
        case 3: _t->on_SlamButton_clicked(); break;
        case 4: _t->on_RvizzButton_clicked(); break;
        case 5: _t->on_graphButton_clicked(); break;
        case 6: _t->on_rqtButton_clicked(); break;
        case 7: _t->on_mainMenuButton_clicked(); break;
        case 8: _t->on_navigationButton_clicked(); break;
        case 9: _t->on_selectMapButton_clicked(); break;
        case 10: _t->on_viewFramesButton_clicked(); break;
        case 11: _t->on_TeleopButton_clicked(); break;
        case 12: _t->on_nodeListButton_clicked(); break;
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
        {
            using _t = void (SimulationWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SimulationWindow::showMainWindow)) {
                *result = 1;
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
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void SimulationWindow::windowClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SimulationWindow::showMainWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
