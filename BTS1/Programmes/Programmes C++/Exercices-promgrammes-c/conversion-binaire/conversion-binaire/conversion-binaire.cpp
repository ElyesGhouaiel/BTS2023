// conversion binaire.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//chenal killian 
//04/10/2021
//
//le programme doit convertir n'importe quel base en binaire, hexadecimmal etc.
//

#include <iostream>
using namespace std;
//Déclaration des variables
float base_dix,b;

int main() //début
{
    cout << "Entrer le nombre de bas dix que vous voulez convertir en base deux";
    cin >> base_dix;
	do
	{
		b = (base_dix / 2);
	} while (base_dix==0);
}

