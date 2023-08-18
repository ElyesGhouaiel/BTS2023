// Saisie bornée d'un nombre.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
//chenal killian 
//28/09/2021
//
//saisie bornée d'un nombre
//
//le programme doit demander à l'utilisateur un nombre compris entre 1  et 10 (inclus) jusqu'à que la réponse convienne.
//

#include <iostream>
using namespace std;
//déclaration des variables 
float x;

int main() // début
{
	cout << "saisir un nombre compris entre 1 et 10 inclus";
	cin >> x;
	if (x >= 1 && x <= 10)
	{
		cout << "le nombre compris est bien entre 1 et 10 inclus";

	}
	else
	{
		do
		{
			cout << "le nombre n'est pas compris entre 1 et 10";
			cin >> x;
			 
		} while ((x >= 1 && x <= 10);

	}
	
}


