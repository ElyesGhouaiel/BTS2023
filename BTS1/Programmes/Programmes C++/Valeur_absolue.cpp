// Calcul d'équation de droite.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//------------------------------------------------------
//Nom: Ghouaiel             Prénom:Elyes
//Date de creation : 21/09/2021
//Date de dernière modif: 21/09/2021
//------------------------------------------------------
//Valeur_absolue
//Le programme demande un nombre et qui renvoie à  sa valeur absolue
//------------------------------------------------------

#include <iostream>

using namespace std;

float x,y;

int main() //Début
{
    cout << "Saisir la valeur " << endl;
    cin >> x;
    if (x >= 0)
        y = x ;
    else{
        x = x*(-1);
    }
    cout << "La valeur absolue est" << x ;
}
//FIN
