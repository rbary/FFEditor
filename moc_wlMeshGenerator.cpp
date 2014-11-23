/****************************************************************************
** Meta object code from reading C++ file 'wlMeshGenerator.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "wlMeshGenerator.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wlMeshGenerator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_wlMeshGenerator[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   17,   16,   16, 0x05,
      91,   72,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
     177,  171,   16,   16, 0x0a,
     197,  195,   16,   16, 0x0a,
     224,  195,   16,   16, 0x0a,
     259,  253,   16,   16, 0x0a,
     289,  282,   16,   16, 0x0a,
     333,   16,   16,   16, 0x0a,
     345,   16,   16,   16, 0x0a,
     360,   16,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_wlMeshGenerator[] = {
    "wlMeshGenerator\0\0list\0"
    "CurveHasChanged(std::vector<std::vector<float> >)\0"
    "vertices,triangles\0"
    "MeshHasChanged(std::vector<std::vector<float> >,std::vector<std::vecto"
    "r<int> >)\0"
    "ctype\0SetCurveType(int)\0n\0"
    "SetVerticalResolution(int)\0"
    "SetHorizontalResolution(int)\0vn,hn\0"
    "SetResolution(int,int)\0points\0"
    "SetPoints(std::vector<std::vector<float> >)\0"
    "PrintSelf()\0PrintContent()\0Update()\0"
};

void wlMeshGenerator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        wlMeshGenerator *_t = static_cast<wlMeshGenerator *>(_o);
        switch (_id) {
        case 0: _t->CurveHasChanged((*reinterpret_cast< std::vector<std::vector<float> >(*)>(_a[1]))); break;
        case 1: _t->MeshHasChanged((*reinterpret_cast< std::vector<std::vector<float> >(*)>(_a[1])),(*reinterpret_cast< std::vector<std::vector<int> >(*)>(_a[2]))); break;
        case 2: _t->SetCurveType((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->SetVerticalResolution((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->SetHorizontalResolution((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->SetResolution((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->SetPoints((*reinterpret_cast< std::vector<std::vector<float> >(*)>(_a[1]))); break;
        case 7: _t->PrintSelf(); break;
        case 8: _t->PrintContent(); break;
        case 9: _t->Update(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData wlMeshGenerator::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject wlMeshGenerator::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_wlMeshGenerator,
      qt_meta_data_wlMeshGenerator, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &wlMeshGenerator::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *wlMeshGenerator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *wlMeshGenerator::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_wlMeshGenerator))
        return static_cast<void*>(const_cast< wlMeshGenerator*>(this));
    if (!strcmp(_clname, "wlCore"))
        return static_cast< wlCore*>(const_cast< wlMeshGenerator*>(this));
    return QWidget::qt_metacast(_clname);
}

int wlMeshGenerator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void wlMeshGenerator::CurveHasChanged(std::vector<std::vector<float> > _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void wlMeshGenerator::MeshHasChanged(std::vector<std::vector<float> > _t1, std::vector<std::vector<int> > _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
