// Calcul d'équation de droite.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//------------------------------------------------------
//Nom: Ghouaiel             Prénom:Elyes
//Date de creation : 21/09/2021
//Date de dernière modif: 21/09/2021
//------------------------------------------------------
//Calcul_d'équation_de_droite
//Le programme demande une valer de x et affiche la valeur de y sachant que y=5.x+12,il calcule une équation de droite .
//------------------------------------------------------

#include <iostream>

//Déclaration des variables
float x,y;

using namespace std;

int main()
{
cout <<"Saisir la valeur de x";
cin >> x ;
y = 5*x+12;
cout << "La valeur de y est="<<y;
return 0;
}  // Fin
