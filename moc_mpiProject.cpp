/****************************************************************************
** Meta object code from reading C++ file 'mpiProject.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mpiProject.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mpiProject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_mpiProject[] = {

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
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      35,   11,   11,   11, 0x08,
      64,   11,   11,   11, 0x08,
      95,   11,   11,   11, 0x08,
     106,   11,   11,   11, 0x08,
     117,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_mpiProject[] = {
    "mpiProject\0\0newMeshHasBeenLoaded()\0"
    "SetNumberOfVerticalSamples()\0"
    "SetNumberOfHorizontalSamples()\0"
    "OpenMesh()\0SaveMesh()\0Help()\0"
};

void mpiProject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        mpiProject *_t = static_cast<mpiProject *>(_o);
        switch (_id) {
        case 0: _t->newMeshHasBeenLoaded(); break;
        case 1: _t->SetNumberOfVerticalSamples(); break;
        case 2: _t->SetNumberOfHorizontalSamples(); break;
        case 3: _t->OpenMesh(); break;
        case 4: _t->SaveMesh(); break;
        case 5: _t->Help(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData mpiProject::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject mpiProject::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_mpiProject,
      qt_meta_data_mpiProject, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &mpiProject::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *mpiProject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *mpiProject::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_mpiProject))
        return static_cast<void*>(const_cast< mpiProject*>(this));
    if (!strcmp(_clname, "wlCore"))
        return static_cast< wlCore*>(const_cast< mpiProject*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int mpiProject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
void mpiProject::newMeshHasBeenLoaded()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
