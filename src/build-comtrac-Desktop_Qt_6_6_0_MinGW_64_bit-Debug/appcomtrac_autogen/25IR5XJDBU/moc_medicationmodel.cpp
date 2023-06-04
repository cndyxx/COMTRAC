/****************************************************************************
** Meta object code from reading C++ file 'medicationmodel.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../comtrac/Models/medicationmodel.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'medicationmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMedicationModelENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMedicationModelENDCLASS = QtMocHelpers::stringData(
    "MedicationModel",
    "medicationChanged",
    "",
    "medicationsChanged",
    "singleMedicationChanged",
    "updateModel",
    "addMedication",
    "name",
    "intakePerDay",
    "QList<QTime>",
    "intakeTimes",
    "reminderTime",
    "medications",
    "QList<Medication*>",
    "singleMedication"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMedicationModelENDCLASS_t {
    uint offsetsAndSizes[30];
    char stringdata0[16];
    char stringdata1[18];
    char stringdata2[1];
    char stringdata3[19];
    char stringdata4[24];
    char stringdata5[12];
    char stringdata6[14];
    char stringdata7[5];
    char stringdata8[13];
    char stringdata9[13];
    char stringdata10[12];
    char stringdata11[13];
    char stringdata12[12];
    char stringdata13[19];
    char stringdata14[17];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMedicationModelENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMedicationModelENDCLASS_t qt_meta_stringdata_CLASSMedicationModelENDCLASS = {
    {
        QT_MOC_LITERAL(0, 15),  // "MedicationModel"
        QT_MOC_LITERAL(16, 17),  // "medicationChanged"
        QT_MOC_LITERAL(34, 0),  // ""
        QT_MOC_LITERAL(35, 18),  // "medicationsChanged"
        QT_MOC_LITERAL(54, 23),  // "singleMedicationChanged"
        QT_MOC_LITERAL(78, 11),  // "updateModel"
        QT_MOC_LITERAL(90, 13),  // "addMedication"
        QT_MOC_LITERAL(104, 4),  // "name"
        QT_MOC_LITERAL(109, 12),  // "intakePerDay"
        QT_MOC_LITERAL(122, 12),  // "QList<QTime>"
        QT_MOC_LITERAL(135, 11),  // "intakeTimes"
        QT_MOC_LITERAL(147, 12),  // "reminderTime"
        QT_MOC_LITERAL(160, 11),  // "medications"
        QT_MOC_LITERAL(172, 18),  // "QList<Medication*>"
        QT_MOC_LITERAL(191, 16)   // "singleMedication"
    },
    "MedicationModel",
    "medicationChanged",
    "",
    "medicationsChanged",
    "singleMedicationChanged",
    "updateModel",
    "addMedication",
    "name",
    "intakePerDay",
    "QList<QTime>",
    "intakeTimes",
    "reminderTime",
    "medications",
    "QList<Medication*>",
    "singleMedication"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMedicationModelENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       2,   57, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x06,    3 /* Public */,
       3,    0,   45,    2, 0x06,    4 /* Public */,
       4,    0,   46,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   47,    2, 0x0a,    6 /* Public */,
       6,    4,   48,    2, 0x0a,    7 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, 0x80000000 | 9, QMetaType::QTime,    7,    8,   10,   11,

 // properties: name, type, flags
      12, 0x80000000 | 13, 0x0001510b, uint(1), 0,
      14, 0x80000000 | 13, 0x0001510b, uint(2), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject MedicationModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QSqlQueryModel::staticMetaObject>(),
    qt_meta_stringdata_CLASSMedicationModelENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMedicationModelENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMedicationModelENDCLASS_t,
        // property 'medications'
        QtPrivate::TypeAndForceComplete<QList<Medication*>, std::true_type>,
        // property 'singleMedication'
        QtPrivate::TypeAndForceComplete<QList<Medication*>, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MedicationModel, std::true_type>,
        // method 'medicationChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'medicationsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'singleMedicationChanged'
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
        case 2: _t->singleMedicationChanged(); break;
        case 3: _t->updateModel(); break;
        case 4: _t->addMedication((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QList<QTime>>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QTime>>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 4:
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
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<Medication*> >(); break;
        }
    }  else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<MedicationModel *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QList<Medication*>*>(_v) = _t->medications(); break;
        case 1: *reinterpret_cast< QList<Medication*>*>(_v) = _t->singleMedication(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<MedicationModel *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setMedications(*reinterpret_cast< QList<Medication*>*>(_v)); break;
        case 1: _t->setSingleMedication(*reinterpret_cast< QList<Medication*>*>(_v)); break;
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
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMedicationModelENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QSqlQueryModel::qt_metacast(_clname);
}

int MedicationModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSqlQueryModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
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
