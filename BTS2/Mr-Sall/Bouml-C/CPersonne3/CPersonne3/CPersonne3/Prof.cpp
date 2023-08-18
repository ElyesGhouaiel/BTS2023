
#include "Prof.h"
#include <iostream>
using namespace std;
Prof::Prof(string unNom, string unPrenom, int unAge, string uneMatiere)
	:Personne(unNom,unPrenom,unAge) {

	matiere = uneMatiere;
}

void Prof::sePresenter() {
	Personne::sePresenter();
	cout << "\nje suis professeur de la matiere " << matiere<<"\n";
}

