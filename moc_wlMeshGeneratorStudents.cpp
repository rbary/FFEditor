/****************************************************************************
** Meta object code from reading C++ file 'wlMeshGeneratorStudents.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "wlMeshGeneratorStudents.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wlMeshGeneratorStudents.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_wlMeshGeneratorStudents[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      25,   24,   24,   24, 0x0a,
      55,   43,   24,   24, 0x0a,
      82,   78,   24,   24, 0x0a,
     111,  107,   24,   24, 0x0a,
     133,   24,   24,   24, 0x0a,
     153,   24,   24,   24, 0x0a,
     176,   24,   24,   24, 0x0a,
     199,   24,   24,   24, 0x0a,
     235,  219,   24,   24, 0x0a,
     281,  273,  267,   24, 0x0a,
     372,  361,  328,   24, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_wlMeshGeneratorStudents[] = {
    "wlMeshGeneratorStudents\0\0initializations()\0"
    "typeOfCurve\0SetTheTypeOfCurve(int)\0"
    "a_u\0changeCurrent_ui(double)\0a_w\0"
    "changeCurrent_wi(int)\0addCurrent_uiToUi()\0"
    "Ui_pushButtonClicked()\0Wi_pushButtonClicked()\0"
    "addCurrent_wiToWi()\0vectorToDisplay\0"
    "afficheVector(std::vector<int>)\0float\0"
    "a_curve\0computeScale(std::vector<std::vector<float> >)\0"
    "std::vector<std::vector<float> >\0"
    "hz,a_curve\0"
    "allVtxComputing(int,std::vector<std::vector<float> >)\0"
};

void wlMeshGeneratorStudents::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        wlMeshGeneratorStudents *_t = static_cast<wlMeshGeneratorStudents *>(_o);
        switch (_id) {
        case 0: _t->initializations(); break;
        case 1: _t->SetTheTypeOfCurve((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->changeCurrent_ui((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->changeCurrent_wi((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->addCurrent_uiToUi(); break;
        case 5: _t->Ui_pushButtonClicked(); break;
        case 6: _t->Wi_pushButtonClicked(); break;
        case 7: _t->addCurrent_wiToWi(); break;
        case 8: _t->afficheVector((*reinterpret_cast< std::vector<int>(*)>(_a[1]))); break;
        case 9: { float _r = _t->computeScale((*reinterpret_cast< std::vector<std::vector<float> >(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 10: { std::vector<std::vector<float> > _r = _t->allVtxComputing((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< std::vector<std::vector<float> >(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< std::vector<std::vector<float> >*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData wlMeshGeneratorStudents::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject wlMeshGeneratorStudents::staticMetaObject = {
    { &wlMeshGenerator::staticMetaObject, qt_meta_stringdata_wlMeshGeneratorStudents,
      qt_meta_data_wlMeshGeneratorStudents, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &wlMeshGeneratorStudents::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *wlMeshGeneratorStudents::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *wlMeshGeneratorStudents::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_wlMeshGeneratorStudents))
        return static_cast<void*>(const_cast< wlMeshGeneratorStudents*>(this));
    return wlMeshGenerator::qt_metacast(_clname);
}

int wlMeshGeneratorStudents::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = wlMeshGenerator::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
