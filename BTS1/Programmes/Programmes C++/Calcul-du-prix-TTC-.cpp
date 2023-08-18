// Calcul d'équation de droite.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//------------------------------------------------------
//Nom: Ghouaiel             Prénom:Elyes
//Date de creation : 21/09/2021
//Date de dernière modif: 21/09/2021
//------------------------------------------------------
//Calcul_du prix TTC
//Le programme calcule le prix TTC sachant qu ele programme demande le prix hors taxe , le nombre et le taux de TVA .
//------------------------------------------------------

#include <iostream>

//Déclaration des variables
float HT,Le_nombre,TVA,TTC;

using namespace std;

int main()
{
    cout << "Saisir le prix hors taxe " ;
    cin >> HT ;
    cout << "Saisir le nombre " ;
    cin >> Le_nombre;
    cout << "Saisir La TVA";
    cin >> TVA;
    TTC = (Le_nombre*HT)*(1+(TVA/100));
    cout << "voici le TTC" << TTC ;
    return 0;
}
