#include <iostream>
#include "CUjeuAllumettes.h"
#include <QMessageBox>
using namespace std;

CUjeuAllumettes::CUjeuAllumettes(){
    ihm.RecupAddJeu(this);
    ihm.show();
    ihm.initIHM();
}

int CUjeuAllumettes::tirageAleatoire(int mini, int maxi){
    srand(time(NULL));
    nbreAllumettes = rand()%(maxi-mini)+mini;
    joueurEnCours=((rand() % (2 - 1 + 1)) + 1) -1;
    return nbreAllumettes;
}

void CUjeuAllumettes::setnbreAllumettes(int NBreAllumettes){
    nbreAllumettes = NBreAllumettes;
}

int CUjeuAllumettes::getnbreAllumettes(){
    return nbreAllumettes;
}

int CUjeuAllumettes::getjoueurEnCours(){
    return joueurEnCours;
}

void CUjeuAllumettes::ChangerJoueur(){
    if(joueurEnCours==0){
           joueurEnCours++;
       }else if(joueurEnCours==1){
           joueurEnCours--;
       }
}

void CUjeuAllumettes::commencerunepartie(){
QMessageBox msgBox;
QString x;
int FLAG=0;
nom[0]=ihm.saisirNom(0);
nom[1]=ihm.saisirNom(1);
    if(FLAG==0)
     {
     try
       {
           if(nom[0]=="" && nom[1]=="") throw 1;
           if(nom[0]=="")throw 2;
           if(nom[1]=="")throw 3;
           FLAG = 1;
       }
       catch(int y)
       {
       switch(y)
       {
           case 1 :
           x="Les deux noms ne sont pas renseignés !!";
           break;
           case 2 :
           x="Le nom du joueur numéro 1 n'est pas renseigné !!";
           break;
           case 3 :
           x="Le nom du joueur numéro 2 n'est pas renseigné !!";
           break;
           }
           msgBox.setIcon(QMessageBox::Information);
           msgBox.setText(x);
           msgBox.exec();
           FLAG = 0;
         }
    }
    if(FLAG==1)
    {
    ihm.boutonJOUERonOff(0);
    ihm.nomsOnOff(0);
    ihm.boutonOKonOff(1);
    nbreAllumettes=tirageAleatoire(5,20);
    setnbreAllumettes(nbreAllumettes);
    ihm.afficherJeuAllumettes(nbreAllumettes);
    ihm.afficherMessage(nom[joueurEnCours++]);
    ihm.NbAEnleverOnOff(1);
    }
}
