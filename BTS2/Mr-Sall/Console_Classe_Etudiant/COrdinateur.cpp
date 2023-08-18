#include "COrdinateur.h"
#include <iostream>

using namespace std;

cOrdinateur::cOrdinateur(){
	Marque=" ";
	Modele=" ";
	TailleEcran=0.0;
	VitesseProcesseur=0.0;
	TailleRam=0;
	ptrProprietaire = NULL;

}
cOrdinateur::cOrdinateur(string UneMarque, string LeModele, float LaTailleEcran, float LavitesseduProcesseur, int LaTailleRam) {
	Marque=UneMarque;
	Modele= LeModele;
	TailleEcran= LaTailleEcran;
	VitesseProcesseur= LavitesseduProcesseur;
	TailleRam=LaTailleRam;
	ptrProprietaire = NULL;
}
string cOrdinateur::getMarque() {
	return Marque;
}
string cOrdinateur::getModele() {
	return Modele;
}
float cOrdinateur::getTailleEcran() {
	return TailleEcran;
}
float cOrdinateur::getVitesseProcesseur() {
	return VitesseProcesseur;
}
int cOrdinateur::getTailleRam() {
	return TailleRam;
}
void cOrdinateur::Afficher() {
	cout << "marque : " << Marque;
	cout << "\nmodele : " << Modele;
	cout << "\nTaille de l ecran : " << TailleEcran << " pouces";
	cout << "\nVitesse Processeur : " << VitesseProcesseur<<" Hz";
	cout << "\nQuantite de la Ram : " << TailleRam << " Go";
}
void cOrdinateur::AttribuerPropietaire(Cetudiant* ptrEtudiant) {
	ptrProprietaire = ptrEtudiant;
}
void cOrdinateur::AfficherProprietaire() {
	ptrProprietaire->Afficher();//On affiche Nom,prenom,ect.. de L'étudiant
}
void cOrdinateur::AttribuerImprimante(Cimprimante* ptrImprimantefinale) {
	ptrImprimante = ptrImprimantefinale;
}
void cOrdinateur::AfficherImprimante() {
	ptrImprimante->Afficher();
}