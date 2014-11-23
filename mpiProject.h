///////////////////////////////////////////////////////////////////////////////
//  File          :   mpiProject.h                                           //
//  Author        :   Wilfrid LEFER                                          //
//  Comment       :   Interface pour le projet de MPI                        //
//  Related files :   mpiProject.cxx, wlPointEditor.{h,cxx}                  //
//                    Wilfrid Lefer - UPPA - 2007                            //
///////////////////////////////////////////////////////////////////////////////


#ifndef _ISI_PROJECT_H
#define _ISI_PROJECT_H

#include <wlMacros.h>
#include <wlMesh.h>
#include <wlPointEditor.h>
#include <wlMeshGeneratorStudents.h>
#include <QMainWindow>
#include <QTextEdit>
#include <QLabel>
#include <QProgressBar>
#include <QDateTime>

// taille de la fenetre principale par defaut
#define XSIZE 600
#define YSIZE 600

/// \todo tooltips
/// \todo Implementer le signal newMeshHasBeenLoaded()

/** \brief mpiProject realise l'interface du projet de ISI.
*/
class mpiProject : public QMainWindow, public wlCore
{
  Q_OBJECT

public:
  /// Instancie une nouvelle application.
  mpiProject(QString title=QString::fromLocal8Bit("mpiProject", 11), QSize size=QSize(), int debug=0);
 /// Destructeur de classe.
  virtual ~mpiProject() {};
  /// Necessaire pour l'heritage de la classe wlCore.
  virtual char *GetClassName() {return "mpiProject";};

  /// Imprime un message dans la console de l'application.
  void Message(QString text);
  /// Recupere la barre de statut.
  inline QStatusBar *GetStatusBar() {return this->sb;};
  /// Demarre la barre de progression dans la barre de status (a appeler au debut d'un calcul
  /// pour lequel on souhaite une barre de progression). "nsteps" est le nombre total de pas
  /// de temps du calcul.
  void Start(int nsteps);
  /// Progresse la barre de progression d'un pas de temps pour le calcul en cours.
  void Step();

signals:
  /// Signal envoye au modeleur lorsqu'une mesh a ete chargee depuis un fichier.
  void newMeshHasBeenLoaded();

private:
  // Objets Qt.
  QTextEdit *console;
  QStatusBar *sb;
  // La barre de progression.
  QProgressBar *progress;
  // Nombre de pas de temps completes pour le processus en cours de progression.
  int ns;
  // Temps d'execution total de la derniere execution mesuree.
  QTime *exectime;
  // L'editeur de points
  wlPointEditor *editor;
  // Le generateur de mesh.
  wlMeshGeneratorStudents *modeler;
  // La mesh.
  wlMesh *mesh;
  // Le viewer OpenGL
  wlQGLViewer *viewer;

private slots:
  /// Slot : change le nombre de points en verticale.
  void SetNumberOfVerticalSamples();
  /// Slot : change le nombre de points en horizontale (revolution).
  void SetNumberOfHorizontalSamples();
  /// Slot : charge un modele 3D depuis un fichier.
  void OpenMesh();
  /// Slot : sauvegarde le modele 3D dans un fichier.
  void SaveMesh();
  /// La routine d'aide.
  void Help();
};
#endif
