#include "ihmpendu.h"
#include "ui_ihmpendu.h"
#include "CUjeuDuPendu.h"
#include <iostream>
#include <QMessageBox>
#include <QFile>
#include <QSignalMapper>
#include <QObject>
#include <QString>
#include <QPushButton>
#include <QLineEdit>
#include <QMainWindow>
#include <qmessagebox.h>
#include <qfiledialog.h>
#include <qlayout.h>
#include <QtGui>
#include <QFileDialog>
using namespace std;

IHMPendu::IHMPendu(QWidget *parent): QMainWindow(parent), ui(new Ui::IHMPendu)
{
    ui->setupUi(this);
    initIHMWIDGETS();
}

IHMPendu::~IHMPendu()
{
    delete ui;
}

void IHMPendu::RecupAddJeu(class CUjeuDUPendu *jeu){
    addJeuDuPendu = jeu;
}

void IHMPendu::RecupAddFenetreConfig(QWidget* lafenetre){
    addFenetreConfig=lafenetre;
}

void IHMPendu::initIHMWIDGETS()
{
    ui->NomduFichier->setText("");
    ui->MotDisponibles->setText("");
    ui->LineEditNomDuJoueur->setEnabled(true);
    ui->Bonton_Config->setEnabled(true);
    ui->Bonton_Jouer->setEnabled(true);
    nbrcorrespondantpourlependu=1;
}

void IHMPendu::inintIHMreset()
{
    for(int y=0;y<26;y++){
        Bouton[y]->setEnabled(false);
    }
    AfficherPendu(0);
    ui->LineEditNomDuJoueur->setEnabled(true);
    boutonJOUEROnOff(1);
    boutonCONFIGOnOff(1);
    ui->LineEditNomDuJoueur->clear();
    nbrcorrespondantpourlependu=1;
}
void IHMPendu::AfficherPendu(int number){

    ui->PenduBattons->setPixmap(QPixmap("ImagePendu"+QString::number(number)+".png"));
    ui->PenduBattons->adjustSize();
}
void IHMPendu::boutonJOUEROnOff(bool joueronOff)
{
    if(joueronOff==0){
       ui->Bonton_Jouer->setEnabled(false);
    }else if (joueronOff==1){
        ui->Bonton_Jouer->setEnabled(true);
    }
}

void IHMPendu::boutonCONFIGOnOff(bool configonOff){
    if(configonOff==0){
       ui->Bonton_Config->setEnabled(false);
    }else if (configonOff==1){
        ui->Bonton_Config->setEnabled(true);
    }
}

void IHMPendu::NomsOnOff(bool nomsonOff){
    if(nomsonOff==0){
       ui->LineEditNomDuJoueur->setEnabled(false);
    }else if (nomsonOff==1){
        ui->LineEditNomDuJoueur->setEnabled(true);
    }
}

void IHMPendu::Afficher(QString motAtrouver){
    ui->LabelMotaTrouver->setText(motAtrouver);
}

void IHMPendu::AfficherNomFichierMots(QString nomfi){
    ui->NomduFichier->setText("Adresse du fichier : "+nomfi);
}

void IHMPendu::AfficherNombreDeMots(int nbrdemots){
    ui->MotDisponibles->setText("Mots disponibles "+QString::number(nbrdemots));
}

QString IHMPendu::saisirNom(){
    QString nom;
    nom=ui->LineEditNomDuJoueur->text();
    return nom;
}


void IHMPendu::on_Bonton_Jouer_clicked()
{
    QMessageBox msgBox; QString x;
    msgBox.setIcon(QMessageBox::Information);
    if (ui->LineEditNomDuJoueur->text()=="")
    {
    x="Vous avez oubliez de rentrer le nom du joueur !!!";
    msgBox.setText(x);
    msgBox.exec();
    }else if(NomDuFichierSelectionner=="")
    {
    x="Vous avez oubliez de rentrer le fichier des mots !!!";
    msgBox.setText(x);
    msgBox.exec();
    }
    if(NomDuFichierSelectionner!="" && saisirNom()!="")
    {
    ui->Bonton_Jouer->setText("REJOUER");
    addJeuDuPendu->commencerunePartie();
    }
}

void IHMPendu::slotBouton()
{
        int a=97;
        QFile leFichier("liste_mots_sans_accents.txt");
        leFichier.open(QIODevice::ReadOnly);//on va LIRE les données !
        for (int i = 0; i < 26; i++) {
            Bouton[i]=new QPushButton (QChar(a++));
            Bouton[i]->setMinimumWidth(10);
            Bouton[i]->setMinimumHeight(10);
            ui->alphabet->addWidget(Bouton[i],i/10,i%10);
            QObject::connect(Bouton[i], SIGNAL(clicked()), this, SLOT(boutonclic0()));
        }
}

void IHMPendu::boutonclic0(){
    int flag=0;
    QString lettredumot,nom,motencours,motchoisi,motfinal,x;
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Information);
    QPushButton *button = (QPushButton *)sender();
    QString lettre= button->text();
    nom = saisirNom();
    motencours = addJeuDuPendu->getmotEnCours();

    for(int m=0;m<addJeuDuPendu->getmotEnCours().size();m++)
    {
        lettredumot=motencours[m];

                if(lettredumot==lettre)
                {
                flag=1;
                button->setEnabled(false);
                motchoisi = addJeuDuPendu->getmotChoisi();
                motchoisi[m] = lettredumot[0];
                addJeuDuPendu->setMotPointilles(motchoisi);
                ui->LabelMotaTrouver->setText(motchoisi);
                motfinal= addJeuDuPendu->getmotChoisi();

                    if(ui->NBrErreurs->text()!="10" && motfinal.contains('*',Qt::CaseSensitivity())==false)
                    {
                    x="The Winner is : " + nom;
                    msgBox.setText(x);
                    msgBox.exec();
                    inintIHMreset();
                }
            }
            else
            {
            button->setEnabled(false);
            }
    }

    if (flag==0)
    {
    AfficherPendu(nbrcorrespondantpourlependu);
    ui->NBrErreurs->setText(QString::number(nbrcorrespondantpourlependu));
    nbrcorrespondantpourlependu++;

    if(ui->NBrErreurs->text()=="10")
    {
    x=nom+", Dommage, le mot initial était : "+motencours;
    msgBox.setText(x);
    msgBox.exec();
    inintIHMreset();
    }
    }
    else if(flag==1)
    {
    button->setStyleSheet("QPushButton { background-color: green; }\n"
    "QPushButton:enabled { background-color: rgb(200,0,0); }\n");
    }
}

void IHMPendu::on_Bonton_Config_clicked()
{
    QWidget* Quand_on_appuie_sur_le_bouton_fenetre_Config = new QWidget();
    Quand_on_appuie_sur_le_bouton_fenetre_Config->setFixedWidth(1000);
    Quand_on_appuie_sur_le_bouton_fenetre_Config->setFixedHeight(1000);
    Quand_on_appuie_sur_le_bouton_fenetre_Config->setWindowTitle("Configuration");

    QPushButton *button_Selectionner_fichier_dans_leboutton_config = new QPushButton("Selectionner fichier",Quand_on_appuie_sur_le_bouton_fenetre_Config);
    button_Selectionner_fichier_dans_leboutton_config->setGeometry(100,200,200,100);
    QObject::connect(button_Selectionner_fichier_dans_leboutton_config, SIGNAL(clicked()), this, SLOT(boutonclic1()));

    QPushButton *button_Quitter_dans_leboutton_config=new QPushButton("Quitter",Quand_on_appuie_sur_le_bouton_fenetre_Config);
    button_Quitter_dans_leboutton_config->setGeometry(250,200,200,100);
    QObject::connect(button_Quitter_dans_leboutton_config, SIGNAL(clicked()), this, SLOT(boutonclic2()));

    Quand_on_appuie_sur_le_bouton_fenetre_Config->show();
    RecupAddFenetreConfig(Quand_on_appuie_sur_le_bouton_fenetre_Config);
}

void IHMPendu::boutonclic1(){
    QFileDialog dialog(this);QStringList fileNames;
    dialog.setFileMode(QFileDialog::ExistingFiles);
    dialog.setNameFilter("Text files (*.txt)");
    NomDuFichierSelectionner = dialog.getOpenFileName();
    if (dialog.exec())
         fileNames = dialog.selectedFiles();
}

void IHMPendu::boutonclic2(){
    addFenetreConfig->close();
}














