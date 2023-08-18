#include <iostream>
#include "Personne.h"
using namespace std;

Personne::Personne(string unNom, string unPrenom, int unAge) {
	nom = unNom;
	prenom = unPrenom;
	age = unAge;
}

void Personne::Afficher() {
	cout << prenom << " " << nom << " " << age << " ans\n";
}

string Personne::getNom() {
	return nom;
}

string Personne::getPrenom() {
	return prenom;
}

int Personne::getAge() {
	return age;
}

