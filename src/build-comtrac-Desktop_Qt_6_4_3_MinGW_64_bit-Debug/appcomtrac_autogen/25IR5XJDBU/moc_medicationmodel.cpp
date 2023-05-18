/****************************************************************************
** Meta object code from reading C++ file 'medicationmodel.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../comtrac/Models/medicationmodel.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'medicationmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_MedicationModel_t {
    uint offsetsAndSizes[22];
    char stringdata0[16];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[4];
    char stringdata5[14];
    char stringdata6[5];
    char stringdata7[13];
    char stringdata8[13];
    char stringdata9[12];
    char stringdata10[13];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MedicationModel_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MedicationModel_t qt_meta_stringdata_MedicationModel = {
    {
        QT_MOC_LITERAL(0, 15),  // "MedicationModel"
        QT_MOC_LITERAL(16, 11),  // "updateModel"
        QT_MOC_LITERAL(28, 0),  // ""
        QT_MOC_LITERAL(29, 5),  // "getId"
        QT_MOC_LITERAL(35, 3),  // "row"
        QT_MOC_LITERAL(39, 13),  // "addMedication"
        QT_MOC_LITERAL(53, 4),  // "name"
        QT_MOC_LITERAL(58, 12),  // "intakePerDay"
        QT_MOC_LITERAL(71, 12),  // "QList<QTime>"
        QT_MOC_LITERAL(84, 11),  // "intakeTimes"
        QT_MOC_LITERAL(96, 12)   // "reminderTime"
    },
    "MedicationModel",
    "updateModel",
    "",
    "getId",
    "row",
    "addMedication",
    "name",
    "intakePerDay",
    "QList<QTime>",
    "intakeTimes",
    "reminderTime"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MedicationModel[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   32,    2, 0x0a,    1 /* Public */,
       3,    1,   33,    2, 0x0a,    2 /* Public */,
       5,    4,   36,    2, 0x0a,    4 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Int, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, 0x80000000 | 8, QMetaType::QTime,    6,    7,    9,   10,

       0        // eod
};

Q_CONSTINIT const QMetaObject MedicationModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QSqlQueryModel::staticMetaObject>(),
    qt_meta_stringdata_MedicationModel.offsetsAndSizes,
    qt_meta_data_MedicationModel,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MedicationModel_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MedicationModel, std::true_type>,
        // method 'updateModel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'getId'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'addMedication'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QList<QTime>, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTime, std::false_type>
    >,
    nullptr
} };

void MedicationModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MedicationModel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updateModel(); break;
        case 1: { int _r = _t->getId((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->addMedication((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QList<QTime>>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QTime>>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 2:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<QTime> >(); break;
            }
            break;
        }
    }
}

const QMetaObject *MedicationModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MedicationModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MedicationModel.stringdata0))
        return static_cast<void*>(this);
    return QSqlQueryModel::qt_metacast(_clname);
}

int MedicationModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSqlQueryModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
