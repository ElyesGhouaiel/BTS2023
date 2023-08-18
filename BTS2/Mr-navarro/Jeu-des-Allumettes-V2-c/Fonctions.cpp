#include <iostream>
#include "Fonction.h"
using namespace std;

string IHMJoueur::saisirNom(int numerojoueur){
    string nom;
    cout <<endl;
    //if (numerojoueur==0){
        cout << "Veuillez saisir le nom du joueur"<<numerojoueur+1 <<" : ";
        cin >> nom;
    /*}else if(numerojoueur==1){
        cout << "Veuillez saisir le nom du joueur 2 : ";
        cin >> nom[1];
    }*/
    return nom;
}

void IHMJoueur::afficherJeuAllumettes(int N){

    string affich = "";
    for(int i=0;i<N;i++){
         affich = affich + "| ";
    }
    cout << N << affich;
}

int IHMJoueur::JouerUnCoup(int NbrAllumettesRestantes,string nom){
    int NbreAllumettesSupprimes;
    cout << endl << nom <<" Combien d'allumettes voulez-vous supprimer ?";
    cin >> NbreAllumettesSupprimes;
    while(NbreAllumettesSupprimes<1 || NbreAllumettesSupprimes>3){
        cout << nom<<": Veuillez saisir entre 1 et 3 ";
        cin >>NbreAllumettesSupprimes;
    }
    while(NbrAllumettesRestantes < NbreAllumettesSupprimes){
        cout << nom <<": Vous enlevez trop d'Allumettes";
        cin >> NbreAllumettesSupprimes;
    }
    NbrAllumettesRestantes = NbrAllumettesRestantes - NbreAllumettesSupprimes;
    return NbrAllumettesRestantes;
}

void IHMJoueur::afficherVainqueur(string joueurVainqueur){
    cout << "==============Vainqueur=============="<< endl;
    cout << "le joueur " << joueurVainqueur << " a gagné"<< endl<<endl;
}

void CUjeuAllumettes::tirageAleatoire(int mini,int maxi){
    srand(time(NULL));
    nbreAllumettes = rand()%(maxi-mini)+mini;
}

void CUjeuAllumettes::ChangerJoueur(){
    if(joueurEnCours==0){
        joueurEnCours++;
    }else if(joueurEnCours==1){
        joueurEnCours--;
    }
}

CUjeuAllumettes::CUjeuAllumettes(){
    nbreAllumettes=0;
    joueurEnCours=0;
}

void CUjeuAllumettes::jouerUnePartie(){
    tirageAleatoire(5,35);
    nom[0]=ihm.saisirNom(0);
    nom[1]=ihm.saisirNom(1);
    while(nbreAllumettes!=0){
        ihm.afficherJeuAllumettes(nbreAllumettes);
        nbreAllumettes = ihm.JouerUnCoup(nbreAllumettes,nom[joueurEnCours]);
        ChangerJoueur();
    }
    if(nbreAllumettes==0 && joueurEnCours==0){
        ihm.afficherVainqueur(nom[0]);
    }else if(nbreAllumettes==0 && joueurEnCours==1){
        ihm.afficherVainqueur(nom[1]);
    }
}
