#include "CEtudiant.h"

/***********implémentation de la classe CEtudiant***********/
//implémentation du constructeur
Cetudiant::Cetudiant(string leNom, string lePrenom, int unAge, int unNumEtud)
{
	nom			= leNom;
	prenom		= lePrenom;
	age			= unAge;
	numEtudiant	= unNumEtud;
}

// implémentation de la méthode void Afficher()
void Cetudiant::Afficher()
{
	cout << numEtudiant << " " << nom << " " << prenom << " " << age 
		<<" ans" << endl;
}

int Cetudiant::returnNumEtudiant()
{
	return numEtudiant;
}

string Cetudiant::returnNom() {
	return nom;
}

string Cetudiant::returnPrenom() {
	return prenom;
}

int Cetudiant::returnAge() {
	return age;
}