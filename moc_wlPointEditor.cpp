/****************************************************************************
** Meta object code from reading C++ file 'wlPointEditor.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "wlPointEditor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wlPointEditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_wlPointEditor[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,   15,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      74,   14,   14,   14, 0x0a,
      96,   89,   14,   14, 0x0a,
     141,  139,   14,   14, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_wlPointEditor[] = {
    "wlPointEditor\0\0list\0"
    "PointListHasChanged(std::vector<std::vector<float> >)\0"
    "PrintContent()\0points\0"
    "SetCurve(std::vector<std::vector<float> >)\0"
    "e\0paintEvent(QPaintEvent*)\0"
};

void wlPointEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        wlPointEditor *_t = static_cast<wlPointEditor *>(_o);
        switch (_id) {
        case 0: _t->PointListHasChanged((*reinterpret_cast< std::vector<std::vector<float> >(*)>(_a[1]))); break;
        case 1: _t->PrintContent(); break;
        case 2: _t->SetCurve((*reinterpret_cast< std::vector<std::vector<float> >(*)>(_a[1]))); break;
        case 3: _t->paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData wlPointEditor::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject wlPointEditor::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_wlPointEditor,
      qt_meta_data_wlPointEditor, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &wlPointEditor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *wlPointEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *wlPointEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_wlPointEditor))
        return static_cast<void*>(const_cast< wlPointEditor*>(this));
    if (!strcmp(_clname, "wlCore"))
        return static_cast< wlCore*>(const_cast< wlPointEditor*>(this));
    return QWidget::qt_metacast(_clname);
}

int wlPointEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void wlPointEditor::PointListHasChanged(std::vector<std::vector<float> > _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
