// Puissance.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//chenal killian
//03/10/2021
//
//le programme doit demander deux nombres à  l'utilisateur A et n et les calculer A exposant n(puissance), le nombre n doit être un entier.
//

#include <iostream>
using namespace std;
//Déclaration des variables
int a, n, z, produit;

int main() //début
{
    cout << "Entrer un nombre et son exposant";
    cin >> a >> n;
    produit = 1;
    for (int z = 1; z < n; z++)
    {
        produit = pow(a,n);
    }
    cout << "Le resultat est" << produit;
}

