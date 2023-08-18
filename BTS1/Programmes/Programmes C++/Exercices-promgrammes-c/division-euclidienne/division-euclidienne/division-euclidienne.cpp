// division euclidienne.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//chenal killian
//03/10/2021
//
//le programme doit demander deux nombres A et B à  l'utilisateur et calculer le quotient A/B 'division euclidienne). 
//

#include <iostream>
using namespace std;
//Déclaration des variables
int a, b, quotient, z,x,exit;

int main() //début

{
    do
    {
        cout << "Inserer deux nombres entiers";
        cin >> a >> b;
        quotient = (a / b);
        z = quotient * b;
        x = a - z;
        cout<<"le resultat est:" << x<<"\n" << a<<"  " << "est divise par" << "  " << quotient << "\a";
    } while (exit=0);
    
}


