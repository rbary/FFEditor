///////////////////////////////////////////////////////////////////////////////
//  File         :    wlQtSliderSpinBox.h                                    //
//  Author       :    Wilfrid LEFER                                          //
//  Comment      :    A combo QSlider-QSpinBox                               //
//  Related file :    wlQtSliderSpinBox.cxx                                  //
//                    Wilfrid Lefer - UPPA - 2006                            //
///////////////////////////////////////////////////////////////////////////////


#ifndef _WL_QT_SLIDER_SPIN_BOX_H
#define _WL_QT_SLIDER_SPIN_BOX_H

#include <QSlider>
#include <QSpinBox>
#include <wlCore.h>

class wlQtSliderSpinBox;

/** wlQtLinkedSlider implemente un slider dont l'evolution est liee a une spinbox.
    Attention : uniquement le cas de sliders horizontaux a ete traite ! Si on devait un jour
    etendre le code afin de prendre en compte le cas de sliders verticaux, il faudrait
    modifier le code des methodes mousePressEvent et mouseMoveEvent en consequence.
*/
class wlQtLinkedSlider : public QSlider, public wlCore
{
public:
  /// Construit un objet de type wlQtLinkedSlider.
  wlQtLinkedSlider(QWidget *parent, int min, int max, int step, wlQtSliderSpinBox *combo);
  /// Requis par wlCore.
  virtual char *GetClassName() {return "wlQtLinkedSlider";};

protected:
  void mousePressEvent(QMouseEvent *e);

private:
  /// Une reference a l'objet de type wlQtSliderSpinBox auquel ce slider appartient.
  wlQtSliderSpinBox *combo;
  /// Vaut 1 si on est en mode drag ou 0 sinon
  int dragging;
  /// Pour memoriser le decalage de la position de la souris par rapport au debut du curseur lors d'un drag
  float clickOffset;
};

/** wlQtLinkedSpinBox implemente une spinbox dont l'evolution est liee a un slider.
*/
class wlQtLinkedSpinBox : public QSpinBox, public wlCore
{
public:
  /// Construit un objet de type wlQtLinkedSpinBox.
  wlQtLinkedSpinBox(QWidget *parent, int min, int max, int step, wlQtSliderSpinBox *combo);
  /// Requis par wlCore.
  virtual char *GetClassName() {return "wlQtLinkedSpinBox";};

private:
  /// Une reference a l'objet de type wlQtSliderSpinBox auquel cette spinbox appartient.
  wlQtSliderSpinBox *combo;
};

/** wlQtSliderSpinBox implemente un ensemble QSlider-QSpinBox dont les valeurs sont liees.
*/
class wlQtSliderSpinBox : public QWidget, public wlCore
{
  Q_OBJECT

public:
  wlQtSliderSpinBox(QWidget *parent=NULL, int min=0, int max=100, int step=1, int debug=0);
  /// Requis par wlCore.
  virtual char *GetClassName() {return "wlQtSliderSpinBox";};

  /// Donne le minimum.
  inline int minimum() {return this->GetSpinBox()->minimum();};
  /// Donne le maximum.
  inline int maximum() {return this->GetSpinBox()->maximum();};
  /// Donne le pas.
  int singleStep() {return this->GetSpinBox()->singleStep();};
  // Pour que la taille de la widget soit correcte
  QSize sizeHint() const;
  QSize minimumSizeHint() const;

public slots:
  /// Definit les valeurs minimum, maximun et le pas.
  void setRangeAndStep(int min, int max, int step);
  /// Fixe la valeur.
  void setValue(int value);
  /// Donne la borne minimun.
  int value() {
    return this->GetSpinBox()->value();
  }

signals:
  /// Signal emis lorsque la valeur a change.
  void valueChanged(int v);

private:
  /// Acces a l'objet de type QSlider pour la borne inferieure.
  wlGetMacro(Slider, wlQtLinkedSlider *);
  /// Acces a l'objet de type QSpinBox pour la borne inferieure.
  wlGetMacro(SpinBox, wlQtLinkedSpinBox *);
  QWidget *box;

private slots:
  /// Methode appelee lorsque la valeur du slider a change.
  void sliderValueHasChanged(int value);
  /// Methode appelee lorsque la valeur de la spinbox a change.
  void spinBoxValueHasChanged(int value);
};

#endif
