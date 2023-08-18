#ifndef FONCTIONS_H
#define FONCTIONS_H
#include<iostream>
#include <string.h>

using namespace std;

class IHMJoueur{
private:
    string nom;
public:
string getNom();
void saisirNom();
int jouer(int);
};

class CUJeuAllumettes
{
private:

int nbreAllumettes;
int joueurEnCours;
IHMJoueur joueur1;
IHMJoueur joueur2;
int getNbreAllumettes();
void setNbreAllumettes(int N);
int getJoueurEncours();
void tirageAleatoire(int mini,int maxi);
void afficherJeuAllumettes();
void changerJoueur();

public:

CUJeuAllumettes();
void jouerUnePartie();

};

#endif // FONCTIONS_H
