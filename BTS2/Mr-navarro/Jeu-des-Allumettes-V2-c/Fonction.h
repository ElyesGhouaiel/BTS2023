#ifndef FONCTION_H
#define FONCTION_H
#include <iostream>
using namespace std;

class IHMJoueur{
public:
    string saisirNom(int numerojoueur);
    void afficherJeuAllumettes(int N);
    int JouerUnCoup(int NbrAllumettesRestantes,string nom);
    void afficherVainqueur(string joueurVainqueur);
};

class CUjeuAllumettes{
private:
    string nom[2];
    int nbreAllumettes;
    int joueurEnCours;
    IHMJoueur ihm;
    void tirageAleatoire(int mini,int maxi);
    void ChangerJoueur();
public:
    CUjeuAllumettes();
    void jouerUnePartie();
};


#endif // FONCTION_H
