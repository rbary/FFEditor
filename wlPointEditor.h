///////////////////////////////////////////////////////////////////////////////
//  File         :    wlPointEditor.h                                        //
//  Author       :    Wilfrid LEFER                                          //
//  Comment      :    Canvas pour la saisie de points dans le plan           //
//  Related file :    wlPointEditor.cxx                                      //
//                    Wilfrid Lefer - UPPA - 2007                            //
///////////////////////////////////////////////////////////////////////////////


#ifndef _WL_POINT_EDITOR_H
#define _WL_POINT_EDITOR_H

#include <wlCore.h>
#include <QMenu>
#include <QWidget>
#include <QPolygon>
#include <QMouseEvent>

// taille de la fenetre par defaut
#define XSIZE 600
#define YSIZE 600
// tolerance au pointage de la souris, en nombre de pixels
#define MOUSE_THRESHOLD 25

/// \todo recalculer mouse_threshold lors des resize()

/** \brief wlPointEditor implemente un canvas permettant de saisir des points dans le plan.

    Les opérations support&eacute;es sont les suivantes :<br>
    &nbsp;&nbsp;&nbsp; - bouton gauche : cr&eacute;tion d'un nouveau point
    &agrave; l'emplacement de la souris,<br>
    &nbsp;&nbsp;&nbsp; - bouton central : s&eacute;lection puis d&eacute;placement
    d'un point existant (maintenir le bouton enfonc&eacute; pendant le d&eacute;placement),<br>
    &nbsp;&nbsp;&nbsp; - bouton droit : d&eacute;finition de l'altitude d'un point existant (si 2,5D).
*/
class wlPointEditor : public QWidget, public wlCore
{
  Q_OBJECT

public:
  /// Instancie un nouvel editeur.
  wlPointEditor(QWidget *parent=NULL, QSize size=QSize(), int debug=0);
  /// Destructeur.
  virtual ~wlPointEditor() {};
  /// Necessaire pour l'heritage de la classe wlCore.
  virtual char *GetClassName() {return "wlPointEditor";};
  /// Affiche le nombre de sommets saisis.
  void PrintSelf();

  /// Renvoie la taille preferee pour la fenetre.
  virtual QSize sizeHint() const {return this->PreferredSize;};
  /// Renvoie la taille minimale souhaitee pour la fenetre.
  virtual QSize minimumSizeHint() const {return this->PreferredSize;};
  /// \brief Renvoie la taille preferee pour la hauteur de la fenetre, en fonction de sa largeur.
  /// Permet de conserver des proportions constantes pour la fenetre (carre en l'occurrence).
  int heightForWidth(int w) {return w;};

  /// Renvoie la liste des liste des points cr&eacute;&eacute;s.
  std::vector<std::vector<float> > GetPoints();
  /// Reinitialise le dessin.
  void Clear();

signals:
  void PointListHasChanged(std::vector<std::vector<float> > list);

public slots:
  /// Affiche les coordonn&eaxute;es de tous les sommets saisis.
  void PrintContent();
  /// Associe une courbe sous forme de liste de points.
  void SetCurve(std::vector<std::vector<float> > points);

protected slots:
  /// La routine de dessin.
  void paintEvent(QPaintEvent *e);

protected:
  /// \brief Le slot de d&nbsp;clanchement d'une op&nbsp;ration.
  /// Les opérations support&eacute;es sont les suivantes :<br>
  /// &nbsp;&nbsp;&nbsp; - bouton gauche : cr&eacute;tion d'un nouveau point
  /// &agrave; l'emplacement de la souris,<br>
  /// &nbsp;&nbsp;&nbsp; - bouton central : s&eacute;lection puis d&eacute;placement
  /// d'un point existant (maintenir le bouton enfonc&eacute; pendant le d&eacute;placement),<br>
  /// &nbsp;&nbsp;&nbsp; - bouton droit : d&eacute;finition de l'altitude d'un point existant.
  void mousePressEvent(QMouseEvent *);
  /// \brief Le slot de traitement de l'&eacute;v&egrave;nement de d&eacute;placement de la souris.
  /// Actif uniquement lorsque le bouton central est maintenu enfonc&eacute; :
  /// le point s&eacute;lectionn&eacute; est alors d&eacute;plac&eacute; avec le pointeur.
  void mouseMoveEvent(QMouseEvent *);
  /// \brief Le slot de traitement du rel&acirc;lechement d'un bouton de la souris.
  /// Actif uniquement lorsque le bouton central &eacute;tait maintenu enfonc&eacute; :
  /// met alors fin au mouvement de d&eacute;placement du point s&eacute;lectionn&eacute;.
  void mouseReleaseEvent(QMouseEvent *);

private:
  /// Renvoie le point sous le pointeur de la souris.
  QPolygonF::iterator indexAt(QPointF pos);
  /// Calcule la distance d'un point a un segment de droite.
  float CalculeDistPointSegment(QPointF P, QPointF P0, QPointF P1);

  // la taille pr&eacute;f&eacute;r&eacute;e de la fen&ecirc;tre
  QSize PreferredSize;
  // la tolerance au pointage de la souris pour attraper les points
  // si aucun point dans le voisinage de la souris a une distance
  // inferieure ou egale a ce seuil, aucun point ne sera selectionne
  // le seuil est stocke en coordonnees normalisees, a partir de
  // MOUSE_THRESHOLD, qui est lui donne en coordonnees ecran
  float mouse_threshold;
  // les points
  QPolygonF points;
  // le point selectionne (en cours de deplacement)
  QPolygonF::iterator selected;
  // la courbe spline sous forme de liste de paires de points
  QVector<QPointF> curve;
  // la position de la souris lors du clic initial d'une operation de deplacement de sommet
  QPointF originalpos;
  // la position de la souris lors du dernier evenement traite
  QPointF oldpos;
  // la liste des points saisis
  std::vector<std::vector<float> > liste;
};

#endif
