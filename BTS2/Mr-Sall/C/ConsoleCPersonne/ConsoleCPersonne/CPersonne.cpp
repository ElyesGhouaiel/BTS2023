#include "CPersonne.h"
#include <iostream>
using namespace std;

CPersonne::CPersonne(string nom, string prenom, int age) {
	this->nom = nom;// utilisation du pointeur this : l'objet lui même
	this->prenom = prenom;
	this->age = age;
}

void CPersonne::Afficher() {
	cout << nom << " " << prenom << " " << age << " ans" << endl;
}

