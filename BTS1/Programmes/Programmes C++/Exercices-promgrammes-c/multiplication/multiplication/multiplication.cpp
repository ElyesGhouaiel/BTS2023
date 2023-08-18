// multiplication.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
using namespace std;
//Déclaratio des variables
int x, y, z, somme;


int main() //début
{
    cout << "Entrer deux nombres entiers";
    cin >> x;
    cin >> y;
    somme = 0;
    for (int z = 0; z < y; z++)
    {
        somme = (somme + x);
    }
    cout << "Le resultat est:" << somme;
}

