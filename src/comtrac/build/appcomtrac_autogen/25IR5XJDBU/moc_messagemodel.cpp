/****************************************************************************
** Meta object code from reading C++ file 'messagemodel.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Models/messagemodel.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'messagemodel.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_MessageModel_t {
    uint offsetsAndSizes[16];
    char stringdata0[13];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[16];
    char stringdata5[12];
    char stringdata6[12];
    char stringdata7[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MessageModel_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MessageModel_t qt_meta_stringdata_MessageModel = {
    {
        QT_MOC_LITERAL(0, 12),  // "MessageModel"
        QT_MOC_LITERAL(13, 15),  // "messagesChanged"
        QT_MOC_LITERAL(29, 0),  // ""
        QT_MOC_LITERAL(30, 11),  // "getMessages"
        QT_MOC_LITERAL(42, 15),  // "QList<Message*>"
        QT_MOC_LITERAL(58, 11),  // "setMessages"
        QT_MOC_LITERAL(70, 11),  // "newMessages"
        QT_MOC_LITERAL(82, 8)   // "messages"
    },
    "MessageModel",
    "messagesChanged",
    "",
    "getMessages",
    "QList<Message*>",
    "setMessages",
    "newMessages",
    "messages"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MessageModel[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       1,   37, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   32,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   33,    2, 0x0a,    3 /* Public */,
       5,    1,   34,    2, 0x0a,    4 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    0x80000000 | 4,
    QMetaType::Void, 0x80000000 | 4,    6,

 // properties: name, type, flags
       7, 0x80000000 | 4, 0x0001510b, uint(0), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject MessageModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_MessageModel.offsetsAndSizes,
    qt_meta_data_MessageModel,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MessageModel_t,
        // property 'messages'
        QtPrivate::TypeAndForceComplete<QList<Message*>, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MessageModel, std::true_type>,
        // method 'messagesChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'getMessages'
        QtPrivate::TypeAndForceComplete<QList<Message*>, std::false_type>,
        // method 'setMessages'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QList<Message*> &, std::false_type>
    >,
    nullptr
} };

void MessageModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MessageModel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->messagesChanged(); break;
        case 1: { QList<Message*> _r = _t->getMessages();
            if (_a[0]) *reinterpret_cast< QList<Message*>*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->setMessages((*reinterpret_cast< std::add_pointer_t<QList<Message*>>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<Message*> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MessageModel::*)();
            if (_t _q_method = &MessageModel::messagesChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<Message*> >(); break;
        }
    }
else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<MessageModel *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QList<Message*>*>(_v) = _t->messages(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<MessageModel *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setMessages(*reinterpret_cast< QList<Message*>*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *MessageModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MessageModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MessageModel.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MessageModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void MessageModel::messagesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
