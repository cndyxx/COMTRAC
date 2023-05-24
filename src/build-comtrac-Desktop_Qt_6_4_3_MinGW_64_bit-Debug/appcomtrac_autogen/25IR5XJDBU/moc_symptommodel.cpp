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
    uint offsetsAndSizes[38];
    char stringdata0[13];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[21];
    char stringdata4[11];
    char stringdata5[5];
    char stringdata6[10];
    char stringdata7[10];
    char stringdata8[9];
    char stringdata9[10];
    char stringdata10[10];
    char stringdata11[18];
    char stringdata12[3];
    char stringdata13[18];
    char stringdata14[11];
    char stringdata15[9];
    char stringdata16[16];
    char stringdata17[14];
    char stringdata18[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_SymptomModel_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_SymptomModel_t qt_meta_stringdata_SymptomModel = {
    {
        QT_MOC_LITERAL(0, 12),  // "SymptomModel"
        QT_MOC_LITERAL(13, 15),  // "symptomsChanged"
        QT_MOC_LITERAL(29, 0),  // ""
        QT_MOC_LITERAL(30, 20),  // "singleSymptomChanged"
        QT_MOC_LITERAL(51, 10),  // "addSymptom"
        QT_MOC_LITERAL(62, 4),  // "name"
        QT_MOC_LITERAL(67, 9),  // "intensity"
        QT_MOC_LITERAL(77, 9),  // "frequency"
        QT_MOC_LITERAL(87, 8),  // "duration"
        QT_MOC_LITERAL(96, 9),  // "entryDate"
        QT_MOC_LITERAL(106, 9),  // "entryTime"
        QT_MOC_LITERAL(116, 17),  // "setCurrentSymptom"
        QT_MOC_LITERAL(134, 2),  // "id"
        QT_MOC_LITERAL(137, 17),  // "getCurrentSymptom"
        QT_MOC_LITERAL(155, 10),  // "setSymptom"
        QT_MOC_LITERAL(166, 8),  // "symptoms"
        QT_MOC_LITERAL(175, 15),  // "QList<Symptom*>"
        QT_MOC_LITERAL(191, 13),  // "singleSymptom"
        QT_MOC_LITERAL(205, 8)   // "Symptom*"
    },
    "SymptomModel",
    "symptomsChanged",
    "",
    "singleSymptomChanged",
    "addSymptom",
    "name",
    "intensity",
    "frequency",
    "duration",
    "entryDate",
    "entryTime",
    "setCurrentSymptom",
    "id",
    "getCurrentSymptom",
    "setSymptom",
    "symptoms",
    "QList<Symptom*>",
    "singleSymptom",
    "Symptom*"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_SymptomModel[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       2,   72, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x06,    3 /* Public */,
       3,    0,   51,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    6,   52,    2, 0x0a,    5 /* Public */,
      11,    1,   65,    2, 0x0a,   12 /* Public */,
      13,    0,   68,    2, 0x0a,   14 /* Public */,
      14,    1,   69,    2, 0x0a,   15 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString,    5,    6,    7,    8,    9,   10,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,   12,

 // properties: name, type, flags
      15, 0x80000000 | 16, 0x0001510b, uint(0), 0,
      17, 0x80000000 | 18, 0x0001510b, uint(1), 0,

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
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SymptomModel, std::true_type>,
        // method 'symptomsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'singleSymptomChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addSymptom'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'setCurrentSymptom'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getCurrentSymptom'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setSymptom'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
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
        case 2: _t->addSymptom((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[6]))); break;
        case 3: _t->setCurrentSymptom((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: { int _r = _t->getCurrentSymptom();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->setSymptom((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
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
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
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
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<SymptomModel *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setSymptoms(*reinterpret_cast< QList<Symptom*>*>(_v)); break;
        case 1: _t->setSingleSymptom(*reinterpret_cast< Symptom**>(_v)); break;
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
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
