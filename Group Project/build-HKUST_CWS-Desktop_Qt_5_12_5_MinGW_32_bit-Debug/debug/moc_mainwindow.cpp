/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../HKUST_CWS/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[23];
    char stringdata0[314];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 13), // "user_show_req"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 17), // "Requirement::Type"
QT_MOC_LITERAL(4, 44, 4), // "type"
QT_MOC_LITERAL(5, 49, 15), // "user_change_req"
QT_MOC_LITERAL(6, 65, 6), // "string"
QT_MOC_LITERAL(7, 72, 12), // "new_req_name"
QT_MOC_LITERAL(8, 85, 19), // "user_click_a_course"
QT_MOC_LITERAL(9, 105, 19), // "clicked_course_name"
QT_MOC_LITERAL(10, 125, 21), // "user_click_a_semester"
QT_MOC_LITERAL(11, 147, 9), // "Semester*"
QT_MOC_LITERAL(12, 157, 16), // "clicked_semester"
QT_MOC_LITERAL(13, 174, 20), // "user_edit_search_box"
QT_MOC_LITERAL(14, 195, 7), // "content"
QT_MOC_LITERAL(15, 203, 20), // "user_delete_a_course"
QT_MOC_LITERAL(16, 224, 11), // "course_name"
QT_MOC_LITERAL(17, 236, 8), // "semester"
QT_MOC_LITERAL(18, 245, 18), // "user_view_a_course"
QT_MOC_LITERAL(19, 264, 7), // "Course*"
QT_MOC_LITERAL(20, 272, 6), // "course"
QT_MOC_LITERAL(21, 279, 19), // "user_leave_a_course"
QT_MOC_LITERAL(22, 299, 14) // "user_click_add"

    },
    "MainWindow\0user_show_req\0\0Requirement::Type\0"
    "type\0user_change_req\0string\0new_req_name\0"
    "user_click_a_course\0clicked_course_name\0"
    "user_click_a_semester\0Semester*\0"
    "clicked_semester\0user_edit_search_box\0"
    "content\0user_delete_a_course\0course_name\0"
    "semester\0user_view_a_course\0Course*\0"
    "course\0user_leave_a_course\0user_click_add"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x08 /* Private */,
       5,    2,   67,    2, 0x08 /* Private */,
       8,    1,   72,    2, 0x08 /* Private */,
      10,    1,   75,    2, 0x08 /* Private */,
      13,    1,   78,    2, 0x08 /* Private */,
      13,    0,   81,    2, 0x28 /* Private | MethodCloned */,
      15,    2,   82,    2, 0x08 /* Private */,
      18,    1,   87,    2, 0x08 /* Private */,
      21,    0,   90,    2, 0x08 /* Private */,
      22,    0,   91,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 6,    4,    7,
    QMetaType::Void, 0x80000000 | 6,    9,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 6,   14,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 11,   16,   17,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->user_show_req((*reinterpret_cast< Requirement::Type(*)>(_a[1]))); break;
        case 1: _t->user_change_req((*reinterpret_cast< Requirement::Type(*)>(_a[1])),(*reinterpret_cast< string(*)>(_a[2]))); break;
        case 2: _t->user_click_a_course((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 3: _t->user_click_a_semester((*reinterpret_cast< Semester*(*)>(_a[1]))); break;
        case 4: _t->user_edit_search_box((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 5: _t->user_edit_search_box(); break;
        case 6: _t->user_delete_a_course((*reinterpret_cast< string(*)>(_a[1])),(*reinterpret_cast< Semester*(*)>(_a[2]))); break;
        case 7: _t->user_view_a_course((*reinterpret_cast< Course*(*)>(_a[1]))); break;
        case 8: _t->user_leave_a_course(); break;
        case 9: _t->user_click_add(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
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
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
