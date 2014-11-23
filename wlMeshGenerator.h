///////////////////////////////////////////////////////////////////////////////
//  File         :    wlMeshGenerator.h                                      //
//  Author       :    Wilfrid LEFER                                          //
//  Comment      :    Genere un objet 3D en tant que surface de revolution   //
//                    Accepte une liste de points qui servent de points de   //
//                    controle pour la generation du profil de type spline   //
//  Related file :    wlMeshGenerator.cxx                                    //
//                    Wilfrid Lefer - UPPA - 2007                            //
///////////////////////////////////////////////////////////////////////////////


#ifndef _WL_MESH_GENERATOR_H
#define _WL_MESH_GENERATOR_H

//#define BEZIER 1
//#define SPLINE 2

#include <wlCore.h>
#include <vector>
#include <QWidget>
#include <QPolygon>

/** \brief wlMeshGenerator genere un objet 3D en tant que surface de revolution.

    Cette classe accepte une liste de points qui servent de points de controle pour
    la generation du profil de type spline, utilise pour creer la surface de revolution.
*/
class wlMeshGenerator : public QWidget, public wlCore
{
  Q_OBJECT

public:
  /// Instancie un nouvel generateur.
  wlMeshGenerator(QWidget *parent=NULL, int debug=0);
  /// Destructeur.
  virtual ~wlMeshGenerator() {};
  /// Necessaire pour l'heritage de la classe wlCore.
  virtual char *GetClassName() {return "wlMeshGenerator";};

  /// \brief Renvoie la liste des sommets de la mesh.
  inline std::vector<std::vector<float> > GetVerticies() {return this->verts;};
  /// \brief Renvoie la liste des triangles de la mesh.
  inline std::vector<std::vector<int> > GetTriangles() {return this->triangles;};
  /// Renvoie le nombre de sommets de la mesh.
  inline int GetNumberOfVerticies() {return this->verts.size();};
  /// Renvoie le nombre de triangles de la mesh.
  inline int GetNumberOfTriangles() {return this->triangles.size();};

signals:
  void CurveHasChanged(std::vector<std::vector<float> > list);
  void MeshHasChanged(std::vector<std::vector<float> > vertices,
		      std::vector<std::vector<int> > triangles);

public slots:
  /// Fixe le type de courbe : BEZIER ou SPLINE.
  void SetCurveType(int ctype);
  /// Fixe la resolution verticale pour la generation de la mesh.
  void SetVerticalResolution(int n);
  /// Fixe la resolution horizontale pour la generation de la mesh.
  void SetHorizontalResolution(int n);
  /// Fixe les resolutions verticale et horizontale pour la generation de la mesh.
  void SetResolution(int vn, int hn);
  /// \brief Initialise la liste des points de controle.
  /// L'objet cree tient dans le cube unitaire centre en 0, les points de controle sont
  /// donc ramenes entre 0 et 1 avant traitement.
  void SetPoints(std::vector<std::vector<float> > points);
  /// Affiche le nombre de sommets et faces de la triangulation.
  void PrintSelf();
  /// Affiche la liste compl&egrave;te des simplex de la triangulation.
  void PrintContent();
  /// Reconstruit la mesh.
  void Update();

protected:
  // une fonction qui calcule une BSpline a partir de la liste des points
  virtual void ComputeShape();
  // une fonction qui construit une mesh par revolution du profil BSpline
  virtual void BuildMesh();
  // le type de courbe
  int CurveType;
  // la liste des points de controle
  std::vector<std::vector<float> > points;
  // la suite monotone incrementale Ui
  std::vector<float> Ui;
  // la resolution verticale pour la generation de la mesh
  int VerticalResolution;
  // la resolution horizontale pour la generation de la mesh
  int HorizontalResolution;
  // la liste des sommets de la mesh
  std::vector<std::vector<float> > verts;
  // la liste des faces/triangles de la mesh
  std::vector<std::vector<int> > triangles;
  // la liste des points decrivant la courbe spline
  std::vector<std::vector<float> > curve;
};

#endif
