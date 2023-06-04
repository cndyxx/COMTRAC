/****************************************************************************
** Meta object code from reading C++ file 'symptommodel.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../comtrac/Models/symptommodel.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'symptommodel.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSSymptomModelENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSSymptomModelENDCLASS = QtMocHelpers::stringData(
    "SymptomModel",
    "symptomsChanged",
    "",
    "singleSymptomChanged",
    "daySymptomsChanged",
    "symptomsOfMonthChanged",
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
    "getSymptoms",
    "setSymptoms",
    "entryDate",
    "entryTime",
    "setSingleSymptom",
    "Symptom*",
    "newSingleSymptom",
    "getSymptomsOfDate",
    "symptoms",
    "QList<Symptom*>",
    "singleSymptom",
    "daySymptoms",
    "symptomsOfMonth",
    "QList<QDate>"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSSymptomModelENDCLASS_t {
    uint offsetsAndSizes[60];
    char stringdata0[13];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[21];
    char stringdata4[19];
    char stringdata5[23];
    char stringdata6[14];
    char stringdata7[14];
    char stringdata8[5];
    char stringdata9[10];
    char stringdata10[10];
    char stringdata11[9];
    char stringdata12[14];
    char stringdata13[6];
    char stringdata14[9];
    char stringdata15[5];
    char stringdata16[12];
    char stringdata17[12];
    char stringdata18[10];
    char stringdata19[10];
    char stringdata20[17];
    char stringdata21[9];
    char stringdata22[17];
    char stringdata23[18];
    char stringdata24[9];
    char stringdata25[16];
    char stringdata26[14];
    char stringdata27[12];
    char stringdata28[16];
    char stringdata29[13];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSSymptomModelENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSSymptomModelENDCLASS_t qt_meta_stringdata_CLASSSymptomModelENDCLASS = {
    {
        QT_MOC_LITERAL(0, 12),  // "SymptomModel"
        QT_MOC_LITERAL(13, 15),  // "symptomsChanged"
        QT_MOC_LITERAL(29, 0),  // ""
        QT_MOC_LITERAL(30, 20),  // "singleSymptomChanged"
        QT_MOC_LITERAL(51, 18),  // "daySymptomsChanged"
        QT_MOC_LITERAL(70, 22),  // "symptomsOfMonthChanged"
        QT_MOC_LITERAL(93, 13),  // "deleteSymptom"
        QT_MOC_LITERAL(107, 13),  // "updateSymptom"
        QT_MOC_LITERAL(121, 4),  // "name"
        QT_MOC_LITERAL(126, 9),  // "intensity"
        QT_MOC_LITERAL(136, 9),  // "frequency"
        QT_MOC_LITERAL(146, 8),  // "duration"
        QT_MOC_LITERAL(155, 13),  // "getEntryDates"
        QT_MOC_LITERAL(169, 5),  // "month"
        QT_MOC_LITERAL(175, 8),  // "findDate"
        QT_MOC_LITERAL(184, 4),  // "date"
        QT_MOC_LITERAL(189, 11),  // "getSymptoms"
        QT_MOC_LITERAL(201, 11),  // "setSymptoms"
        QT_MOC_LITERAL(213, 9),  // "entryDate"
        QT_MOC_LITERAL(223, 9),  // "entryTime"
        QT_MOC_LITERAL(233, 16),  // "setSingleSymptom"
        QT_MOC_LITERAL(250, 8),  // "Symptom*"
        QT_MOC_LITERAL(259, 16),  // "newSingleSymptom"
        QT_MOC_LITERAL(276, 17),  // "getSymptomsOfDate"
        QT_MOC_LITERAL(294, 8),  // "symptoms"
        QT_MOC_LITERAL(303, 15),  // "QList<Symptom*>"
        QT_MOC_LITERAL(319, 13),  // "singleSymptom"
        QT_MOC_LITERAL(333, 11),  // "daySymptoms"
        QT_MOC_LITERAL(345, 15),  // "symptomsOfMonth"
        QT_MOC_LITERAL(361, 12)   // "QList<QDate>"
    },
    "SymptomModel",
    "symptomsChanged",
    "",
    "singleSymptomChanged",
    "daySymptomsChanged",
    "symptomsOfMonthChanged",
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
    "getSymptoms",
    "setSymptoms",
    "entryDate",
    "entryTime",
    "setSingleSymptom",
    "Symptom*",
    "newSingleSymptom",
    "getSymptomsOfDate",
    "symptoms",
    "QList<Symptom*>",
    "singleSymptom",
    "daySymptoms",
    "symptomsOfMonth",
    "QList<QDate>"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSymptomModelENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       4,  126, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   86,    2, 0x06,    5 /* Public */,
       3,    0,   87,    2, 0x06,    6 /* Public */,
       4,    0,   88,    2, 0x06,    7 /* Public */,
       5,    0,   89,    2, 0x06,    8 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,   90,    2, 0x0a,    9 /* Public */,
       7,    4,   91,    2, 0x0a,   10 /* Public */,
      12,    1,  100,    2, 0x0a,   15 /* Public */,
      14,    1,  103,    2, 0x0a,   17 /* Public */,
      16,    0,  106,    2, 0x0a,   19 /* Public */,
      17,    6,  107,    2, 0x0a,   20 /* Public */,
      20,    1,  120,    2, 0x0a,   27 /* Public */,
      23,    1,  123,    2, 0x0a,   29 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString,    8,    9,   10,   11,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Bool, QMetaType::QString,   15,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString,    8,    9,   10,   11,   18,   19,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void, QMetaType::QString,   18,

 // properties: name, type, flags
      24, 0x80000000 | 25, 0x0001510b, uint(0), 0,
      26, 0x80000000 | 21, 0x0001510b, uint(1), 0,
      27, 0x80000000 | 25, 0x0001510b, uint(2), 0,
      28, 0x80000000 | 29, 0x0001510b, uint(3), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject SymptomModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QSqlQueryModel::staticMetaObject>(),
    qt_meta_stringdata_CLASSSymptomModelENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSymptomModelENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSymptomModelENDCLASS_t,
        // property 'symptoms'
        QtPrivate::TypeAndForceComplete<QList<Symptom*>, std::true_type>,
        // property 'singleSymptom'
        QtPrivate::TypeAndForceComplete<Symptom*, std::true_type>,
        // property 'daySymptoms'
        QtPrivate::TypeAndForceComplete<QList<Symptom*>, std::true_type>,
        // property 'symptomsOfMonth'
        QtPrivate::TypeAndForceComplete<QList<QDate>, std::true_type>,
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
        // method 'getSymptoms'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setSymptoms'
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
        QtPrivate::TypeAndForceComplete<QString, std::false_type>
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
        case 4: _t->deleteSymptom(); break;
        case 5: _t->updateSymptom((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4]))); break;
        case 6: _t->getEntryDates((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: { bool _r = _t->findDate((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->getSymptoms(); break;
        case 9: _t->setSymptoms((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[6]))); break;
        case 10: _t->setSingleSymptom((*reinterpret_cast< std::add_pointer_t<Symptom*>>(_a[1]))); break;
        case 11: _t->getSymptomsOfDate((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 10:
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
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QDate> >(); break;
        case 2:
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<Symptom*> >(); break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Symptom* >(); break;
        }
    }  else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<SymptomModel *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QList<Symptom*>*>(_v) = _t->symptoms(); break;
        case 1: *reinterpret_cast< Symptom**>(_v) = _t->singleSymptom(); break;
        case 2: *reinterpret_cast< QList<Symptom*>*>(_v) = _t->daySymptoms(); break;
        case 3: *reinterpret_cast< QList<QDate>*>(_v) = _t->symptomsOfMonth(); break;
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
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSymptomModelENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QSqlQueryModel::qt_metacast(_clname);
}

int SymptomModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSqlQueryModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
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
QT_WARNING_POP
