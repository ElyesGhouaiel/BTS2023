// multiplication.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//chenal killian
//03/10/2021
//
//multiplication
//
// le programme doit demander deux nombres à l'utilisateur et calculer le produit de ces deux nombreq sans utiliser la multiplication.
//

#include <iostream>
using namespace std;
//Déclaration des variables
int x, y, z, somme;


int main() //début


{
     cout << "Entrer deux nombres entiers";
     cin >> x >> y;
     somme = 0;
     for (int z = 1; z < y; z++)
     {
         somme = somme + x;
     }
     cout << "Le resultat est" << somme;
     
}