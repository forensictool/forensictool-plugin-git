/****************************************************************************
** Meta object code from reading C++ file 'window.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/ui/window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GitSearchRepoWindow_t {
    QByteArrayData data[6];
    char stringdata0[82];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GitSearchRepoWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GitSearchRepoWindow_t qt_meta_stringdata_GitSearchRepoWindow = {
    {
QT_MOC_LITERAL(0, 0, 19), // "GitSearchRepoWindow"
QT_MOC_LITERAL(1, 20, 11), // "onUpdateKFW"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 7), // "kfwlist"
QT_MOC_LITERAL(4, 41, 17), // "btnGenerateSignal"
QT_MOC_LITERAL(5, 59, 22) // "btnRunGeneticAlgorithm"

    },
    "GitSearchRepoWindow\0onUpdateKFW\0\0"
    "kfwlist\0btnGenerateSignal\0"
    "btnRunGeneticAlgorithm"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GitSearchRepoWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x0a /* Public */,
       4,    0,   32,    2, 0x08 /* Private */,
       5,    0,   33,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GitSearchRepoWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GitSearchRepoWindow *_t = static_cast<GitSearchRepoWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onUpdateKFW((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->btnGenerateSignal(); break;
        case 2: _t->btnRunGeneticAlgorithm(); break;
        default: ;
        }
    }
}

const QMetaObject GitSearchRepoWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_GitSearchRepoWindow.data,
      qt_meta_data_GitSearchRepoWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GitSearchRepoWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GitSearchRepoWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GitSearchRepoWindow.stringdata0))
        return static_cast<void*>(const_cast< GitSearchRepoWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int GitSearchRepoWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
struct qt_meta_stringdata_GitSearchRepoWindowThread_t {
    QByteArrayData data[4];
    char stringdata0[45];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GitSearchRepoWindowThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GitSearchRepoWindowThread_t qt_meta_stringdata_GitSearchRepoWindowThread = {
    {
QT_MOC_LITERAL(0, 0, 25), // "GitSearchRepoWindowThread"
QT_MOC_LITERAL(1, 26, 9), // "updateKFW"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 7) // "kfwlist"

    },
    "GitSearchRepoWindowThread\0updateKFW\0"
    "\0kfwlist"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GitSearchRepoWindowThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

       0        // eod
};

void GitSearchRepoWindowThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GitSearchRepoWindowThread *_t = static_cast<GitSearchRepoWindowThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateKFW((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GitSearchRepoWindowThread::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GitSearchRepoWindowThread::updateKFW)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject GitSearchRepoWindowThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_GitSearchRepoWindowThread.data,
      qt_meta_data_GitSearchRepoWindowThread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GitSearchRepoWindowThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GitSearchRepoWindowThread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GitSearchRepoWindowThread.stringdata0))
        return static_cast<void*>(const_cast< GitSearchRepoWindowThread*>(this));
    return QThread::qt_metacast(_clname);
}

int GitSearchRepoWindowThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void GitSearchRepoWindowThread::updateKFW(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
