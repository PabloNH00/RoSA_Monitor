/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../RoSA_Monitor/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[15];
    char stringdata0[280];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 12), // "resizeImages"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 11), // "resizeEvent"
QT_MOC_LITERAL(4, 37, 13), // "QResizeEvent*"
QT_MOC_LITERAL(5, 51, 5), // "event"
QT_MOC_LITERAL(6, 57, 25), // "on_EnterSimButton_clicked"
QT_MOC_LITERAL(7, 83, 24), // "onSimulationWindowClosed"
QT_MOC_LITERAL(8, 108, 21), // "on_RosaButton_clicked"
QT_MOC_LITERAL(9, 130, 18), // "onRosaWindowClosed"
QT_MOC_LITERAL(10, 149, 21), // "on_DemoButton_clicked"
QT_MOC_LITERAL(11, 171, 18), // "onDemoWindowClosed"
QT_MOC_LITERAL(12, 190, 34), // "on_select_workspace_button_cl..."
QT_MOC_LITERAL(13, 225, 29), // "on_previousMenuButton_clicked"
QT_MOC_LITERAL(14, 255, 24) // "onGetWorkspaceFromWindow"

    },
    "MainWindow\0resizeImages\0\0resizeEvent\0"
    "QResizeEvent*\0event\0on_EnterSimButton_clicked\0"
    "onSimulationWindowClosed\0on_RosaButton_clicked\0"
    "onRosaWindowClosed\0on_DemoButton_clicked\0"
    "onDemoWindowClosed\0"
    "on_select_workspace_button_clicked\0"
    "on_previousMenuButton_clicked\0"
    "onGetWorkspaceFromWindow"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    1,   70,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    0,   79,    2, 0x08 /* Private */,
      13,    0,   80,    2, 0x08 /* Private */,
      14,    0,   81,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
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

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->resizeImages(); break;
        case 1: _t->resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 2: _t->on_EnterSimButton_clicked(); break;
        case 3: _t->onSimulationWindowClosed(); break;
        case 4: _t->on_RosaButton_clicked(); break;
        case 5: _t->onRosaWindowClosed(); break;
        case 6: _t->on_DemoButton_clicked(); break;
        case 7: _t->onDemoWindowClosed(); break;
        case 8: _t->on_select_workspace_button_clicked(); break;
        case 9: _t->on_previousMenuButton_clicked(); break;
        case 10: _t->onGetWorkspaceFromWindow(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
