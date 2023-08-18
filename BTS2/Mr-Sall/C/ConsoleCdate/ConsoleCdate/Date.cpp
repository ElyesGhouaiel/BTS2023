#include "Cdate.h"
#include <iostream>

//implémentation des méthodes de la classe date



//constructeur par défautS
DATE::DATE() {
	//initalise les données membres avec des  valeurs par défaut

	jour = 1;
	mois = 1;
	annee = 2000;
}

DATE::DATE(int leJour, int leMois, int uneAnnee) {
	jour = leJour;
	mois = leMois;
	annee = uneAnnee;
}

void DATE:: Afficher() {
	std::cout << jour << "/" << annee << std::endl;
}

