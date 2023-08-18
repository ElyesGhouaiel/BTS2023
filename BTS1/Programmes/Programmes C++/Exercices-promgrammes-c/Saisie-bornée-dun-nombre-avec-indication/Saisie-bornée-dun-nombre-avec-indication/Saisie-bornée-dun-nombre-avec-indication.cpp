// Saisie bornée d'un nombre avec indication.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
//chenal killian
//29/09/2021
//
//saisie bornée d'un nombre avec incication.
//
//le programme doit demander un nombre compris entre 10 et 20 (inclus), en cas de réponse supérieure à 20 ou inférieure à 10 il repond plus petit ou plus grand.


#include <iostream>
using namespace std;
//Déclaration des variables
float nombre;

int main() //début

{
	do
	{
		cout << "saisir un nombre compris entre 10 et 20";
		cin >> nombre;
		if (nombre<10)

		{
			cout << "plus grand";

		}
		if (nombre>20)

		{
			cout << "plus petit";


		}
	} while (nombre>=10 && nombre <=20);
}

