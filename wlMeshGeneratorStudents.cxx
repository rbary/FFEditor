///////////////////////////////////////////////////////////////////////////////
//  File         :    wlMeshGeneratorStudents.cxx                            //
//  Author       :    Wilfrid LEFER                                          //
//  Comment      :    Genere un objet 3D en tant que surface de revolution   //
//                    Accepte une liste de points qui servent de points de   //
//                    controle pour la generation du profil de type spline   //
//                    Cette classe permet de redefinir uniquement les        //
//                    methodes ComputeShape() et BuildMesh() que doivent     //
//                    ecrire les etudiants dans le cadre de leur TP          //
//  Related file :    wlMeshGeneratorStudents.h, wlMeshGenerator.{h,cxx}     //
//                    Wilfrid Lefer - UPPA - 2007                            //
///////////////////////////////////////////////////////////////////////////////


#include <wlMeshGeneratorStudents.h>
#include <math.h>
#include <cmath>
#include <QDebug>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define K 3 // le degre de la courbe

wlMeshGeneratorStudents::wlMeshGeneratorStudents(QWidget *parent, int debug)
  : wlMeshGenerator(parent, debug)
{
  this->Trace("-> wlMeshGeneratorStudents(%p)", parent);
  this->Trace("<- wlMeshGeneratorStudents()");
  //On effectue  quelques initialisations
  this->initializations();

}

void wlMeshGeneratorStudents::initializations()
{
    CurveType=BEZIER; //On initalise le type de la courbe (BEZIER)
    //On initialise current_u
    current_u=0;
    //On initialise current_w
    current_w=1;
    //On initialise la suite incrementale
    Ui.push_back(0);
    Ui.push_back(0);
    Ui.push_back(0);
    Ui.push_back(0);
    //Ui.push_back(0);
    Ui.push_back(1);
    Ui.push_back(1);
    Ui.push_back(1);
    Ui.push_back(1.0001);

    //on initialise le vecteurs de poids
    Wi.push_back(1);
    Wi.push_back(1);
    this->afficheVector(Wi);
}

void wlMeshGeneratorStudents::changeCurrent_ui(double a_u)
{
    current_u=a_u;
}

void wlMeshGeneratorStudents::changeCurrent_wi(int a_w){
    current_w=a_w;
}

void wlMeshGeneratorStudents::Ui_pushButtonClicked(){
    addCurrent_uiToUi();
}

void wlMeshGeneratorStudents::Wi_pushButtonClicked(){
    addCurrent_wiToWi();
}

void wlMeshGeneratorStudents::addCurrent_uiToUi(){
    //On ajoute la valeur courante de l'indicateur Ui a la suite incrementale Ui
    this->Ui.push_back((float)this->current_u);
    //On met a jour la croissance de la suite incrementale
    std::sort(Ui.begin(),Ui.end());
    this->Update();
}

void wlMeshGeneratorStudents::addCurrent_wiToWi(){
    //On ajoute la valeur courante de l'indicateur Wi au tableau Wi
    if(this->points.size() > this->Wi.size()){
        this->Wi.insert(Wi.end()-1,current_w);
        this->afficheVector(Wi);
    }else{
        message = new QMessageBox();
        message->setText("** Poids non pris en compte \n** Il y a deja autant de points de controles que de poids");
        message->exec();
    }
    this->Update();
}

void wlMeshGeneratorStudents::SetTheTypeOfCurve(int typeOfCurve)
{
    switch(typeOfCurve){
        case 0:
            this->CurveType=BEZIER;
            Print("Curve type: Bézier");
            break;
        case 1:
            this->CurveType=BSPLINE;
            Print("Curve Type: BSpline");
            break;
        case 2:
            this->CurveType=NURBS;
            Print("Curve Type: NURBS");
            break;
        defaUit:
            return;
            break;
    }
}

void wlMeshGeneratorStudents::ComputeShape()
{
    switch(this->CurveType){
        case 0:
            this->ComputeShapeBezier();
            break;
        case 1:
            this->ComputeShapeBSpline();
            break;
        case 2:
            this->ComputeShapeNURBS();
            break;
        default:
            return;
            break;
    }
}


void wlMeshGeneratorStudents::ComputeShapeBezier()
{
    if (this->points.size() < 4 || this->UpToDate(0))
      return;
    this->Trace("-> ComputeShapeBezier()");
    this->curve.clear();
    // calcule des points de la courbe
    //
    // on calcule une courbe de Bezier par groupe de 4 points mais comme il faut un point commun
    // entre chaque paire de groupes consecutifs, cela donne donc des groupes de 3
    // les points en sus d'un mUitiple de 3 ne sont pas traites
    // nc est le nombre de courbes a generer
    int nc = (this->points.size() - 1) / 3;
    // du est l'increment de la variable parametrique u entre 2 points d'echantillonnage consecutifs
    // on va faire varier u entre 0 et n, ce qui le fera varier entre 0 et 1 sur chaque courbe
    float du = (float)nc / (this->VerticalResolution-1);
    // i est l'indice du premier point de controle de cette courbe
    int i=0;
    float u=0;
    nc = nc * 3 - 4;
    for (int n=this->VerticalResolution ; n>0 ; n--,u+=du) {
      // si u passe une unite on doit changer de courbe
      while (u>1 && i<nc) {
        i += 3;
        u -= 1;
      }
      // on calcule les fonctions de melange
      float hu[4];
      hu[0] = (1 - u) * (1 - u) * (1 - u);
      hu[1] = 3 * (1 - u) * (1 - u) * u;
      hu[2] = 3 * (1 - u) * u * u;
      hu[3] = u * u * u;
      // on cree un nouveau point
      std::vector<float> Pu(2, 0);
      // dont on calcule la valeur par la formule de Bezier
      for (unsigned int j=0 ; j<4 ; j++) {
        if (i+j >= this->points.size()) {
      this->Error("tentative d'acces au dela de la fin du tableau points : %d contre taille = %d", i+j, this->points.size());
      return;
        }
        Pu[0] += hu[j] * this->points[i+j][0];
        Pu[1] += hu[j] * this->points[i+j][1];
      }
      // on ajoute le nouveau point a la definition de la courbe
      this->curve.push_back(Pu);
    }
    this->Trace("<- ComputeShapeBezier()");

}

void wlMeshGeneratorStudents::ComputeShapeBSpline()
{
    if (this->points.size()< 4)
        return;

    this->Trace("<- ComputeShapeBSpline()");
    float du =(float)1/(this->VerticalResolution-1);
    float u=0;

    if(this->Ui.size() > this->points.size()){
        this->curve.clear();
        //On calcule la variation de u
        for (int vr=this->VerticalResolution ; vr>0 ; vr--,u+=du) {
                //on cree un point quelconque
                std::vector<float> Pu(2,0);
                for(unsigned int j=0;j<points.size();j++){
                    float bsplineFnVal;
                        bsplineFnVal=bsplineFn(u,K,j);
                        Pu[0] += bsplineFnVal * this->points[j][0];
                        Pu[1] += bsplineFnVal * this->points[j][1];
                }
                //On ajoute la nouvelle definition de la courbe
                this->curve.push_back(Pu);
         }

        if(this->points.size()<this->Ui.size()-K-1)
        {
            message = new QMessageBox();
            QString messNbui=QString::number(this->Ui.size());
            QString messNbpts=QString::number(this->points.size());
            QString diffpts=QString::number((this->Ui.size()-K-1)-this->points.size());
            QString atext = QString("**"+messNbpts+" points de controles\n** "+messNbui+" valeurs de la suite Ui\n>> Incoherence.\n Veuillez rajouter "+diffpts+" points de controles");
            message->setText(atext);
            message->exec();
        }

        if(this->Ui.size()<this->points.size()+K+1)
        {
            message = new QMessageBox();
            QString messNbui=QString::number(this->Ui.size());
            QString messNbpts=QString::number(this->points.size());
            QString diffui=QString::number((this->points.size()+K+1)-this->Ui.size());
            QString atext = QString("**"+messNbui+" valeurs de la suite Ui\n**"+messNbpts+" points de controle\n>> Incoherence.\n Veuillez rajouter "+diffui+" valeurs a la suite Ui");
            message->setText(atext);
            message->exec();
        }
    }
    this->Trace("<- ComputeShapeBSpline()");
}

void wlMeshGeneratorStudents::ComputeShapeNURBS()
{
    if (this->points.size()<4)
        return;

    this->Trace("<- ComputeShapeNURBS()");
    this->curve.clear();
    float du =(float)1/(this->VerticalResolution-1);
    float u=0;

    if(this->Ui.size() > this->points.size() || this->Wi.size() == this->points.size()){
        for (int vr=this->VerticalResolution ; vr>0 ; vr--,u+=du) {
                       //on cree un point quelconque
                       std::vector<float> Pu(2,0);
                       for(unsigned int j=0;j<points.size();j++){
                               Pu[0] += NURBSFn(u,K,j) * this->points[j][0];
                               Pu[1] += NURBSFn(u,K,j) * this->points[j][1];
                       }
                       //On ajoute la nouvelle definition de la courbe
                       this->curve.push_back(Pu);
                }
            this->Trace("<- ComputeShapeNURBS()");
    }

    if(this->Wi.size() != this->points.size()){
        message = new QMessageBox();
        QString messNbwToAdd=QString::number(this->points.size()-this->Wi.size());
        QString atext = QString("** Veuillez associer des poids aux "+messNbwToAdd+" derniers points");
        message->setText(atext);
        message->exec();
    }

    if(this->points.size()<this->Ui.size()-K-1)
    {
        message = new QMessageBox();
        QString messNbui=QString::number(this->Ui.size());
        QString messNbpts=QString::number(this->points.size());
        QString diffpts=QString::number((this->Ui.size()-K-1)-this->points.size());
        QString atext = QString("**"+messNbpts+" points de controles\n** "+messNbui+" valeurs de la suite Ui\n>> Incoherence.\n Veuillez rajouter "+diffpts+" points de controles");
        message->setText(atext);
        message->exec();
    }

    if(this->Ui.size()<this->points.size()+K+1)
    {
        message = new QMessageBox();
        QString messNbui=QString::number(this->Ui.size());
        QString messNbpts=QString::number(this->points.size());
        QString diffui=QString::number((this->points.size()+K+1)-this->Ui.size());
        QString atext = QString("** "+messNbui+" valeurs de la suite Ui\n** "+messNbpts+" points de controle\n>> Incoherence.\n Veuillez rajouter "+diffui+" valeurs a la suite Ui");
        message->setText(atext);
        message->exec();
    }
}

float wlMeshGeneratorStudents::NURBSFn(float u, int k, int j){
    float denom=0;
    for(int i=0;i<points.size();i++)
         denom+=bsplineFn(u,K,i) * Wi[i];
    return bsplineFn(u,K,j) * Wi[j]/denom;
}

float wlMeshGeneratorStudents::bsplineFn(float u, int k, int i)
{
    float a,b,c,d,coeff1,coeff2;
    if(k==0){
        if(Ui[i]<=Ui[i+1] && u>=Ui[i] && u<Ui[i+1]){
            return 1;
        }else
        {
            return 0;
        }
    }else{

            a=(float)u-Ui[i];
            b=(float)Ui[i+k]-Ui[i];
            c=(float)Ui[i+k+1]-u;
            d=(float)Ui[i+k+1]-Ui[i+1];

            //On calcule le coefficient1
            if((a==0 && b!=0) || (b==0 && a!=0) || (a==0 && b==0)){
                coeff1=(float)0;
            }
            if(a!=0 && b!=0){
                coeff1=(float)a/b;
            }
            //On calcule le coefficient2
            if((c==0 && d!=0) || (d==0 && c!=0) || (c==0 && d==0)){
                coeff2=(float)0;
            }
            if(c!=0 && d!=0){
                coeff2=(float)c/d;
            }
            if(isnan((coeff1*bsplineFn(u,k-1,i)+coeff2*bsplineFn(u,k-1,i+1))))
                return 0;
            return (coeff1*bsplineFn(u,k-1,i)+coeff2*bsplineFn(u,k-1,i+1));
    }
}

void wlMeshGeneratorStudents::afficheVector(std::vector<int> vectorToDisplay){
    for(int i=0;i<vectorToDisplay.size();i++){
        Print("%d",vectorToDisplay[i]);
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////
void
wlMeshGeneratorStudents::BuildMesh()
{
    if (this->points.size()<4)
        return;

    //Recuperation des points de la courbe
    std::vector<std::vector<float> > curveTemp;
    for(int i=0;i<curve.size();i++){
        curveTemp.push_back(curve[i]);
    }


      int nbCurvePoints=curveTemp.size();

      //affichage des points recuperes
      for(int i=0;i<curveTemp.size();i++){
          cout<<"x: "<<curveTemp[i][0]<<" y: "<<curveTemp[i][1]<<endl;
       }

      //Translation
      for(int i=0;i<curveTemp.size();i++){
      curveTemp[i][0]=curveTemp[i][0]-20;
      curveTemp[i][1]=curveTemp[i][1]-50;
      }
      //mise a echelle et rotation de l'axe Oy/Oz
      float a_scale=computeScale(curveTemp);
      cout<<"Scale value : "<<a_scale<<endl;
      for(int i=0;i<curveTemp.size();i++){
        curveTemp[i][0]= curveTemp[i][0]/(2 * a_scale);
        curveTemp[i][1]=(-1) * curveTemp[i][1]/(2 * a_scale);
      }

      //Récupération de la résolution horizontale
      int rh=wlMeshGenerator::HorizontalResolution;

      //On calcule tous les points par revolution du profil autor de l'axe Oy
      vertexComputing(rh,curveTemp);
      trianglesComputing();

      //affichage de tous les vertex calcules
      cout<<"Affichage de tous les vertex calculees"<<endl;
      for(unsigned int i=0;i<Vtx.size();i++){
          cout<<Vtx[i][0]<<"|"<<Vtx[i][1]<<"|"<<Vtx[i][2]<<endl;
      }

      //affichage des valeurs de lines
      /*for(unsigned int i=0;i<lines.size();i++){
          for(unsigned int j=0;j<lines[i].size();j++){
              cout<<lines[i][j];
          }
          cout<<">"<<endl;
      }*/
      /////////////////////////////////////////////////////////////////
      verts.clear();
      for(unsigned int i=0;i<Vtx.size();i++){
          verts.push_back(Vtx[i]);
      }

      triangles.clear();
      for(unsigned int i=0;i<Trgls.size();i++){
          triangles.push_back(Trgls[i]);
      }

      cout<<"Affichage de tous les vertex calculees et trouvees dans verts"<<endl;
      for(unsigned int i=0;i<Vtx.size();i++){
          cout<<Vtx[i][0]<<"|"<<Vtx[i][1]<<"|"<<Vtx[i][2]<<endl;
      }

      cout<<"Affichage des indices des triangles calcules"<<endl;
      for(unsigned int i=0;i<Trgls.size();i++){
          cout<<Trgls[i][0]<<"|"<<Trgls[i][1]<<"|"<<Trgls[i][2]<<endl;
      }

      Vtx.clear();
      Trgls.clear();
      wlMeshGenerator::BuildMesh();
      wlMeshGenerator::PrintContent();
}

float wlMeshGeneratorStudents::computeScale(std::vector<std::vector<float> > a_curve){
      float maxValue=0;
      float scale=0;
      for(int i=0;i<a_curve.size();i++){
          for(int j=0;j<a_curve[i].size();j++){
              maxValue=std::max(maxValue,a_curve[i][j]);
          }
      }
      scale=maxValue;
      return scale;
}

void wlMeshGeneratorStudents::vertexComputing(int rh, std::vector<std::vector<float> > a_curve){
  float angleV=360/rh;
  float angle=0;

  std::vector<float> aVtx(3,0);
  std::vector<int> aLine;

  Vtx.push_back(a_curve[0]);
  aLine.push_back(Vtx.size()-1);
  linesComputing(aLine);
  aLine.clear();

  for(unsigned int i=0;i<rh;i++){
      for(unsigned int i=1;i<(a_curve.size()-1);i++){
            glm::vec3 VtxToRotate(a_curve[i][0],a_curve[i][1],0);
            glm::vec3 VtxRotated = glm::rotateY(VtxToRotate,angle);
            aVtx[0]=VtxRotated[0];
            aVtx[1]=VtxRotated[1];
            aVtx[2]=VtxRotated[2];

            Vtx.push_back(aVtx);
            aLine.push_back(Vtx.size()-1);
      }
            angle += angleV;
  }
  linesComputing(aLine);
  aLine.clear();
  Vtx.push_back(a_curve[a_curve.size()-1]);
  aLine.push_back(Vtx.size()-1);
  linesComputing(aLine);
  aLine.clear();
}

void wlMeshGeneratorStudents::linesComputing(std::vector<int> al){
    lines.push_back(al);
}

void wlMeshGeneratorStudents::trianglesComputing(){
    std::vector<int> index;
    cout<<"Triangles computing"<<endl;
    int vr=VerticalResolution;

    if(vr < 3){
        cout<<"Vertical resolution est plus grand que 3 je fais le traitement adequat"<<endl;


        /*for(unsigned int i=1;i<(line.size()-2);i++){
            for(unsigned int j=0;j<lines[i].size();j++){
                        aTrgl.push_back(line[i][j]);
                        aTrgl.push_back(line[i+1][j]);
                        aTrgl.push_back(line[i][j+1]);
                        Trgls.push_back(aTrgl);
                        aTrgl.clear();

                        aTrgl.push_back(lines[i][j+1]);
                        aTrgl.push_back(lines[i+1][j]);
                        aTrgl.push_back(lines[i+1][j+1]);
                        Trgls.push_back(aTrgl);
                        aTrgl.clear();
            }*/
    }

    int l1=lines[1].size();
    for(unsigned int i=0;i<lines[1].size();i++){
          index.push_back(lines[0][0]);
          index.push_back(lines[1][(i+1)% l1]);
          index.push_back(lines[1][i]);
          Trgls.push_back(index);
          index.clear();
    }

    for(unsigned int i=0;i<lines[1].size();i++){
          index.push_back(lines[2][0]);
          index.push_back(lines[1][i]);
          index.push_back(lines[1][(i+1)% l1]);
          Trgls.push_back(index);
          index.clear();
    }

    cout<<"Calcul des triangles ok//"<<endl;
}


