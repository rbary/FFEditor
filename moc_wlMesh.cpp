/****************************************************************************
** Meta object code from reading C++ file 'wlMesh.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "wlMesh.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wlMesh.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_wlMesh[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      36,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
      57,    7,   41,    7, 0x0a,
      68,    7,   41,    7, 0x0a,
     103,    7,   85,    7, 0x0a,
     116,    7,   85,    7, 0x0a,
     168,    7,  135,    7, 0x0a,
     184,    7,  135,    7, 0x0a,
     206,    7,   41,    7, 0x0a,
     218,    7,   41,    7, 0x0a,
     267,    7,  236,    7, 0x0a,
     282,    7,  236,    7, 0x0a,
     323,    7,  303,    7, 0x0a,
     338,    7,  303,    7, 0x0a,
     359,    7,  236,    7, 0x0a,
     377,    7,  236,    7, 0x0a,
     403,  401,    7,    7, 0x0a,
     435,  429,    7,    7, 0x0a,
     474,  429,    7,    7, 0x0a,
     520,  511,    7,    7, 0x0a,
     538,    7,    7,    7, 0x2a,
     557,    7,  549,    7, 0x0a,
     628,  571,    7,    7, 0x0a,
     749,  712,    7,    7, 0x2a,
     847,  828,    7,    7, 0x2a,
     927,  921,    7,    7, 0x0a,
     944,  511,    7,    7, 0x0a,
     965,  511,    7,    7, 0x0a,
     988,    7,    7,    7, 0x0a,
    1008,  995,    7,    7, 0x0a,
    1022,    7,    7,    7, 0x2a,
    1049, 1033,    7,    7, 0x0a,
    1073, 1070,    7,    7, 0x2a,
    1090,    7,    7,    7, 0x0a,
    1107,    7,    7,    7, 0x0a,
    1119,    7,    7,    7, 0x0a,
    1134,    7,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_wlMesh[] = {
    "wlMesh\0\0numberOfTrianglesHasChanged(int)\0"
    "QVector<wlCoin>\0GetCoins()\0GetFiniteCoins()\0"
    "QVector<wlSommet>\0GetSommets()\0"
    "GetFiniteSommets()\0std::vector<std::vector<float> >\0"
    "GetStdSommets()\0GetStdFiniteSommets()\0"
    "GetAretes()\0GetFiniteAretes()\0"
    "std::vector<std::vector<int> >\0"
    "GetStdAretes()\0GetStdFiniteAretes()\0"
    "QVector<wlTriangle>\0GetTriangles()\0"
    "GetFiniteTriangles()\0GetStdTriangles()\0"
    "GetStdFiniteTriangles()\0v\0"
    "Translate(QVector<float>)\0s,v,d\0"
    "Deforme(wlSommet,QVector<float>,float)\0"
    "Deforme(wlSommet,QVector<float>,int)\0"
    "filename\0LoadMesh(QString)\0LoadMesh()\0"
    "QString\0GetFilename()\0"
    "vertices,triangles,HasInfiniteVertex,NbInfiniteTriangles\0"
    "InitMesh(std::vector<std::vector<float> >,std::vector<std::vector<int>"
    " >,uint,uint)\0"
    "vertices,triangles,HasInfiniteVertex\0"
    "InitMesh(std::vector<std::vector<float> >,std::vector<std::vector<int>"
    " >,uint)\0"
    "vertices,triangles\0"
    "InitMesh(std::vector<std::vector<float> >,std::vector<std::vector<int>"
    " >)\0"
    "color\0SetColor(QColor)\0LoadTexture(QString)\0"
    "SaveMeshAsOFF(QString)\0draw()\0"
    "reset_camera\0makeList(int)\0makeList()\0"
    "c0,reset_camera\0makeList(wlCoin,int)\0"
    "c0\0makeList(wlCoin)\0ShowEntireMesh()\0"
    "PrintSelf()\0PrintContent()\0Clear()\0"
};

void wlMesh::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        wlMesh *_t = static_cast<wlMesh *>(_o);
        switch (_id) {
        case 0: _t->numberOfTrianglesHasChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: { QVector<wlCoin> _r = _t->GetCoins();
            if (_a[0]) *reinterpret_cast< QVector<wlCoin>*>(_a[0]) = _r; }  break;
        case 2: { QVector<wlCoin> _r = _t->GetFiniteCoins();
            if (_a[0]) *reinterpret_cast< QVector<wlCoin>*>(_a[0]) = _r; }  break;
        case 3: { QVector<wlSommet> _r = _t->GetSommets();
            if (_a[0]) *reinterpret_cast< QVector<wlSommet>*>(_a[0]) = _r; }  break;
        case 4: { QVector<wlSommet> _r = _t->GetFiniteSommets();
            if (_a[0]) *reinterpret_cast< QVector<wlSommet>*>(_a[0]) = _r; }  break;
        case 5: { std::vector<std::vector<float> > _r = _t->GetStdSommets();
            if (_a[0]) *reinterpret_cast< std::vector<std::vector<float> >*>(_a[0]) = _r; }  break;
        case 6: { std::vector<std::vector<float> > _r = _t->GetStdFiniteSommets();
            if (_a[0]) *reinterpret_cast< std::vector<std::vector<float> >*>(_a[0]) = _r; }  break;
        case 7: { QVector<wlCoin> _r = _t->GetAretes();
            if (_a[0]) *reinterpret_cast< QVector<wlCoin>*>(_a[0]) = _r; }  break;
        case 8: { QVector<wlCoin> _r = _t->GetFiniteAretes();
            if (_a[0]) *reinterpret_cast< QVector<wlCoin>*>(_a[0]) = _r; }  break;
        case 9: { std::vector<std::vector<int> > _r = _t->GetStdAretes();
            if (_a[0]) *reinterpret_cast< std::vector<std::vector<int> >*>(_a[0]) = _r; }  break;
        case 10: { std::vector<std::vector<int> > _r = _t->GetStdFiniteAretes();
            if (_a[0]) *reinterpret_cast< std::vector<std::vector<int> >*>(_a[0]) = _r; }  break;
        case 11: { QVector<wlTriangle> _r = _t->GetTriangles();
            if (_a[0]) *reinterpret_cast< QVector<wlTriangle>*>(_a[0]) = _r; }  break;
        case 12: { QVector<wlTriangle> _r = _t->GetFiniteTriangles();
            if (_a[0]) *reinterpret_cast< QVector<wlTriangle>*>(_a[0]) = _r; }  break;
        case 13: { std::vector<std::vector<int> > _r = _t->GetStdTriangles();
            if (_a[0]) *reinterpret_cast< std::vector<std::vector<int> >*>(_a[0]) = _r; }  break;
        case 14: { std::vector<std::vector<int> > _r = _t->GetStdFiniteTriangles();
            if (_a[0]) *reinterpret_cast< std::vector<std::vector<int> >*>(_a[0]) = _r; }  break;
        case 15: _t->Translate((*reinterpret_cast< QVector<float>(*)>(_a[1]))); break;
        case 16: _t->Deforme((*reinterpret_cast< wlSommet(*)>(_a[1])),(*reinterpret_cast< QVector<float>(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        case 17: _t->Deforme((*reinterpret_cast< wlSommet(*)>(_a[1])),(*reinterpret_cast< QVector<float>(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 18: _t->LoadMesh((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 19: _t->LoadMesh(); break;
        case 20: { QString _r = _t->GetFilename();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 21: _t->InitMesh((*reinterpret_cast< std::vector<std::vector<float> >(*)>(_a[1])),(*reinterpret_cast< std::vector<std::vector<int> >(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3])),(*reinterpret_cast< uint(*)>(_a[4]))); break;
        case 22: _t->InitMesh((*reinterpret_cast< std::vector<std::vector<float> >(*)>(_a[1])),(*reinterpret_cast< std::vector<std::vector<int> >(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3]))); break;
        case 23: _t->InitMesh((*reinterpret_cast< std::vector<std::vector<float> >(*)>(_a[1])),(*reinterpret_cast< std::vector<std::vector<int> >(*)>(_a[2]))); break;
        case 24: _t->SetColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 25: _t->LoadTexture((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 26: _t->SaveMeshAsOFF((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 27: _t->draw(); break;
        case 28: _t->makeList((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 29: _t->makeList(); break;
        case 30: _t->makeList((*reinterpret_cast< wlCoin(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 31: _t->makeList((*reinterpret_cast< wlCoin(*)>(_a[1]))); break;
        case 32: _t->ShowEntireMesh(); break;
        case 33: _t->PrintSelf(); break;
        case 34: _t->PrintContent(); break;
        case 35: _t->Clear(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData wlMesh::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject wlMesh::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_wlMesh,
      qt_meta_data_wlMesh, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &wlMesh::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *wlMesh::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *wlMesh::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_wlMesh))
        return static_cast<void*>(const_cast< wlMesh*>(this));
    if (!strcmp(_clname, "wlCore"))
        return static_cast< wlCore*>(const_cast< wlMesh*>(this));
    return QObject::qt_metacast(_clname);
}

int wlMesh::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 36)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 36;
    }
    return _id;
}

// SIGNAL 0
void wlMesh::numberOfTrianglesHasChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
