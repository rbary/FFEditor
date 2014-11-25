///////////////////////////////////////////////////////////////////////////////
//  File         :    wlMeshGeneratorStudents.h                              //
//  Author       :    Wilfrid LEFER                                          //
//  Comment      :    Genere un objet 3D en tant que surface de revolution   //
//                    Accepte une liste de points qui servent de points de   //
//                    controle pour la generation du profil de type spline   //
//                    Cette classe permet de redefinir uniquement les        //
//                    methodes ComputeShape() et BuildMesh() que doivent     //
//                    ecrire les etudiants dans le cadre de leur TP          //
//  Related file :    wlMeshGeneratorStudents.cxx, wlMeshGenerator.{h,cxx}   //
//                    Wilfrid Lefer - UPPA - 2007                            //
///////////////////////////////////////////////////////////////////////////////


#ifndef _WL_MESH_GENERATOR_STUDENTS_H
#define _WL_MESH_GENERATOR_STUDENTS_H

#include <wlMeshGenerator.h>
#include <vector>
#include <QMessageBox>
#include <iostream>
#include <glm/glm/gtx/rotate_vector.hpp>
using namespace std;


#define BEZIER 0
#define BSPLINE 1
#define NURBS 2

/** \brief wlMeshGeneratorStudents genere un objet 3D en tant que surface de revolution.

    Cette classe accepte une liste de points qui servent de points de controle pour
    la generation du profil de type spline, utilise pour creer la surface de revolution.
    Elle permet de redefinir uniquement les methodes ComputeShape() et BuildMesh() que
    doivent ecrire les etudiants dans le cadre de leur TP.
*/
class wlMeshGeneratorStudents : public wlMeshGenerator
{
  Q_OBJECT

public:
  /// Instancie un nouvel generateur.
  wlMeshGeneratorStudents(QWidget *parent=NULL, int debug=0);
  /// Destructeur.
  virtual ~wlMeshGeneratorStudents() {};
  /// Necessaire pour l'heritage de la classe wlCore.
  virtual char *GetClassName() {return "wlMeshGeneratorStudents";};

public slots:
  /// Initialise le type de courbe: BEZIER par defaut
  void initializations();
  /// Fixe le type de courbe : BEZIER, SPLINE ou NURBS par Signal
  void SetTheTypeOfCurve(int typeOfCurve);
  /// change la valeur de current_u
  void changeCurrent_ui(double a_u);
  /// change la valeur de current_w
  void changeCurrent_wi(int a_w);
  /// Ajoute un u a la suite incrémentale Ui
  void addCurrent_uiToUi();
  /// Methode appelee par un click de "Ajouter ui"
  void Ui_pushButtonClicked();
  /// methode appelee par un click de "Ajouter wi"
  void Wi_pushButtonClicked();
  /// ajoute la valeur de current_w
  void addCurrent_wiToWi();
  /// Affichage par parcours d'un vecteur lambda
  void afficheVector(std::vector<int> vectorToDisplay);
  // Scale computing
  float computeScale(std::vector<std::vector<float> > a_curve);
  // Calcul de tous les vertex
  void vertexComputing(int rh, std::vector<std::vector<float> > a_curve);
  // Calcul de lignes (tableaux d'indices) pour faciliter le calcul des triangles
  void linesComputing(std::vector<int> al);
  // Calcul des triangles pour la realisation de la mesh
  void trianglesComputing();

protected:
  //Conteneur pour stacker tous les points
  std::vector<std::vector<float> > Vtx;
  //Conteneur pour stocker les indices des points par paliers
  std::vector<std::vector<int> > lines;
  //Conteneur pour stocker les triangles calcules
  std::vector<std::vector<int> > Trgls;
  //La nouvelle curve
  std::vector<std::vector<float> > newCurve;
  //valeur courante de u
  double current_u;
  //valeur courrante de w
  int current_w;
  //stockage des differentes valeurs wi associees au points de controles
  std::vector<int> Wi;
  //Message
  QMessageBox * message;

private:
  // une fonction qui calcule une courbe
  void ComputeShape();
  // une fonction qui calcule une courbe de Bézier
  void ComputeShapeBezier();
  // une fonction qui calcule une BSpline a partir de la liste des points
  void ComputeShapeBSpline();
  // une fonction qui calcule une NURBS
  void ComputeShapeNURBS();
  // une fonction qui construit une mesh par revolution du profil BSpline
  void BuildMesh();
  // une fonction récursive de calcul des fonctions de mélange pour B-Spline
  float bsplineFn(float u,int k,int i);
  // Fonction de calcul de la fonction de melange pour NURBS utilisant bsplineFn
  float NURBSFn(float u, int k, int j);
};
#endif
