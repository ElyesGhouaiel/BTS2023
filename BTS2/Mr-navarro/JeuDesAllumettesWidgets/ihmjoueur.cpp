#include "ihmjoueur.h"
#include "ui_ihmjoueur.h"
#include "CUjeuAllumettes.h"
#include <iostream>
#include <QMessageBox>
using namespace std;
IHMjoueur::IHMjoueur(QWidget *parent): QMainWindow(parent), ui(new Ui::IHMjoueur)
{
    ui->setupUi(this);
}

IHMjoueur::~IHMjoueur()
{
    delete ui;
}

void IHMjoueur::initIHM()
{
  ui->Joueur1Nom->setText("");
  ui->Joueur2Nom->setText("");
  ui->OK->setEnabled(false);
  ui->NbAEnlever->setText("");
  ui->NbAEnlever->setEnabled(false);
  ui->zoneMessage->clear();
  ui->Jouer->setEnabled(true);
  ui->Joueur1Nom->setEnabled(true);
  ui->Joueur2Nom->setEnabled(true);
  ui->Allumettes->setText("");
}

QString IHMjoueur::saisirNom(int numerojoueur){
    QString nom;
    if(numerojoueur==0){
    nom=ui->Joueur1Nom->text();
    }else if(numerojoueur==1) {
    nom=ui->Joueur2Nom->text();
    }
    return nom;
}

void IHMjoueur::RecupAddJeu(class CUjeuAllumettes* jeu){
    addJeuAllumettes = jeu;
}

void IHMjoueur::afficherJeuAllumettes(int NbreAllumettes){
    QString ALLumettess;
    for(int i=0;i<NbreAllumettes;i++){
        ALLumettess = ALLumettess + "| ";
        ui->Allumettes->setText(ALLumettess);
    }
}

void IHMjoueur::afficherMessage(QString Message){
    ui->zoneMessage->setText(Message + " , C'est à toi de jouer !");

}

void IHMjoueur::boutonOKonOff(bool okonoff){
    if(okonoff==0){
        ui->OK->setEnabled(false);
    }else if(okonoff==1){
        ui->OK->setEnabled(true);
    }
}

void IHMjoueur::boutonJOUERonOff(bool joueronoff){
    if(joueronoff==0){
        ui->Jouer->setEnabled(false);
    }else if(joueronoff==1){
        ui->Jouer->setEnabled(true);
    }
}

void IHMjoueur::nomsOnOff(bool nomsonoff){
    if(nomsonoff == 0 ){
        ui->Joueur1Nom->setEnabled(false);
        ui->Joueur2Nom->setEnabled(false);
    }else if(nomsonoff == 1){
        ui->Joueur1Nom->setEnabled(true);
        ui->Joueur2Nom->setEnabled(true);
    }
}

void IHMjoueur::NbAEnleverOnOff(bool nbaenleveronOff){
    if (nbaenleveronOff==0){
        ui->NbAEnlever->setEnabled(false);
    }else if(nbaenleveronOff==1){
        ui->NbAEnlever->setEnabled(true);
    }
}

void IHMjoueur::on_Jouer_clicked()
{
    addJeuAllumettes->commencerunepartie();
}

void IHMjoueur::on_OK_clicked()
{
    int nbrsupprimes,nbrtotal,nbrallumettes,joueurencours,flag=0;
    QString nom[2],x;
    QMessageBox msgBox;

    nom[0]= ui->Joueur1Nom->text();
    nom[1]= ui->Joueur2Nom->text();

    nbrallumettes=addJeuAllumettes->getnbreAllumettes();

    joueurencours=addJeuAllumettes->getjoueurEnCours();

    nbrsupprimes=ui->NbAEnlever->text().toInt();

    nbrtotal = nbrallumettes-nbrsupprimes;

    if (flag==0){
        try
        {
        if(ui->NbAEnlever->text().isEmpty())        throw 1;

        if(nbrsupprimes<1 || nbrsupprimes>3)        throw 2;

        if(nbrsupprimes>nbrallumettes)              throw 3;

        if (nbrtotal==0 &&  joueurencours==1) throw 4;

        if (nbrtotal==0 && joueurencours==0) throw 5;

        addJeuAllumettes->setnbreAllumettes(nbrtotal);

        afficherJeuAllumettes(nbrtotal);

        addJeuAllumettes->ChangerJoueur();

        afficherMessage(nom[joueurencours]);

        ui->NbAEnlever->clear();

        flag = 1;
        }
        catch (int y)
        {
        switch(y)
        {
        case 1 :
            x = "Erreur ! Saisie vide";
            break;

        case 2 :
            x = "Vous n'avez pas rentré un chiffre entre 1 et 3 !!";
            break;

        case 3 :
            x = "Vous voulez enlever trop d'allumettes ";
            break;

        case 4:

            x="le vainqueur est " + nom[1];
            initIHM();
            break;

        case 5:

             x="le vainqueur est "+ nom[0];
             initIHM();
            break;
        }
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setText(x);
        msgBox.exec();
        flag=0;
        }
    }
}
