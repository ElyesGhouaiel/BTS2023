#include "ihm_bataille_navale_2.h"
#include "ui_ihm_bataille_navale_2.h"
#include <iostream>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
using namespace std;

IHM_Bataille_Navale_2::IHM_Bataille_Navale_2(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::IHM_Bataille_Navale_2)
{
    ui->setupUi(this);
    Start();
}

IHM_Bataille_Navale_2::~IHM_Bataille_Navale_2()
{
    delete ui;
}

void IHM_Bataille_Navale_2::constructiondutableau_joueur1(){
int coordonnesx_joueur1=1,
    coordonnesy_joueur1=1,
    lettredelalphabetAafficher=65,
    chiffreAafficher=48;

    for (int x = 4; x < 14; x++) {
        for (int y = 3; y < 13; y++) {
            bouton_joueur1[coordonnesx_joueur1][coordonnesy_joueur1]= new QPushButton((QString(lettredelalphabetAafficher)+chiffreAafficher++),centralWidget());
            bouton_joueur1[coordonnesx_joueur1][coordonnesy_joueur1]->setGeometry(42*x,42*y,42,42);
            coordonnesy_joueur1++;
            QObject::connect(bouton_joueur1[coordonnesx_joueur1][coordonnesy_joueur1], SIGNAL(clicked()), this, SLOT(boutonclic0()));
        }
        coordonnesx_joueur1++;
        lettredelalphabetAafficher++;
        chiffreAafficher=48;
    }
}

void IHM_Bataille_Navale_2::boutonclic0(){
int x=1,y=1;
    QPushButton *boutton_1 = (QPushButton*)sender();
    for (int x = 1; x < 11; x++) {
        for (int y = 1; y < 11; y++) {
            if(boutton_1==RecupPointeurs[x][y]){
    boutton_1->setStyleSheet("QPushButton { background-color:  normal; }\n"
                             "QPushButton:enabled { background-color: rgb(0,255,0); }\n");}
        }
    }if (VerificationDesBoutons[x][y]==0) {
        boutton_1->setStyleSheet("QPushButton { background-color:  normal; }\n"
                                 "QPushButton:disable { background-color: rgb(255,255,0); }\n");
    }
    //bouton_joueur1[10][10]->setStyleSheet("background-color: black;");
}

void IHM_Bataille_Navale_2::constructiondutableau_joueur2(){
int coordonnesx_joueur2=1,coordonnesy_joueur2=1,lettredelalphabetAafficher=65,chiffreAafficher=48;
    for (int x = 15; x < 26; x++) {
            for (int y = 3; y < 13; y++) {
                bouton_joueur2[coordonnesx_joueur2][coordonnesy_joueur2]= new QPushButton((QString(lettredelalphabetAafficher)+chiffreAafficher++),centralWidget());;
                bouton_joueur2[coordonnesx_joueur2][coordonnesy_joueur2]->setGeometry(42*x,42*y,42,42);
                coordonnesy_joueur2++;
               // QObject::connect(bouton_joueur2[coordonnesx_joueur2][coordonnesy_joueur2], SIGNAL(clicked()), this, SLOT(boutonclic1()));
            }
            coordonnesx_joueur2++;
            lettredelalphabetAafficher++;
            chiffreAafficher=48;
    }
}

void IHM_Bataille_Navale_2::boutonclic1(){

    QPushButton *boutton_2 = (QPushButton*)sender();
    for (int x = 1; x < 11; x++) {
        for (int y = 1; y < 11; y++) {
    boutton_2->setStyleSheet("QPushButton { background-color:  normal; }\n"
                             "QPushButton:enabled { background-color: rgb(0,255,0); }\n");
        }
    }
    //bouton_joueur2[10][10]->setStyleSheet("background-color: black;");
}


void IHM_Bataille_Navale_2::boutonsAllieOnOff(){
    for (int a=0;a<10;a++)
    {
        for(int z=0;z<10;z++)
        {
            if(VerificationDesBoutons[a][z]==0){
            bouton_joueur1[a][z]->setEnabled(false);
            }else{
            bouton_joueur1[a][z]->setEnabled(true);
            }
        }
    }
}

void IHM_Bataille_Navale_2::Start(){

    constructiondutableau_joueur1();
    constructiondutableau_joueur2();

    QPushButton *Porteavion=new QPushButton("Porteavion",centralWidget());
    Porteavion->setGeometry(0,100,100,50);//positionH, positionV, tailleH, tailleV
    Porteavion->setEnabled(true);
    //QObject::connect(Porteavion, SIGNAL(clicked()), this, SLOT(porteAvion()));

    QPushButton *Croiseur=new QPushButton("Croiseur",centralWidget());
    Croiseur->setGeometry(0,150,100,50);//positionH, positionV, tailleH, tailleV
    Croiseur->setEnabled(true);
    //QObject::connect(Croiseur, SIGNAL(clicked()), this, SLOT(centralWidget()));

    QPushButton *ContreTorpilleur_1=new QPushButton("ContreTorpilleur_1",centralWidget());
    ContreTorpilleur_1->setGeometry(0,200,100,50);//positionH, positionV, tailleH, tailleV
    ContreTorpilleur_1->setEnabled(true);
    //QObject::connect(ContreTorpilleur_1, SIGNAL(clicked()), this, SLOT(contretorpilleur1()));

    QPushButton *ContreTorpilleur_2=new QPushButton("ContreTorpilleur_2",centralWidget());
    ContreTorpilleur_2->setGeometry(0,250,100,50);//positionH, positionV, tailleH, tailleV
    ContreTorpilleur_2->setEnabled(true);
    //QObject::connect(ContreTorpilleur_2, SIGNAL(clicked()), this, SLOT(contretorpilleur2()));

    QPushButton *Torpilleur=new QPushButton("Torpilleur",centralWidget());
    Torpilleur->setGeometry(0,300,100,50);//positionH, positionV, tailleH, tailleV
    Torpilleur->setEnabled(true);
    //QObject::connect(Torpilleur, SIGNAL(clicked()), this, SLOT(torpilleur()));

    /*QPushButton *Send=new QPushButton("Send",centralWidget());
    Send->setGeometry(0,350,100,50);//positionH, positionV, tailleH, tailleV
    Send->setEnabled(true);
    QObject::connect(Send, SIGNAL(clicked()), this, SLOT(Sender()));

    QPushButton *Receive=new QPushButton("Receive",centralWidget());
    Receive->setGeometry(0,400,100,50);//positionH, positionV, tailleH, tailleV
    Receive->setEnabled(true);
    QObject::connect(Receive, SIGNAL(clicked()), this, SLOT(ecoute()));*/

    centralWidget()->show();
}
