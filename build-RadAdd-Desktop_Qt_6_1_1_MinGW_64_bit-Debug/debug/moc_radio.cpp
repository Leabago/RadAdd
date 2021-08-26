/****************************************************************************
** Meta object code from reading C++ file 'radio.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../RadAdd/radio.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'radio.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Radio_t {
    const uint offsetsAndSize[30];
    char stringdata0[145];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Radio_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Radio_t qt_meta_stringdata_Radio = {
    {
QT_MOC_LITERAL(0, 5), // "Radio"
QT_MOC_LITERAL(6, 11), // "linkChanged"
QT_MOC_LITERAL(18, 0), // ""
QT_MOC_LITERAL(19, 11), // "nameChanged"
QT_MOC_LITERAL(31, 11), // "iconChanged"
QT_MOC_LITERAL(43, 16), // "listeningChanged"
QT_MOC_LITERAL(60, 12), // "genreChanged"
QT_MOC_LITERAL(73, 15), // "favoriteChanged"
QT_MOC_LITERAL(89, 15), // "nameChangedSlot"
QT_MOC_LITERAL(105, 4), // "link"
QT_MOC_LITERAL(110, 4), // "name"
QT_MOC_LITERAL(115, 4), // "icon"
QT_MOC_LITERAL(120, 9), // "listening"
QT_MOC_LITERAL(130, 5), // "genre"
QT_MOC_LITERAL(136, 8) // "favorite"

    },
    "Radio\0linkChanged\0\0nameChanged\0"
    "iconChanged\0listeningChanged\0genreChanged\0"
    "favoriteChanged\0nameChangedSlot\0link\0"
    "name\0icon\0listening\0genre\0favorite"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Radio[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       6,   63, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x06,    6 /* Public */,
       3,    0,   57,    2, 0x06,    7 /* Public */,
       4,    0,   58,    2, 0x06,    8 /* Public */,
       5,    0,   59,    2, 0x06,    9 /* Public */,
       6,    0,   60,    2, 0x06,   10 /* Public */,
       7,    0,   61,    2, 0x06,   11 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    0,   62,    2, 0x0a,   12 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

 // properties: name, type, flags
       9, QMetaType::QString, 0x00015103, uint(0), 0,
      10, QMetaType::QString, 0x00015103, uint(1), 0,
      11, QMetaType::QString, 0x00015103, uint(2), 0,
      12, QMetaType::UInt, 0x00015103, uint(3), 0,
      13, QMetaType::QStringList, 0x00015103, uint(4), 0,
      14, QMetaType::Bool, 0x00015103, uint(5), 0,

       0        // eod
};

void Radio::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Radio *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->linkChanged(); break;
        case 1: _t->nameChanged(); break;
        case 2: _t->iconChanged(); break;
        case 3: _t->listeningChanged(); break;
        case 4: _t->genreChanged(); break;
        case 5: _t->favoriteChanged(); break;
        case 6: _t->nameChangedSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Radio::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Radio::linkChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Radio::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Radio::nameChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Radio::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Radio::iconChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Radio::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Radio::listeningChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Radio::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Radio::genreChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Radio::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Radio::favoriteChanged)) {
                *result = 5;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Radio *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->link(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->name(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->icon(); break;
        case 3: *reinterpret_cast< uint*>(_v) = _t->listening(); break;
        case 4: *reinterpret_cast< QList<QString>*>(_v) = _t->genre(); break;
        case 5: *reinterpret_cast< bool*>(_v) = _t->favorite(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Radio *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setLink(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setName(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setIcon(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setListening(*reinterpret_cast< uint*>(_v)); break;
        case 4: _t->setGenre(*reinterpret_cast< QList<QString>*>(_v)); break;
        case 5: _t->setFavorite(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
#endif // QT_NO_PROPERTIES
    (void)_a;
}

const QMetaObject Radio::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Radio.offsetsAndSize,
    qt_meta_data_Radio,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Radio_t
, QtPrivate::TypeAndForceComplete<QString, std::true_type>, QtPrivate::TypeAndForceComplete<QString, std::true_type>, QtPrivate::TypeAndForceComplete<QString, std::true_type>, QtPrivate::TypeAndForceComplete<uint, std::true_type>, QtPrivate::TypeAndForceComplete<QList<QString>, std::true_type>, QtPrivate::TypeAndForceComplete<bool, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Radio::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Radio::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Radio.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Radio::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Radio::linkChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Radio::nameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Radio::iconChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Radio::listeningChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Radio::genreChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Radio::favoriteChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
