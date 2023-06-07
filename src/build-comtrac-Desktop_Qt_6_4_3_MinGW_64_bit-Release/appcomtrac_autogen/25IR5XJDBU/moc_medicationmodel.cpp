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
    uint offsetsAndSizes[40];
    char stringdata0[16];
    char stringdata1[18];
    char stringdata2[1];
    char stringdata3[19];
    char stringdata4[24];
    char stringdata5[14];
    char stringdata6[5];
    char stringdata7[13];
    char stringdata8[13];
    char stringdata9[12];
    char stringdata10[13];
    char stringdata11[20];
    char stringdata12[12];
    char stringdata13[20];
    char stringdata14[14];
    char stringdata15[5];
    char stringdata16[17];
    char stringdata17[12];
    char stringdata18[19];
    char stringdata19[17];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MedicationModel_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MedicationModel_t qt_meta_stringdata_MedicationModel = {
    {
        QT_MOC_LITERAL(0, 15),  // "MedicationModel"
        QT_MOC_LITERAL(16, 17),  // "medicationChanged"
        QT_MOC_LITERAL(34, 0),  // ""
        QT_MOC_LITERAL(35, 18),  // "medicationsChanged"
        QT_MOC_LITERAL(54, 23),  // "singleMedicationChanged"
        QT_MOC_LITERAL(78, 13),  // "addMedication"
        QT_MOC_LITERAL(92, 4),  // "name"
        QT_MOC_LITERAL(97, 12),  // "intakePerDay"
        QT_MOC_LITERAL(110, 12),  // "QList<QTime>"
        QT_MOC_LITERAL(123, 11),  // "intakeTimes"
        QT_MOC_LITERAL(135, 12),  // "reminderTime"
        QT_MOC_LITERAL(148, 19),  // "setSingleMedication"
        QT_MOC_LITERAL(168, 11),  // "Medication*"
        QT_MOC_LITERAL(180, 19),  // "newSingleMedication"
        QT_MOC_LITERAL(200, 13),  // "setIntakeTime"
        QT_MOC_LITERAL(214, 4),  // "time"
        QT_MOC_LITERAL(219, 16),  // "deleteMedication"
        QT_MOC_LITERAL(236, 11),  // "medications"
        QT_MOC_LITERAL(248, 18),  // "QList<Medication*>"
        QT_MOC_LITERAL(267, 16)   // "singleMedication"
    },
    "MedicationModel",
    "medicationChanged",
    "",
    "medicationsChanged",
    "singleMedicationChanged",
    "addMedication",
    "name",
    "intakePerDay",
    "QList<QTime>",
    "intakeTimes",
    "reminderTime",
    "setSingleMedication",
    "Medication*",
    "newSingleMedication",
    "setIntakeTime",
    "time",
    "deleteMedication",
    "medications",
    "QList<Medication*>",
    "singleMedication"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MedicationModel[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       2,   75, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x06,    3 /* Public */,
       3,    0,   57,    2, 0x06,    4 /* Public */,
       4,    0,   58,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    4,   59,    2, 0x0a,    6 /* Public */,
      11,    1,   68,    2, 0x0a,   11 /* Public */,
      14,    1,   71,    2, 0x0a,   13 /* Public */,
      16,    0,   74,    2, 0x0a,   15 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int, 0x80000000 | 8, QMetaType::QTime,    6,    7,    9,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, QMetaType::QTime,   15,
    QMetaType::Void,

 // properties: name, type, flags
      17, 0x80000000 | 18, 0x0001510b, uint(1), 0,
      19, 0x80000000 | 12, 0x0001510b, uint(2), 0,

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
        // property 'singleMedication'
        QtPrivate::TypeAndForceComplete<Medication*, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MedicationModel, std::true_type>,
        // method 'medicationChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'medicationsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'singleMedicationChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addMedication'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QList<QTime>, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTime, std::false_type>,
        // method 'setSingleMedication'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Medication *, std::false_type>,
        // method 'setIntakeTime'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTime, std::false_type>,
        // method 'deleteMedication'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
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
        case 2: _t->singleMedicationChanged(); break;
        case 3: _t->addMedication((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QList<QTime>>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QTime>>(_a[4]))); break;
        case 4: _t->setSingleMedication((*reinterpret_cast< std::add_pointer_t<Medication*>>(_a[1]))); break;
        case 5: _t->setIntakeTime((*reinterpret_cast< std::add_pointer_t<QTime>>(_a[1]))); break;
        case 6: _t->deleteMedication(); break;
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
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Medication* >(); break;
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
        {
            using _t = void (MedicationModel::*)();
            if (_t _q_method = &MedicationModel::singleMedicationChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Medication* >(); break;
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
        case 1: *reinterpret_cast< Medication**>(_v) = _t->singleMedication(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<MedicationModel *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setMedications(*reinterpret_cast< QList<Medication*>*>(_v)); break;
        case 1: _t->setSingleMedication(*reinterpret_cast< Medication**>(_v)); break;
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
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
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

// SIGNAL 2
void MedicationModel::singleMedicationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
