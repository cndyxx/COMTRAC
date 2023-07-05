/****************************************************************************
** Meta object code from reading C++ file 'symptommodel.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../comtrac/Models/symptommodel.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'symptommodel.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_SymptomModel_t {
    uint offsetsAndSizes[74];
    char stringdata0[13];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[21];
    char stringdata4[19];
    char stringdata5[23];
    char stringdata6[20];
    char stringdata7[22];
    char stringdata8[14];
    char stringdata9[14];
    char stringdata10[5];
    char stringdata11[10];
    char stringdata12[10];
    char stringdata13[9];
    char stringdata14[14];
    char stringdata15[6];
    char stringdata16[9];
    char stringdata17[5];
    char stringdata18[12];
    char stringdata19[10];
    char stringdata20[10];
    char stringdata21[17];
    char stringdata22[9];
    char stringdata23[17];
    char stringdata24[18];
    char stringdata25[18];
    char stringdata26[20];
    char stringdata27[5];
    char stringdata28[11];
    char stringdata29[9];
    char stringdata30[16];
    char stringdata31[14];
    char stringdata32[12];
    char stringdata33[16];
    char stringdata34[13];
    char stringdata35[13];
    char stringdata36[15];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_SymptomModel_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_SymptomModel_t qt_meta_stringdata_SymptomModel = {
    {
        QT_MOC_LITERAL(0, 12),  // "SymptomModel"
        QT_MOC_LITERAL(13, 15),  // "symptomsChanged"
        QT_MOC_LITERAL(29, 0),  // ""
        QT_MOC_LITERAL(30, 20),  // "singleSymptomChanged"
        QT_MOC_LITERAL(51, 18),  // "daySymptomsChanged"
        QT_MOC_LITERAL(70, 22),  // "symptomsOfMonthChanged"
        QT_MOC_LITERAL(93, 19),  // "weekSymptomsChanged"
        QT_MOC_LITERAL(113, 21),  // "symptomEntriesChanged"
        QT_MOC_LITERAL(135, 13),  // "deleteSymptom"
        QT_MOC_LITERAL(149, 13),  // "updateSymptom"
        QT_MOC_LITERAL(163, 4),  // "name"
        QT_MOC_LITERAL(168, 9),  // "intensity"
        QT_MOC_LITERAL(178, 9),  // "frequency"
        QT_MOC_LITERAL(188, 8),  // "duration"
        QT_MOC_LITERAL(197, 13),  // "getEntryDates"
        QT_MOC_LITERAL(211, 5),  // "month"
        QT_MOC_LITERAL(217, 8),  // "findDate"
        QT_MOC_LITERAL(226, 4),  // "date"
        QT_MOC_LITERAL(231, 11),  // "addSymptoms"
        QT_MOC_LITERAL(243, 9),  // "entryDate"
        QT_MOC_LITERAL(253, 9),  // "entryTime"
        QT_MOC_LITERAL(263, 16),  // "setSingleSymptom"
        QT_MOC_LITERAL(280, 8),  // "Symptom*"
        QT_MOC_LITERAL(289, 16),  // "newSingleSymptom"
        QT_MOC_LITERAL(306, 17),  // "getSymptomsOfDate"
        QT_MOC_LITERAL(324, 17),  // "getSymptomEntries"
        QT_MOC_LITERAL(342, 19),  // "getCalendarWeekDate"
        QT_MOC_LITERAL(362, 4),  // "year"
        QT_MOC_LITERAL(367, 10),  // "weekNumber"
        QT_MOC_LITERAL(378, 8),  // "symptoms"
        QT_MOC_LITERAL(387, 15),  // "QList<Symptom*>"
        QT_MOC_LITERAL(403, 13),  // "singleSymptom"
        QT_MOC_LITERAL(417, 11),  // "daySymptoms"
        QT_MOC_LITERAL(429, 15),  // "symptomsOfMonth"
        QT_MOC_LITERAL(445, 12),  // "QList<QDate>"
        QT_MOC_LITERAL(458, 12),  // "weekSymptoms"
        QT_MOC_LITERAL(471, 14)   // "symptomEntries"
    },
    "SymptomModel",
    "symptomsChanged",
    "",
    "singleSymptomChanged",
    "daySymptomsChanged",
    "symptomsOfMonthChanged",
    "weekSymptomsChanged",
    "symptomEntriesChanged",
    "deleteSymptom",
    "updateSymptom",
    "name",
    "intensity",
    "frequency",
    "duration",
    "getEntryDates",
    "month",
    "findDate",
    "date",
    "addSymptoms",
    "entryDate",
    "entryTime",
    "setSingleSymptom",
    "Symptom*",
    "newSingleSymptom",
    "getSymptomsOfDate",
    "getSymptomEntries",
    "getCalendarWeekDate",
    "year",
    "weekNumber",
    "symptoms",
    "QList<Symptom*>",
    "singleSymptom",
    "daySymptoms",
    "symptomsOfMonth",
    "QList<QDate>",
    "weekSymptoms",
    "symptomEntries"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_SymptomModel[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       6,  153, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  104,    2, 0x06,    7 /* Public */,
       3,    0,  105,    2, 0x06,    8 /* Public */,
       4,    0,  106,    2, 0x06,    9 /* Public */,
       5,    0,  107,    2, 0x06,   10 /* Public */,
       6,    0,  108,    2, 0x06,   11 /* Public */,
       7,    0,  109,    2, 0x06,   12 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    0,  110,    2, 0x0a,   13 /* Public */,
       9,    4,  111,    2, 0x0a,   14 /* Public */,
      14,    1,  120,    2, 0x0a,   19 /* Public */,
      16,    1,  123,    2, 0x0a,   21 /* Public */,
      18,    6,  126,    2, 0x0a,   23 /* Public */,
      21,    1,  139,    2, 0x0a,   30 /* Public */,
      24,    1,  142,    2, 0x0a,   32 /* Public */,
      25,    1,  145,    2, 0x0a,   34 /* Public */,
      26,    2,  148,    2, 0x0a,   36 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString,   10,   11,   12,   13,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Bool, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString,   10,   11,   12,   13,   19,   20,
    QMetaType::Void, 0x80000000 | 22,   23,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   27,   28,

 // properties: name, type, flags
      29, 0x80000000 | 30, 0x0001510b, uint(0), 0,
      31, 0x80000000 | 22, 0x0001510b, uint(1), 0,
      32, 0x80000000 | 30, 0x0001510b, uint(2), 0,
      33, 0x80000000 | 34, 0x0001510b, uint(3), 0,
      35, 0x80000000 | 30, 0x0001510b, uint(4), 0,
      36, 0x80000000 | 30, 0x0001510b, uint(5), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject SymptomModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QSqlQueryModel::staticMetaObject>(),
    qt_meta_stringdata_SymptomModel.offsetsAndSizes,
    qt_meta_data_SymptomModel,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_SymptomModel_t,
        // property 'symptoms'
        QtPrivate::TypeAndForceComplete<QList<Symptom*>, std::true_type>,
        // property 'singleSymptom'
        QtPrivate::TypeAndForceComplete<Symptom*, std::true_type>,
        // property 'daySymptoms'
        QtPrivate::TypeAndForceComplete<QList<Symptom*>, std::true_type>,
        // property 'symptomsOfMonth'
        QtPrivate::TypeAndForceComplete<QList<QDate>, std::true_type>,
        // property 'weekSymptoms'
        QtPrivate::TypeAndForceComplete<QList<Symptom*>, std::true_type>,
        // property 'symptomEntries'
        QtPrivate::TypeAndForceComplete<QList<Symptom*>, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SymptomModel, std::true_type>,
        // method 'symptomsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'singleSymptomChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'daySymptomsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'symptomsOfMonthChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'weekSymptomsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'symptomEntriesChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'deleteSymptom'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateSymptom'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getEntryDates'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'findDate'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'addSymptoms'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'setSingleSymptom'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Symptom *, std::false_type>,
        // method 'getSymptomsOfDate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getSymptomEntries'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getCalendarWeekDate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void SymptomModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SymptomModel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->symptomsChanged(); break;
        case 1: _t->singleSymptomChanged(); break;
        case 2: _t->daySymptomsChanged(); break;
        case 3: _t->symptomsOfMonthChanged(); break;
        case 4: _t->weekSymptomsChanged(); break;
        case 5: _t->symptomEntriesChanged(); break;
        case 6: _t->deleteSymptom(); break;
        case 7: _t->updateSymptom((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4]))); break;
        case 8: _t->getEntryDates((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: { bool _r = _t->findDate((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 10: _t->addSymptoms((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[6]))); break;
        case 11: _t->setSingleSymptom((*reinterpret_cast< std::add_pointer_t<Symptom*>>(_a[1]))); break;
        case 12: _t->getSymptomsOfDate((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 13: _t->getSymptomEntries((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 14: _t->getCalendarWeekDate((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Symptom* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SymptomModel::*)();
            if (_t _q_method = &SymptomModel::symptomsChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SymptomModel::*)();
            if (_t _q_method = &SymptomModel::singleSymptomChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SymptomModel::*)();
            if (_t _q_method = &SymptomModel::daySymptomsChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SymptomModel::*)();
            if (_t _q_method = &SymptomModel::symptomsOfMonthChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (SymptomModel::*)();
            if (_t _q_method = &SymptomModel::weekSymptomsChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (SymptomModel::*)();
            if (_t _q_method = &SymptomModel::symptomEntriesChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QDate> >(); break;
        case 5:
        case 4:
        case 2:
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<Symptom*> >(); break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Symptom* >(); break;
        }
    }
else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<SymptomModel *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QList<Symptom*>*>(_v) = _t->symptoms(); break;
        case 1: *reinterpret_cast< Symptom**>(_v) = _t->singleSymptom(); break;
        case 2: *reinterpret_cast< QList<Symptom*>*>(_v) = _t->daySymptoms(); break;
        case 3: *reinterpret_cast< QList<QDate>*>(_v) = _t->symptomsOfMonth(); break;
        case 4: *reinterpret_cast< QList<Symptom*>*>(_v) = _t->weekSymptoms(); break;
        case 5: *reinterpret_cast< QList<Symptom*>*>(_v) = _t->symptomEntries(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<SymptomModel *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setSymptoms(*reinterpret_cast< QList<Symptom*>*>(_v)); break;
        case 1: _t->setSingleSymptom(*reinterpret_cast< Symptom**>(_v)); break;
        case 2: _t->setDaySymptoms(*reinterpret_cast< QList<Symptom*>*>(_v)); break;
        case 3: _t->setSymptomsOfMonth(*reinterpret_cast< QList<QDate>*>(_v)); break;
        case 4: _t->setWeekSymptoms(*reinterpret_cast< QList<Symptom*>*>(_v)); break;
        case 5: _t->setSymptomEntries(*reinterpret_cast< QList<Symptom*>*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *SymptomModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SymptomModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SymptomModel.stringdata0))
        return static_cast<void*>(this);
    return QSqlQueryModel::qt_metacast(_clname);
}

int SymptomModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSqlQueryModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void SymptomModel::symptomsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SymptomModel::singleSymptomChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void SymptomModel::daySymptomsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void SymptomModel::symptomsOfMonthChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void SymptomModel::weekSymptomsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void SymptomModel::symptomEntriesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
