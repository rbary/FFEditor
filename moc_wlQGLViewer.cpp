/****************************************************************************
** Meta object code from reading C++ file 'wlQGLViewer.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "wlQGLViewer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wlQGLViewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_wlQGLViewer[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,
      28,   24,   12,   12, 0x0a,
      64,   55,   12,   12, 0x0a,
      93,   90,   12,   12, 0x0a,
     111,   12,   12,   12, 0x0a,
     123,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_wlQGLViewer[] = {
    "wlQGLViewer\0\0updateGL()\0dir\0"
    "SetImageDirectory(QString)\0basename\0"
    "SetImageBasename(QString)\0on\0"
    "SaveSnapshot(int)\0SaveImage()\0"
    "ClearImages()\0"
};

void wlQGLViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        wlQGLViewer *_t = static_cast<wlQGLViewer *>(_o);
        switch (_id) {
        case 0: _t->updateGL(); break;
        case 1: _t->SetImageDirectory((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->SetImageBasename((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->SaveSnapshot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->SaveImage(); break;
        case 5: _t->ClearImages(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData wlQGLViewer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject wlQGLViewer::staticMetaObject = {
    { &QGLViewer::staticMetaObject, qt_meta_stringdata_wlQGLViewer,
      qt_meta_data_wlQGLViewer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &wlQGLViewer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *wlQGLViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *wlQGLViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_wlQGLViewer))
        return static_cast<void*>(const_cast< wlQGLViewer*>(this));
    return QGLViewer::qt_metacast(_clname);
}

int wlQGLViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLViewer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
