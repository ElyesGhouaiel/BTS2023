
#include "CDate.h"
#include <iostream>

using namespace std;
//constructeur par defaut : donne aux donn�e valeurs par defaut 11/01/2000
CDate::CDate() {
	// Initialisation des donn�es membre avec des valeurs par d�faut
	jour = 1;
	mois = 1;
	annee = 2000;	
}

CDate::CDate(int leJour, int lemois, int lannee) {
	jour = leJour;
	mois = lemois;
	annee = lannee;
}

//affiche la date selon le format: jj/m/an

void CDate::afficher() {

	cout << jour << "/" << mois << "/" << annee << endl;
}

//retourne lattribut Jour

int CDate::ReturnJour() {
	return jour;
}

//retourne l'attribut mois

int CDate::RetourMois() {
	return mois;
}

//retourne l'attribut annee

int CDate::RetourAnnee() {
	return annee;
}

void CDate::setJour(int unJour) {
	jour = unJour;
}

void CDate::setMois(int Mois) {
	mois = Mois;
}

void CDate::setAnnee(int Annee) {
	annee = Annee;
}

