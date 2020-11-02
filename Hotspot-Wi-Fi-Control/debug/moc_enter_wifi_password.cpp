/****************************************************************************
** Meta object code from reading C++ file 'enter_wifi_password.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../enter_wifi_password.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'enter_wifi_password.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_enter_wifi_password[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x08,
      45,   20,   20,   20, 0x08,
      69,   20,   20,   20, 0x08,
      96,   20,   20,   20, 0x08,
     123,   20,   20,   20, 0x08,
     149,   20,   20,   20, 0x08,
     173,   20,   20,   20, 0x08,
     196,   20,   20,   20, 0x08,
     223,   20,   20,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_enter_wifi_password[] = {
    "enter_wifi_password\0\0on_abc_button_clicked()\0"
    "on_ABC_button_clicked()\0"
    "on_number_button_clicked()\0"
    "on_symbol_button_clicked()\0"
    "on_space_button_clicked()\0"
    "on_del_button_clicked()\0on_ok_button_clicked()\0"
    "on_cancel_button_clicked()\0"
    "keyboard_clicked()\0"
};

void enter_wifi_password::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        enter_wifi_password *_t = static_cast<enter_wifi_password *>(_o);
        switch (_id) {
        case 0: _t->on_abc_button_clicked(); break;
        case 1: _t->on_ABC_button_clicked(); break;
        case 2: _t->on_number_button_clicked(); break;
        case 3: _t->on_symbol_button_clicked(); break;
        case 4: _t->on_space_button_clicked(); break;
        case 5: _t->on_del_button_clicked(); break;
        case 6: _t->on_ok_button_clicked(); break;
        case 7: _t->on_cancel_button_clicked(); break;
        case 8: _t->keyboard_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData enter_wifi_password::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject enter_wifi_password::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_enter_wifi_password,
      qt_meta_data_enter_wifi_password, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &enter_wifi_password::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *enter_wifi_password::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *enter_wifi_password::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_enter_wifi_password))
        return static_cast<void*>(const_cast< enter_wifi_password*>(this));
    return QDialog::qt_metacast(_clname);
}

int enter_wifi_password::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
