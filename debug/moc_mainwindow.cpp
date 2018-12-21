/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[23];
    char stringdata0[381];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 12), // "dataReceived"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 7), // "qbArray"
QT_MOC_LITERAL(4, 33, 22), // "on_loginButton_clicked"
QT_MOC_LITERAL(5, 56, 17), // "close_main_window"
QT_MOC_LITERAL(6, 74, 27), // "on_runServerButton_released"
QT_MOC_LITERAL(7, 102, 27), // "on_runClientButton_released"
QT_MOC_LITERAL(8, 130, 24), // "on_logoutButton_released"
QT_MOC_LITERAL(9, 155, 25), // "on_receiveButton_released"
QT_MOC_LITERAL(10, 181, 23), // "on_checkButton_released"
QT_MOC_LITERAL(11, 205, 22), // "on_sendButton_released"
QT_MOC_LITERAL(12, 228, 22), // "on_statButton_released"
QT_MOC_LITERAL(13, 251, 13), // "connectToHost"
QT_MOC_LITERAL(14, 265, 4), // "host"
QT_MOC_LITERAL(15, 270, 9), // "writeData"
QT_MOC_LITERAL(16, 280, 4), // "data"
QT_MOC_LITERAL(17, 285, 13), // "newConnection"
QT_MOC_LITERAL(18, 299, 12), // "disconnected"
QT_MOC_LITERAL(19, 312, 9), // "readyRead"
QT_MOC_LITERAL(20, 322, 17), // "handleStateChange"
QT_MOC_LITERAL(21, 340, 28), // "QAbstractSocket::SocketState"
QT_MOC_LITERAL(22, 369, 11) // "socketState"

    },
    "MainWindow\0dataReceived\0\0qbArray\0"
    "on_loginButton_clicked\0close_main_window\0"
    "on_runServerButton_released\0"
    "on_runClientButton_released\0"
    "on_logoutButton_released\0"
    "on_receiveButton_released\0"
    "on_checkButton_released\0on_sendButton_released\0"
    "on_statButton_released\0connectToHost\0"
    "host\0writeData\0data\0newConnection\0"
    "disconnected\0readyRead\0handleStateChange\0"
    "QAbstractSocket::SocketState\0socketState"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   97,    2, 0x08 /* Private */,
       5,    0,   98,    2, 0x08 /* Private */,
       6,    0,   99,    2, 0x08 /* Private */,
       7,    0,  100,    2, 0x08 /* Private */,
       8,    0,  101,    2, 0x08 /* Private */,
       9,    0,  102,    2, 0x08 /* Private */,
      10,    0,  103,    2, 0x08 /* Private */,
      11,    0,  104,    2, 0x08 /* Private */,
      12,    0,  105,    2, 0x08 /* Private */,
      13,    1,  106,    2, 0x08 /* Private */,
      15,    1,  109,    2, 0x08 /* Private */,
      17,    0,  112,    2, 0x08 /* Private */,
      18,    0,  113,    2, 0x08 /* Private */,
      19,    0,  114,    2, 0x08 /* Private */,
      20,    1,  115,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,

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
    QMetaType::Bool, QMetaType::QString,   14,
    QMetaType::Bool, QMetaType::QByteArray,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 21,   22,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dataReceived((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->on_loginButton_clicked(); break;
        case 2: _t->close_main_window(); break;
        case 3: _t->on_runServerButton_released(); break;
        case 4: _t->on_runClientButton_released(); break;
        case 5: _t->on_logoutButton_released(); break;
        case 6: _t->on_receiveButton_released(); break;
        case 7: _t->on_checkButton_released(); break;
        case 8: _t->on_sendButton_released(); break;
        case 9: _t->on_statButton_released(); break;
        case 10: { bool _r = _t->connectToHost((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 11: { bool _r = _t->writeData((*reinterpret_cast< QByteArray(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 12: _t->newConnection(); break;
        case 13: _t->disconnected(); break;
        case 14: _t->readyRead(); break;
        case 15: _t->handleStateChange((*reinterpret_cast< QAbstractSocket::SocketState(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 15:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketState >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::dataReceived)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::dataReceived(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
