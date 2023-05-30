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
    uint offsetsAndSizes[26];
    char stringdata0[16];
    char stringdata1[18];
    char stringdata2[1];
    char stringdata3[19];
    char stringdata4[12];
    char stringdata5[14];
    char stringdata6[5];
    char stringdata7[13];
    char stringdata8[13];
    char stringdata9[12];
    char stringdata10[13];
    char stringdata11[12];
    char stringdata12[19];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MedicationModel_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MedicationModel_t qt_meta_stringdata_MedicationModel = {
    {
        QT_MOC_LITERAL(0, 15),  // "MedicationModel"
        QT_MOC_LITERAL(16, 17),  // "medicationChanged"
        QT_MOC_LITERAL(34, 0),  // ""
        QT_MOC_LITERAL(35, 18),  // "medicationsChanged"
        QT_MOC_LITERAL(54, 11),  // "updateModel"
        QT_MOC_LITERAL(66, 13),  // "addMedication"
        QT_MOC_LITERAL(80, 4),  // "name"
        QT_MOC_LITERAL(85, 12),  // "intakePerDay"
        QT_MOC_LITERAL(98, 12),  // "QList<QTime>"
        QT_MOC_LITERAL(111, 11),  // "intakeTimes"
        QT_MOC_LITERAL(123, 12),  // "reminderTime"
        QT_MOC_LITERAL(136, 11),  // "medications"
        QT_MOC_LITERAL(148, 18)   // "QList<Medication*>"
    },
    "MedicationModel",
    "medicationChanged",
    "",
    "medicationsChanged",
    "updateModel",
    "addMedication",
    "name",
    "intakePerDay",
    "QList<QTime>",
    "intakeTimes",
    "reminderTime",
    "medications",
    "QList<Medication*>"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MedicationModel[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       1,   50, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   38,    2, 0x06,    2 /* Public */,
       3,    0,   39,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   40,    2, 0x0a,    4 /* Public */,
       5,    4,   41,    2, 0x0a,    5 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, 0x80000000 | 8, QMetaType::QTime,    6,    7,    9,   10,

 // properties: name, type, flags
      11, 0x80000000 | 12, 0x0001510b, uint(1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject MedicationModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QSqlQueryModel::staticMetaObject>(),
    qt_meta_stringdata_MedicationModel.offsetsAndSizes,
    qt_meta_data_MedicationModel,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MedicationModel_t,
        // property 'medications'
        QtPrivate::TypeAndForceComplete<QList<Medication*>, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MedicationModel, std::true_type>,
        // method 'medicationChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'medicationsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateModel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
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
        case 0: _t->medicationChanged(); break;
        case 1: _t->medicationsChanged(); break;
        case 2: _t->updateModel(); break;
        case 3: _t->addMedication((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QList<QTime>>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QTime>>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 2:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<QTime> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MedicationModel::*)();
            if (_t _q_method = &MedicationModel::medicationChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MedicationModel::*)();
            if (_t _q_method = &MedicationModel::medicationsChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<Medication*> >(); break;
        }
    }
else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<MedicationModel *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QList<Medication*>*>(_v) = _t->medications(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<MedicationModel *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setMedications(*reinterpret_cast< QList<Medication*>*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
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
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void MedicationModel::medicationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MedicationModel::medicationsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
