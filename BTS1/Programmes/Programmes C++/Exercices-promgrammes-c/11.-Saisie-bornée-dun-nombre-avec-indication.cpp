//  Saisie bornée d'un nombre avec indication.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
//chenal killian
//28/09/2021
//
//11. Saisie bornée d'un nombre ave inddication
//
//le programme doit demander un nombre à l'utilisateur compris entre 10 et 20 (inclu), jusqu'à que la réponse convienne. En cas de réponse supérieure à 20, il affichera un message "plus petit" et inversement si plus petit que 10.
//

#include <iostream>
using namespace std;
//Déclaration des variables
float nombre;
int main() //début



{
    do
    {
        cout << "saisir un nombre entre 10 et 20";
        cin >> (nombre);
        if (nombre <= 10)
        {
            cout << "Plus grand";
        }
        if (nombre >= 20)
        {
            cout << "Plus petit";
        }while (nombre >= 10 && nombre <= 20);
    }
}