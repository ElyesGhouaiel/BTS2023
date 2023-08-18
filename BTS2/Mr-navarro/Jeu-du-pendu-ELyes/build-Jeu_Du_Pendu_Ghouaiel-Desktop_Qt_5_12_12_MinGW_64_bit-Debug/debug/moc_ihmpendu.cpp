/****************************************************************************
** Meta object code from reading C++ file 'ihmpendu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Jeu_Du_Pendu_Ghouaiel_a_terminer/ihmpendu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ihmpendu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_IHMPendu_t {
    QByteArrayData data[7];
    char stringdata0[95];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IHMPendu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IHMPendu_t qt_meta_stringdata_IHMPendu = {
    {
QT_MOC_LITERAL(0, 0, 8), // "IHMPendu"
QT_MOC_LITERAL(1, 9, 23), // "on_Bonton_Jouer_clicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 24), // "on_Bonton_Config_clicked"
QT_MOC_LITERAL(4, 59, 11), // "boutonclic0"
QT_MOC_LITERAL(5, 71, 11), // "boutonclic1"
QT_MOC_LITERAL(6, 83, 11) // "boutonclic2"

    },
    "IHMPendu\0on_Bonton_Jouer_clicked\0\0"
    "on_Bonton_Config_clicked\0boutonclic0\0"
    "boutonclic1\0boutonclic2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IHMPendu[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void IHMPendu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<IHMPendu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_Bonton_Jouer_clicked(); break;
        case 1: _t->on_Bonton_Config_clicked(); break;
        case 2: _t->boutonclic0(); break;
        case 3: _t->boutonclic1(); break;
        case 4: _t->boutonclic2(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject IHMPendu::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_IHMPendu.data,
    qt_meta_data_IHMPendu,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *IHMPendu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IHMPendu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_IHMPendu.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int IHMPendu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
