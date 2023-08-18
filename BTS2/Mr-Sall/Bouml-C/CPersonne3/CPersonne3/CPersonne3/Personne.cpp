
#include "Personne.h"
#include <iostream>
using namespace std;
Personne::Personne(string unNom, string unPrenom, int unAge) {
	nom = unNom;  prenom = unPrenom; age = unAge;  
}

void Personne::sePresenter() {
	cout << "\nBonjour je suis "<< " " << nom << "   " 
		<< prenom << " :  " << age<<" ans\n";








}

