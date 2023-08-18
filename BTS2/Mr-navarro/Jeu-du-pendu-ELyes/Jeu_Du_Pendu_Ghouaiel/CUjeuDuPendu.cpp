#include <QPushButton>
#include <iostream>
#include <QLineEdit>
#include <QMainWindow>
#include <QString>
#include <qfile.h>
#include "CUjeuDuPendu.h"
#include "ihmpendu.h"
using namespace std;

CUjeuDUPendu::CUjeuDUPendu(){
    RecupAddIHM(addIHMPendu);
}

CUjeuDUPendu::~CUjeuDUPendu()
{}


int CUjeuDUPendu::tirageAleatoire(int mini, int maxi){
    srand(time(NULL));
    int nombre = rand()%(maxi-mini)+mini;
    return nombre;
}

void CUjeuDUPendu::RecupAddIHM(class IHMPendu* ihm){
    addIHMPendu = ihm;
}

QString CUjeuDUPendu::getnomFichierDeMots(){
    return nomFichierDeMots;
}

void CUjeuDUPendu::setnomFichierDeMots(QString nomfichierdemots){
    nomFichierDeMots = nomfichierdemots;
}

int CUjeuDUPendu::getnombreErreur(){
    return nombreErreur;
}

void CUjeuDUPendu::setnombreErreur(int nbrErreurs){
    nombreErreur = nbrErreurs;
}

QString CUjeuDUPendu::getmotEnCours(){
    return motEnCours;
}

int CUjeuDUPendu::getnombredemotsdisponibles(){
    return nombreDeMotsDisponibles;
}

void CUjeuDUPendu::setnombredemotsdisponibles(int nbrdemotdispo){
    nombreDeMotsDisponibles=nbrdemotdispo;
}

void CUjeuDUPendu::setmotEnCours(QString mte){
    motEnCours=mte;
}

QString CUjeuDUPendu::getmotChoisi(){
    return motChoisi;
}

void CUjeuDUPendu::miseAJourFichierDeMots(){
    setnombredemotsdisponibles(nombreDeMotsDisponibles);
}

void CUjeuDUPendu::lireNombresdeMotsAJour(){
    QFile lefichier(nomFichierDeMots);

    lefichier.open(QIODevice::ReadOnly);

    while(lefichier.readLine()!=""){
        nombreDeMotsDisponibles++;
    }
}


void CUjeuDUPendu::commencerunePartie(){
    int numerodumotencours;
    nomJoueur= addIHMPendu->saisirNom();
    addIHMPendu->boutonJOUEROnOff(0);
    addIHMPendu->NomsOnOff(0);
    addIHMPendu->boutonCONFIGOnOff(0);
    addIHMPendu->slotBouton();
    QFile Lefichier(addIHMPendu->NomDuFichierSelectionner);
    setnomFichierDeMots(addIHMPendu->NomDuFichierSelectionner);
    Lefichier.open(QIODevice::ReadOnly);
    lireNombresdeMotsAJour();

    numerodumotencours=tirageAleatoire(1,nombreDeMotsDisponibles);

    for(int m=0;m<numerodumotencours;m++){
        motEnCours = Lefichier.readLine(nombreDeMotsDisponibles);
    }

    nomFichierDeMots=getnomFichierDeMots();
    addIHMPendu->AfficherNomFichierMots(nomFichierDeMots);
    addIHMPendu->AfficherNombreDeMots(nombreDeMotsDisponibles);

    for(int i=0;i<(motEnCours.size()-2);i++)
    {
        motChoisi = motChoisi + "*";
    }

    addIHMPendu->Afficher(motChoisi);
}

void CUjeuDUPendu::setMotPointilles(QString motchois)
{
    motChoisi = motchois;
}









