// Calcul d'équation de droite.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//------------------------------------------------------
//Nom: Ghouaiel             Prénom:Elyes
//Date de creation : 21/09/2021
//Date de dernière modif: 21/09/2021
//------------------------------------------------------
//Calcul_d'équation_de_droite
//Le programme demande 3 nombres et calcule la moyenne de ceux-ci..
//------------------------------------------------------

#include <iostream>

//Déclaration des variables
float a,b,c,x;

using namespace std;

int main()
{
    cout << "Entrer 3 nombres";
    cin >> a >> b >> c ;
    x = (a+b+c)/3;
    cout << "La moyenne vaut"<< x;
    return 0;
}
