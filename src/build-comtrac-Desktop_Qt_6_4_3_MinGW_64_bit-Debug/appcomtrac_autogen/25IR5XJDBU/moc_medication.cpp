/****************************************************************************
** Meta object code from reading C++ file 'medication.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../comtrac/Models/medication.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'medication.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_Medication_t {
    uint offsetsAndSizes[40];
    char stringdata0[11];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[18];
    char stringdata4[18];
    char stringdata5[12];
    char stringdata6[20];
    char stringdata7[20];
    char stringdata8[18];
    char stringdata9[10];
    char stringdata10[15];
    char stringdata11[11];
    char stringdata12[14];
    char stringdata13[5];
    char stringdata14[13];
    char stringdata15[12];
    char stringdata16[13];
    char stringdata17[11];
    char stringdata18[13];
    char stringdata19[3];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Medication_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_Medication_t qt_meta_stringdata_Medication = {
    {
        QT_MOC_LITERAL(0, 10),  // "Medication"
        QT_MOC_LITERAL(11, 15),  // "medicationAdded"
        QT_MOC_LITERAL(27, 0),  // ""
        QT_MOC_LITERAL(28, 17),  // "medicationRemoved"
        QT_MOC_LITERAL(46, 17),  // "medicationUpdated"
        QT_MOC_LITERAL(64, 11),  // "nameChanged"
        QT_MOC_LITERAL(76, 19),  // "reminderTimeChanged"
        QT_MOC_LITERAL(96, 19),  // "intakePerDayChanged"
        QT_MOC_LITERAL(116, 17),  // "intakeTimeChanged"
        QT_MOC_LITERAL(134, 9),  // "idChanged"
        QT_MOC_LITERAL(144, 14),  // "readMedication"
        QT_MOC_LITERAL(159, 10),  // "medication"
        QT_MOC_LITERAL(170, 13),  // "addMedication"
        QT_MOC_LITERAL(184, 4),  // "name"
        QT_MOC_LITERAL(189, 12),  // "intakePerDay"
        QT_MOC_LITERAL(202, 11),  // "intakeTimes"
        QT_MOC_LITERAL(214, 12),  // "reminderTime"
        QT_MOC_LITERAL(227, 10),  // "intakeTime"
        QT_MOC_LITERAL(238, 12),  // "QList<QTime>"
        QT_MOC_LITERAL(251, 2)   // "id"
    },
    "Medication",
    "medicationAdded",
    "",
    "medicationRemoved",
    "medicationUpdated",
    "nameChanged",
    "reminderTimeChanged",
    "intakePerDayChanged",
    "intakeTimeChanged",
    "idChanged",
    "readMedication",
    "medication",
    "addMedication",
    "name",
    "intakePerDay",
    "intakeTimes",
    "reminderTime",
    "intakeTime",
    "QList<QTime>",
    "id"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_Medication[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       5,   94, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   74,    2, 0x06,    6 /* Public */,
       3,    0,   75,    2, 0x06,    7 /* Public */,
       4,    0,   76,    2, 0x06,    8 /* Public */,
       5,    0,   77,    2, 0x06,    9 /* Public */,
       6,    0,   78,    2, 0x06,   10 /* Public */,
       7,    0,   79,    2, 0x06,   11 /* Public */,
       8,    0,   80,    2, 0x06,   12 /* Public */,
       9,    0,   81,    2, 0x06,   13 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      10,    1,   82,    2, 0x0a,   14 /* Public */,
      12,    4,   85,    2, 0x0a,   16 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QTime, QMetaType::QTime,   13,   14,   15,   16,

 // properties: name, type, flags
      13, QMetaType::QString, 0x00015103, uint(3), 0,
      14, QMetaType::Int, 0x00015103, uint(5), 0,
      16, QMetaType::QTime, 0x00015103, uint(4), 0,
      17, 0x80000000 | 18, 0x0001510b, uint(6), 0,
      19, QMetaType::Int, 0x00015103, uint(7), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject Medication::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Medication.offsetsAndSizes,
    qt_meta_data_Medication,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_Medication_t,
        // property 'name'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'intakePerDay'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'reminderTime'
        QtPrivate::TypeAndForceComplete<QTime, std::true_type>,
        // property 'intakeTime'
        QtPrivate::TypeAndForceComplete<QList<QTime>, std::true_type>,
        // property 'id'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Medication, std::true_type>,
        // method 'medicationAdded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'medicationRemoved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'medicationUpdated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'nameChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'reminderTimeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'intakePerDayChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'intakeTimeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'idChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'readMedication'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'addMedication'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTime, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTime, std::false_type>
    >,
    nullptr
} };

void Medication::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Medication *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->medicationAdded(); break;
        case 1: _t->medicationRemoved(); break;
        case 2: _t->medicationUpdated(); break;
        case 3: _t->nameChanged(); break;
        case 4: _t->reminderTimeChanged(); break;
        case 5: _t->intakePerDayChanged(); break;
        case 6: _t->intakeTimeChanged(); break;
        case 7: _t->idChanged(); break;
        case 8: _t->readMedication((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: _t->addMedication((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QTime>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QTime>>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Medication::*)();
            if (_t _q_method = &Medication::medicationAdded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Medication::*)();
            if (_t _q_method = &Medication::medicationRemoved; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Medication::*)();
            if (_t _q_method = &Medication::medicationUpdated; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Medication::*)();
            if (_t _q_method = &Medication::nameChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Medication::*)();
            if (_t _q_method = &Medication::reminderTimeChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Medication::*)();
            if (_t _q_method = &Medication::intakePerDayChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Medication::*)();
            if (_t _q_method = &Medication::intakeTimeChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Medication::*)();
            if (_t _q_method = &Medication::idChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QTime> >(); break;
        }
    }
else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Medication *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->name(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->intakePerDay(); break;
        case 2: *reinterpret_cast< QTime*>(_v) = _t->reminderTime(); break;
        case 3: *reinterpret_cast< QList<QTime>*>(_v) = _t->intakeTime(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->id(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Medication *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setName(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setIntakePerDay(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setReminderTime(*reinterpret_cast< QTime*>(_v)); break;
        case 3: _t->setIntakeTime(*reinterpret_cast< QList<QTime>*>(_v)); break;
        case 4: _t->setId(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *Medication::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Medication::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Medication.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Medication::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Medication::medicationAdded()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Medication::medicationRemoved()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Medication::medicationUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Medication::nameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Medication::reminderTimeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Medication::intakePerDayChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Medication::intakeTimeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void Medication::idChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
