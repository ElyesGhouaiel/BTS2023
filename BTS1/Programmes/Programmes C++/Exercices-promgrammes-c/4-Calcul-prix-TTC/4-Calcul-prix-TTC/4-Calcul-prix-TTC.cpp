// 4) Calcul prix TTC.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//chenal    killian
//21/09/2021
//
//Calul prix TTC.
//
//Le programme lit le prix HT d'un article, le nombre d'articles et le taux de TVA exprimé en %, et il dit fournir le prix total TTC qui correspond.
//

#include <iostream>
using namespace std;
//Déclaration des variables
float HT, nb, TVA, TTC;

int main() //début
{
	cout << "Entrer le prix hors taxe";
	cin >> HT;
	cout << "entrer le nombres d'articles";
	cin >> nb;
	cout << "entrer la TVA";
	cin >> TVA;
	TTC = (HT * nb) * (1 + TVA) / 100;
	cout << "le prix total est:" << TTC;

}


