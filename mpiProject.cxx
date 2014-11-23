///////////////////////////////////////////////////////////////////////////////
//  File          :   mpiProject.cxx                                         //
//  Author        :   Wilfrid LEFER                                          //
//  Comment       :   Interface pour le projet de MPI                        //
//  Related files :   mpiProject.h, wlPointEditor.{h,cxx}                    //
//                    Wilfrid Lefer - UPPA - 2007                            //
///////////////////////////////////////////////////////////////////////////////


#include "mpiProject.h"
#include <wlQtSliderSpinBox.h>
#include <QApplication>
#include <QAction>
#include <QFileDialog>
#include <QToolBar>
#include <QMenuBar>
#include <QStatusBar>
#include <QStringList>
#include <QGroupBox>
#include <QPushButton>
#include <QEvent>
#include <QDockWidget>
#include <QBoxLayout>
#include <QMessageBox>
#include <QComboBox>
#include <QPushButton>

#define USAGE(cmd) { \
  this->Error("Usage: %s [-debug]\n", cmd); \
  qApp->quit(); \
}

mpiProject::mpiProject(QString title, QSize size, int debug)
  : wlCore(debug)
{
  this->Trace("-> mpiProject()");
  this->setWindowTitle(title);
  //
  // Objets de calcul et d'affichage
  //
  // un editeur de points dans le plan
  this->editor = new wlPointEditor(NULL, size, debug);
  // un modeleur a base de courbes de Bezier
  this->modeler = new wlMeshGeneratorStudents(this, debug);
  // un viewer OpenGL
  this->viewer = new wlQGLViewer;
  // une mesh 3D avec relations topologiques
  this->mesh = new wlMesh(debug, this->viewer);
  // on les connecte afin qu'ils communiquent a chaque nouvel evenement
  this->mesh->ConnectViewer(this->viewer);
  connect(this->editor, SIGNAL(PointListHasChanged(std::vector<std::vector<float> >)),
          this->modeler, SLOT(SetPoints(std::vector<std::vector<float> >)));
  connect(this->modeler, SIGNAL(CurveHasChanged(std::vector<std::vector<float> >)),
          this->editor, SLOT(SetCurve(std::vector<std::vector<float> >)));
  connect(this->modeler, SIGNAL(MeshHasChanged(std::vector<std::vector<float> >, std::vector<std::vector<int> >)),
          this->mesh, SLOT(InitMesh(std::vector<std::vector<float> >, std::vector<std::vector<int> >)));
  //
  // Menus
  //
  // menu fichier
  QMenu *file_menu = this->menuBar()->addMenu("&File");
  QAction *openAct = new QAction("&Open model", this);
  openAct->setShortcut(QKeySequence(QString("Ctrl+S")));
  openAct->setStatusTip("Charger un modele 3D");
  connect(openAct, SIGNAL(triggered()), this, SLOT(OpenMesh()));
  file_menu->addAction(openAct);
  QAction *saveAct = new QAction("&Save model", this);
  saveAct->setShortcut(QKeySequence(QString("Ctrl+S")));
  saveAct->setStatusTip("Sauvegarder le modele 3D");
  connect(saveAct, SIGNAL(triggered()), this, SLOT(SaveMesh()));
  file_menu->addAction(saveAct);
  file_menu->addSeparator();
  QAction *quitAct = new QAction("&Quit", this);
  quitAct->setShortcut(QKeySequence(QString("Ctrl+Q")));
  quitAct->setStatusTip("Quitter l'application");
  connect(quitAct, SIGNAL(triggered()), qApp, SLOT(closeAllWindows()));
  file_menu->addAction(quitAct);
  // menu aide
  QMenu *help_menu = this->menuBar()->addMenu("&Help");
  QAction *interAct = new QAction("&Interactions", this);
  interAct->setShortcut(QKeySequence(QString("Ctrl+H")));
  interAct->setStatusTip("Explique les interactions possibles");
  connect(interAct, SIGNAL(triggered()), this, SLOT(Help()));
  help_menu->addAction(interAct);
  //
  // Button bar
  //
  QToolBar *tb = new QToolBar();
  this->addToolBar(tb);
  QWidget *wb = new QWidget;
  QVBoxLayout *wlayout = new QVBoxLayout;
  wb->setLayout(wlayout);

  QPushButton *b = new QPushButton(QString::fromLocal8Bit("PrintSelf"));
  b->setWhatsThis(QString::fromLocal8Bit("Imprime le nombre de points de controle, sommets et triangles"));
  QObject::connect(b, SIGNAL(clicked()), this->modeler, SLOT(PrintSelf()));
  wlayout->addWidget(b);
  b = new QPushButton(QString::fromLocal8Bit("PrintContent"));
  b->setWhatsThis(QString::fromLocal8Bit("Imprime la liste des points de controle, sommets et triangles"));
  QObject::connect(b, SIGNAL(clicked()), this->modeler, SLOT(PrintContent()));
  wlayout->addWidget(b);
  /************************************************************************************************************/
  //Mise en place de l'option permettant de choisir le type de courbe (Bézier, BSpline ou NURBS)
  QComboBox * bbn = new QComboBox();
  bbn->addItem("Bezier");
  bbn->addItem("BSpline");
  bbn->addItem("NURBS");
  bbn->setWhatsThis(QString::fromLocal8Bit("Choisir le type de courbe (Bezier, BSpline, NURBS"));
  QObject::connect(bbn, SIGNAL(activated(int)),this->modeler,SLOT(SetTheTypeOfCurve(int)));
  wlayout->addWidget(bbn);
  /************************************************************************************************************/
  tb->addWidget(wb);
  tb->addSeparator();
  QWidget *wv = new QWidget;
  QVBoxLayout *vlayout = new QVBoxLayout;
  wv->setLayout(vlayout);
  QLabel *lv = new QLabel(QString::fromLocal8Bit("Resolution verticale :"));
  vlayout->addWidget(lv);
  wlQtSliderSpinBox *v = new wlQtSliderSpinBox(NULL, 3);
  v->setWhatsThis(QString::fromLocal8Bit("Definit la resolution verticale"));
  QObject::connect(v, SIGNAL(valueChanged(int)), this->modeler, SLOT(SetVerticalResolution(int)));
  vlayout->addWidget(v);
  tb->addWidget(wv);
  QWidget *wh = new QWidget;
  QVBoxLayout *hlayout = new QVBoxLayout;
  wh->setLayout(hlayout);
  QLabel *lh = new QLabel(QString::fromLocal8Bit("Resolution horizontale :"));
  hlayout->addWidget(lh);
  wlQtSliderSpinBox *h = new wlQtSliderSpinBox(NULL, 3);
  h->setWhatsThis(QString::fromLocal8Bit("Definit la resolution horizontale"));
  QObject::connect(h, SIGNAL(valueChanged(int)), this->modeler, SLOT(SetHorizontalResolution(int)));
  hlayout->addWidget(h);
  tb->addWidget(wh);
  ///////////////////////////////////////////////////////////////////////////////////////
  QWidget * wul = new QWidget;
  QVBoxLayout * ullayout = new QVBoxLayout;
  wul->setLayout(ullayout);
  QLabel * lul = new QLabel(QString::fromLocal8Bit("Indicateur Ui"));
  ullayout->addWidget(lul);
  QDoubleSpinBox * ul = new QDoubleSpinBox(NULL);
  ul->setMinimum(0.0);
  ul->setMaximum(1.0);
  ul->setSingleStep(0.1);
  ul->setWhatsThis(QString::fromLocal8Bit("Spécifier une suite incrémentale monotone à valeurs entre 0 et 1"));
  QObject::connect(ul,SIGNAL(valueChanged(double)),this->modeler,SLOT(changeCurrent_ui(double)));
  //On ajoute un bouton pour valider les valeur Ul choisies
  QPushButton * ulButton = new QPushButton("Ajouter ui");
  QObject::connect(ulButton, SIGNAL(clicked()), this->modeler, SLOT(Ui_pushButtonClicked()));
  ullayout->addWidget(ul);
  ullayout->addWidget(ulButton);
  tb->addWidget(wul);
  ////////////////////////////////////////////////////////////////////////////////////////
  QWidget * wwi = new QWidget;
  QVBoxLayout * wilayout = new QVBoxLayout;
  wwi->setLayout(wilayout);
  QLabel * lwi = new QLabel(QString::fromLocal8Bit("Indicateur de WI"));
  wilayout->addWidget(lwi);
  wlQtSliderSpinBox * wi =  new wlQtSliderSpinBox(NULL,1);
  wi->setRangeAndStep(0,10,1);
  wi->setWhatsThis(QString::fromLocal8Bit("Spécifier une liste de poids à valeurs entre 0 et 10"));
  QObject::connect(h,SIGNAL(valueChanged(int)),this->modeler,SLOT(changeCurrent_wi(int)));
  //On ajoute un bouton pour valider les valeurs Wi choisies
  QPushButton * wiButton = new QPushButton("Ajouter wi");
  QObject::connect(wiButton,SIGNAL(clicked()),this->modeler,SLOT(Wi_pushButtonClicked()));
  wilayout->addWidget(wi);
  wilayout->addWidget(wiButton);
  tb->addWidget(wwi);
  ///////////////////////////////////////////////////////////////////////////////////////

  //
  // Central area
  //
  QWidget *central = new QWidget();
  QHBoxLayout *centrallayout = new QHBoxLayout;
  central->setLayout(centrallayout);
  centrallayout->addWidget(this->editor);
  centrallayout->addWidget(this->viewer);
  this->setCentralWidget(central);
  // Console
  this->console = new QTextEdit;
  this->console->setMinimumSize(QSize(100, 100));
  this->console->setReadOnly(TRUE);
  QDockWidget *w = new QDockWidget;
  w->setWidget(this->console);
  this->addDockWidget(Qt::BottomDockWidgetArea, w);
  //
  // Status bar
  this->sb = new QStatusBar;
  this->setStatusBar(this->sb);
  this->progress = new QProgressBar();
  //
  // Initialize process
  //

  //
  // Finally display everything
  //
  this->show();
  this->Trace("<- mpiProject");
}

// Charge une mesh depuis un fichier
void
mpiProject::OpenMesh()
{
  this->Trace("-> OpenMesh()");
  QString s = QFileDialog::getOpenFileName(this,
					   "Choisissez un fichier contenant un model 3D",
					   ".",
					   "Datasets (*.off)");
  if (!s.isEmpty()) {
    this->mesh->LoadMesh(s);
    emit newMeshHasBeenLoaded();
  }
  this->Trace("<- OpenMesh()");
}

// Sauvegarde une mesh dans un fichier
void
mpiProject::SaveMesh()
{
  this->Trace("-> SaveMesh()");
  QString s = QFileDialog::getSaveFileName(this,
					   "Choisissez ou creez un fichier pour sauvegarder le modele 3D",
					   ".",
					   "Datasets (*.off)");
  if (!s.isEmpty())
    this->mesh->SaveMeshAsOFF(s);
  this->Trace("<- SaveMesh()");
}

// Affiche un message decrivant les interactions possibles
void
mpiProject::Help()
{
  QString text("<h2>Interactions possibles</h2>");
  text += "<ul><li>clic gauche : ajouter un nouveau point. Le nouveau point est ins&eacute;r&eacute; entre les 2 extr&eacute;mit&eacute;s du segment le plus proche. En maintenant le bouton de la souris appuy&eacute; il est possible ensuite de d&eacute;placer le point afin de l'amener &agrave; la position voulue.</li>";
  text += "<li>clic centre : attraper un point puis maintenir le bouton de la souris enfonc&eacute; afin de le d&eacute;placer. Rel&acirc;cher le bouton lorsque le point est &agrave; la position voulue.</li>";
  text += "<li>clic droit : supprimer un point.</li></ul>";
  text += "Attention : les manipulations avec la souris ne sont valides que dans la zone sensible, &agrave; savoir le carr&eacute; dont le c&ocirc;t&eacute; gauche est mat&eacute;rialis&eacute; en noir. Lorsque la souris sort de cette zone, l'action de drag-and-drop en cours est annul&eacute;e et le sommet en cours de d&eacute;placement retrouve sa position initiale. Tout clic hors de la zone sensible est sans effet.";
  QMessageBox::information(this, QString::fromLocal8Bit("Interactions possibles"), text, QMessageBox::Ok);
}
 
// Slot : change le nombre de points en verticale.
void
mpiProject::SetNumberOfVerticalSamples()
{
  this->Trace("-> slot SetNumberOfVerticalSamples()");
  this->Message(QString("A vous de jouer !"));
  this->Trace("<- slot SetNumberOfVerticalSamples()");
}
 
// Slot : change le nombre de points en horizontale (revolution).
void
mpiProject::SetNumberOfHorizontalSamples()
{
  this->Trace("-> slot SetNumberOfHorizontalSamples()");
  this->Message(QString("A vous de jouer !"));
  this->Trace("<- slot SetNumberOfHorizontalSamples()");
}
 
void
mpiProject::Message(QString text)
{
  this->console->append(text);
}

void
mpiProject::Start(int nsteps)
{
  this->progress->setRange(0, nsteps);
  this->progress->reset();
  this->GetStatusBar()->addWidget(this->progress);
  this->ns = 0;
  this->exectime = new QTime;
  this->exectime->start();
}

void
mpiProject::Step()
{
  this->progress->setValue(++this->ns);
  if (this->ns >= this->progress->maximum()) {
    this->GetStatusBar()->removeWidget(this->progress);
    int ms = this->exectime->elapsed();
    delete this->exectime;
    this->exectime = new QTime;
    this->Message(QString("Temps d'execution : ") + this->exectime->addMSecs(ms).toString("hh:mm:ss.zzz"));
  }
}
