// ConsoleRevsisionsPointeurs.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "echanger.h"
using namespace std;

int main()
{
    /*int valint1 = 10;
    int valint2 = 20;

    cout << "avant appel a la procedure echanger(...)";
    cout << "\nvalint1 =" << valint1 << "valint2 = " << valint2;
    echanger3(&valint1, &valint2);
    cout << "\naprès appel a la procedure echanger(...)";
    cout << "\nvalint1 =" << valint1 << "valint2 = " << valint2;*/

    int* ptrInt; // déclaration d'un pointeur sur un entier 
    ptrInt = new int[10]; // allocation dynamique d’un tableau de 50 entiers pointé par ptrInt
    // affecter 10 au 3e élément du tableau pointé par ptrint
    ptrInt[2] = 10;
    // afficher le 3eme éléement du tableau 
    cout << "\nle 3eme element du tableau est : " << ptrInt[2];
    // detruire explicitement la place reservée pour le tableau
    delete(ptrInt);
}
