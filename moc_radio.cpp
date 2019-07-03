/****************************************************************************
** Meta object code from reading C++ file 'radio.h'
**
** Created: Tue Jul 2 22:35:30 2019
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "radio.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'radio.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Radio[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,    7,    6,    6, 0x05,
      39,   32,    6,    6, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_Radio[] = {
    "Radio\0\0freqVal\0freqChanged(int)\0volVal\0"
    "volChanged(int)\0"
};

const QMetaObject Radio::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Radio,
      qt_meta_data_Radio, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Radio::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Radio::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Radio::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Radio))
        return static_cast<void*>(const_cast< Radio*>(this));
    return QWidget::qt_metacast(_clname);
}

int Radio::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: freqChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: volChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void Radio::freqChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Radio::volChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
