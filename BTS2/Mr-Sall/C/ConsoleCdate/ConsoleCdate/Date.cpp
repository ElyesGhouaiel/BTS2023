#include "Cdate.h"
#include <iostream>

//impl�mentation des m�thodes de la classe date



//constructeur par d�fautS
DATE::DATE() {
	//initalise les donn�es membres avec des  valeurs par d�faut

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

