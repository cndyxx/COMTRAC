/****************************************************************************
** Meta object code from reading C++ file 'symptom.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../comtrac/Models/symptom.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'symptom.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSSymptomENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSSymptomENDCLASS = QtMocHelpers::stringData(
    "Symptom",
    "idChanged",
    "",
    "nameChanged",
    "intensityChanged",
    "frequencyChanged",
    "durationChanged",
    "entryDateChanged",
    "entryTimeChanged",
    "id",
    "name",
    "intensity",
    "frequency",
    "duration",
    "entryDate",
    "entryTime"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSSymptomENDCLASS_t {
    uint offsetsAndSizes[32];
    char stringdata0[8];
    char stringdata1[10];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[17];
    char stringdata5[17];
    char stringdata6[16];
    char stringdata7[17];
    char stringdata8[17];
    char stringdata9[3];
    char stringdata10[5];
    char stringdata11[10];
    char stringdata12[10];
    char stringdata13[9];
    char stringdata14[10];
    char stringdata15[10];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSSymptomENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSSymptomENDCLASS_t qt_meta_stringdata_CLASSSymptomENDCLASS = {
    {
        QT_MOC_LITERAL(0, 7),  // "Symptom"
        QT_MOC_LITERAL(8, 9),  // "idChanged"
        QT_MOC_LITERAL(18, 0),  // ""
        QT_MOC_LITERAL(19, 11),  // "nameChanged"
        QT_MOC_LITERAL(31, 16),  // "intensityChanged"
        QT_MOC_LITERAL(48, 16),  // "frequencyChanged"
        QT_MOC_LITERAL(65, 15),  // "durationChanged"
        QT_MOC_LITERAL(81, 16),  // "entryDateChanged"
        QT_MOC_LITERAL(98, 16),  // "entryTimeChanged"
        QT_MOC_LITERAL(115, 2),  // "id"
        QT_MOC_LITERAL(118, 4),  // "name"
        QT_MOC_LITERAL(123, 9),  // "intensity"
        QT_MOC_LITERAL(133, 9),  // "frequency"
        QT_MOC_LITERAL(143, 8),  // "duration"
        QT_MOC_LITERAL(152, 9),  // "entryDate"
        QT_MOC_LITERAL(162, 9)   // "entryTime"
    },
    "Symptom",
    "idChanged",
    "",
    "nameChanged",
    "intensityChanged",
    "frequencyChanged",
    "durationChanged",
    "entryDateChanged",
    "entryTimeChanged",
    "id",
    "name",
    "intensity",
    "frequency",
    "duration",
    "entryDate",
    "entryTime"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSymptomENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       7,   63, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x06,    8 /* Public */,
       3,    0,   57,    2, 0x06,    9 /* Public */,
       4,    0,   58,    2, 0x06,   10 /* Public */,
       5,    0,   59,    2, 0x06,   11 /* Public */,
       6,    0,   60,    2, 0x06,   12 /* Public */,
       7,    0,   61,    2, 0x06,   13 /* Public */,
       8,    0,   62,    2, 0x06,   14 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       9, QMetaType::Int, 0x00015103, uint(0), 0,
      10, QMetaType::QString, 0x00015103, uint(1), 0,
      11, QMetaType::QString, 0x00015103, uint(2), 0,
      12, QMetaType::Int, 0x00015103, uint(3), 0,
      13, QMetaType::QString, 0x00015103, uint(4), 0,
      14, QMetaType::QDate, 0x00015103, uint(5), 0,
      15, QMetaType::QTime, 0x00015103, uint(6), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject Symptom::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSSymptomENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSymptomENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSymptomENDCLASS_t,
        // property 'id'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'name'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'intensity'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'frequency'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'duration'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'entryDate'
        QtPrivate::TypeAndForceComplete<QDate, std::true_type>,
        // property 'entryTime'
        QtPrivate::TypeAndForceComplete<QTime, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Symptom, std::true_type>,
        // method 'idChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'nameChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'intensityChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'frequencyChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'durationChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'entryDateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'entryTimeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Symptom::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Symptom *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->idChanged(); break;
        case 1: _t->nameChanged(); break;
        case 2: _t->intensityChanged(); break;
        case 3: _t->frequencyChanged(); break;
        case 4: _t->durationChanged(); break;
        case 5: _t->entryDateChanged(); break;
        case 6: _t->entryTimeChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Symptom::*)();
            if (_t _q_method = &Symptom::idChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Symptom::*)();
            if (_t _q_method = &Symptom::nameChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Symptom::*)();
            if (_t _q_method = &Symptom::intensityChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Symptom::*)();
            if (_t _q_method = &Symptom::frequencyChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Symptom::*)();
            if (_t _q_method = &Symptom::durationChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Symptom::*)();
            if (_t _q_method = &Symptom::entryDateChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Symptom::*)();
            if (_t _q_method = &Symptom::entryTimeChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
    } else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Symptom *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->id(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->name(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->intensity(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->frequency(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->duration(); break;
        case 5: *reinterpret_cast< QDate*>(_v) = _t->entryDate(); break;
        case 6: *reinterpret_cast< QTime*>(_v) = _t->entryTime(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Symptom *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setId(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setName(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setIntensity(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setFrequency(*reinterpret_cast< int*>(_v)); break;
        case 4: _t->setDuration(*reinterpret_cast< QString*>(_v)); break;
        case 5: _t->setEntryDate(*reinterpret_cast< QDate*>(_v)); break;
        case 6: _t->setEntryTime(*reinterpret_cast< QTime*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
    (void)_a;
}

const QMetaObject *Symptom::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Symptom::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSymptomENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Symptom::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Symptom::idChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Symptom::nameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Symptom::intensityChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Symptom::frequencyChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Symptom::durationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Symptom::entryDateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Symptom::entryTimeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
