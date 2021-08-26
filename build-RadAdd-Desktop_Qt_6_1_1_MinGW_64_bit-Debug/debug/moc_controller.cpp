/****************************************************************************
** Meta object code from reading C++ file 'controller.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../RadAdd/controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Controller_t {
    const uint offsetsAndSize[42];
    char stringdata0[238];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Controller_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Controller_t qt_meta_stringdata_Controller = {
    {
QT_MOC_LITERAL(0, 10), // "Controller"
QT_MOC_LITERAL(11, 9), // "sentToQml"
QT_MOC_LITERAL(21, 0), // ""
QT_MOC_LITERAL(22, 25), // "removeFromFavoriteByIndex"
QT_MOC_LITERAL(48, 5), // "index"
QT_MOC_LITERAL(54, 17), // "favoriteLinkExist"
QT_MOC_LITERAL(72, 4), // "link"
QT_MOC_LITERAL(77, 12), // "addToFavoite"
QT_MOC_LITERAL(90, 7), // "radioId"
QT_MOC_LITERAL(98, 15), // "addToFavoriteDB"
QT_MOC_LITERAL(114, 18), // "removeFromFavorite"
QT_MOC_LITERAL(133, 20), // "removeFromFavoriteDB"
QT_MOC_LITERAL(154, 7), // "addName"
QT_MOC_LITERAL(162, 3), // "val"
QT_MOC_LITERAL(166, 8), // "getRadio"
QT_MOC_LITERAL(175, 6), // "Radio*"
QT_MOC_LITERAL(182, 7), // "getName"
QT_MOC_LITERAL(190, 12), // "prepearGenre"
QT_MOC_LITERAL(203, 11), // "getGenreAll"
QT_MOC_LITERAL(215, 8), // "MyModel*"
QT_MOC_LITERAL(224, 13) // "getGenreToAdd"

    },
    "Controller\0sentToQml\0\0removeFromFavoriteByIndex\0"
    "index\0favoriteLinkExist\0link\0addToFavoite\0"
    "radioId\0addToFavoriteDB\0removeFromFavorite\0"
    "removeFromFavoriteDB\0addName\0val\0"
    "getRadio\0Radio*\0getName\0prepearGenre\0"
    "getGenreAll\0MyModel*\0getGenreToAdd"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Controller[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   92,    2, 0x06,    0 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    1,   93,    2, 0x0a,    1 /* Public */,
       5,    1,   96,    2, 0x0a,    3 /* Public */,
       7,    1,   99,    2, 0x0a,    5 /* Public */,
       9,    1,  102,    2, 0x0a,    7 /* Public */,
      10,    1,  105,    2, 0x0a,    9 /* Public */,
      11,    1,  108,    2, 0x0a,   11 /* Public */,
      12,    2,  111,    2, 0x0a,   13 /* Public */,
      14,    1,  116,    2, 0x0a,   16 /* Public */,
      16,    1,  119,    2, 0x0a,   18 /* Public */,
      17,    0,  122,    2, 0x0a,   20 /* Public */,
      18,    0,  123,    2, 0x0a,   21 /* Public */,
      20,    0,  124,    2, 0x0a,   22 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Bool, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Bool, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Bool, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,   13,
    0x80000000 | 15, QMetaType::QString,    6,
    QMetaType::QString, QMetaType::QString,    6,
    QMetaType::Void,
    0x80000000 | 19,
    QMetaType::QStringList,

       0        // eod
};

void Controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Controller *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sentToQml(); break;
        case 1: _t->removeFromFavoriteByIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: { bool _r = _t->favoriteLinkExist((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->addToFavoite((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: { bool _r = _t->addToFavoriteDB((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->removeFromFavorite((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: { bool _r = _t->removeFromFavoriteDB((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->addName((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 8: { Radio* _r = _t->getRadio((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< Radio**>(_a[0]) = std::move(_r); }  break;
        case 9: { QString _r = _t->getName((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 10: _t->prepearGenre(); break;
        case 11: { MyModel* _r = _t->getGenreAll();
            if (_a[0]) *reinterpret_cast< MyModel**>(_a[0]) = std::move(_r); }  break;
        case 12: { QList<QString> _r = _t->getGenreToAdd();
            if (_a[0]) *reinterpret_cast< QList<QString>*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Controller::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::sentToQml)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Controller::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Controller.offsetsAndSize,
    qt_meta_data_Controller,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Controller_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<const QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<Radio *, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<MyModel *, std::false_type>, QtPrivate::TypeAndForceComplete<QList<QString>, std::false_type>


>,
    nullptr
} };


const QMetaObject *Controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Controller::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Controller.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void Controller::sentToQml()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
