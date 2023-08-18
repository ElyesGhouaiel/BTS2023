#include <iostream>
#include "Etudiant.h"
using namespace std;

Etudiant::Etudiant(string unNom, string unPrenom, int unAge, string unINE, 
	string uneClasse):Personne(unNom,unPrenom,unAge)
{
	//initialisation des données membres spécifiques à la classe Etudiant
	INE = unINE;
	NomClasse = uneClasse;

}

void Etudiant::Afficher() {
	//utilise la methode afficher de la classe mère 
	Personne::Afficher();
	cout << " numero etudiant : " << INE << " classe: " << NomClasse << endl;
}

string Etudiant::getINE() {
	return INE;
}

string Etudiant::getNomClasse() {
	return NomClasse;
}

