// Calcul d'une moyenne.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//chenal    killian 
//21/09/2021
//
//Calcul d'une moyenne
//
//le programme doit demander trois nombres et calcul la moyenne de ces trois nombres.
//


#include <iostream>
using namespace std;
//Déclaration des variables
float n1, n2, n3,moyenne;

int main() //début

{
	cout << "Entrer trois nombres!";
	cin >> n1 >> n2 >> n3;
	moyenne = (n1 + n2 + n3) / 3;
	cout << "La moyenne vau" << moyenne;

}

