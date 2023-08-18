
#include "Etudiant.h"
#include "Personne.h"
#include <iostream>
using namespace std;
Etudiant::Etudiant(string unNom, string unPrenom, int unAge, string uneClasse):Personne(unNom,unPrenom,unAge) {
	
	 classe=uneClasse ;
}

void Etudiant::sePresenter() {
	Personne::sePresenter();
	cout << "\nje suis etudiant en classe de " << classe<<"\n";
}

