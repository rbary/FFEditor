TEMPLATE = app
TARGET +=
CONFIG = qt opengl release
DEPENDPATH += .
QT *= opengl xml
INCLUDEPATH += /usr/include/qt4/Qt /usr/include/QGLViewer
LIBS += -L/usr/local/lib -lQGLViewer -L. -lGLU -lFFEditor
QMAKE_CXXFLAGS += -Wno-write-strings
QMAKE_CXXFLAGS_DEBUG += -Wno-deprecated
QMAKE_CXXFLAGS_RELEASE += -Wno-deprecated

# Input
HEADERS += mpiProject.h \
           wlCore.h \
           wlMacros.h \
           wlQGLViewer.h \
           wlMesh.h \
           wlMeshGenerator.h \
           wlMeshGeneratorStudents.h \
           wlPointEditor.h \
           wlQtSliderSpinBox.h
SOURCES += wlMeshGeneratorStudents.cxx \
           mpiProject.cxx
