/****************************************************************************
** Meta object code from reading C++ file 'wlQtSliderSpinBox.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "wlQtSliderSpinBox.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wlQtSliderSpinBox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_wlQtSliderSpinBox[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   19,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
      52,   39,   18,   18, 0x0a,
      87,   81,   18,   18, 0x0a,
     105,   18,  101,   18, 0x0a,
     113,   81,   18,   18, 0x08,
     140,   81,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_wlQtSliderSpinBox[] = {
    "wlQtSliderSpinBox\0\0v\0valueChanged(int)\0"
    "min,max,step\0setRangeAndStep(int,int,int)\0"
    "value\0setValue(int)\0int\0value()\0"
    "sliderValueHasChanged(int)\0"
    "spinBoxValueHasChanged(int)\0"
};

void wlQtSliderSpinBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        wlQtSliderSpinBox *_t = static_cast<wlQtSliderSpinBox *>(_o);
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setRangeAndStep((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->setValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: { int _r = _t->value();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 4: _t->sliderValueHasChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->spinBoxValueHasChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData wlQtSliderSpinBox::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject wlQtSliderSpinBox::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_wlQtSliderSpinBox,
      qt_meta_data_wlQtSliderSpinBox, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &wlQtSliderSpinBox::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *wlQtSliderSpinBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *wlQtSliderSpinBox::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_wlQtSliderSpinBox))
        return static_cast<void*>(const_cast< wlQtSliderSpinBox*>(this));
    if (!strcmp(_clname, "wlCore"))
        return static_cast< wlCore*>(const_cast< wlQtSliderSpinBox*>(this));
    return QWidget::qt_metacast(_clname);
}

int wlQtSliderSpinBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void wlQtSliderSpinBox::valueChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
