#include "Fonctions.h"
#include <iostream>
using namespace std;

string IHMJoueur::getNom(){
    return nom;
}
void IHMJoueur::saisirNom(){
    cout << "======== Jeu des Allumettes ========"<<endl<<endl;
    cout<< "Entrer le nom du joueur : ";
    cin >> nom;
}

int IHMJoueur::jouer(int Allumettes){
    int NombreAllumettesSupprimees;
        cout << ", Combien d'allumettes voulez vous supprimer ? ";
        cin >> NombreAllumettesSupprimees;
        while (NombreAllumettesSupprimees < 1 || NombreAllumettesSupprimees > 3) {
             cout << "Veuillez saisir un chiffre entre 1 et 3 : ";
             cin >> NombreAllumettesSupprimees ;
        }
        while ( Allumettes <= NombreAllumettesSupprimees) {
             cout << "ERROR, Vous voulez supprimer trop d'allumettes : ";
             cin >> NombreAllumettesSupprimees;
        }
        Allumettes = Allumettes - NombreAllumettesSupprimees;
        return  Allumettes;
    }
void CUJeuAllumettes::tirageAleatoire(int mini,int maxi){
    srand(time(NULL));
    nbreAllumettes = rand()%(maxi-mini)+mini;
}

CUJeuAllumettes::CUJeuAllumettes(){}

int CUJeuAllumettes::getJoueurEncours(){
    return joueurEnCours;
}

void CUJeuAllumettes::setNbreAllumettes(int N){
    nbreAllumettes=N;
}

int CUJeuAllumettes::getNbreAllumettes(){

}


void CUJeuAllumettes::afficherJeuAllumettes(){
    cout<<endl<<endl<<endl;
    for(int i=0;i<nbreAllumettes;i++){
        cout << "| ";
    }
}

void CUJeuAllumettes::jouerUnePartie(){
    tirageAleatoire(5,35);
    while (allumettes != 0) {
        NombreAllumettes(Allumettes);
        AQuiDeJouer = Tours(AQuiDeJouer, Joueur1, Joueur2);
        Allumettes = SupprimerAllumettes(Allumettes);
        }
    afficherJeuAllumettes();
    int allumettes = joueur1.jouer(nbreAllumettes);
    allumettes = joueur2.jouer(nbreAllumettes);
    setNbreAllumettes(allumettes);

}









