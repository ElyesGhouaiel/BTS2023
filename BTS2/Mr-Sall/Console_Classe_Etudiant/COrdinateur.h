#pragma once
#ifndef Ordinateur_H
#define Ordinateur_H
#include <iostream>
#include "CEtudiant.h"
#include "CImprimante.h"
using namespace std;
//definition de la classe COrdinateur

class cOrdinateur {
private:
	string Marque;
	string Modele;
	float TailleEcran;
	float VitesseProcesseur;
	int TailleRam;
	Cetudiant *ptrProprietaire;
	Cimprimante *ptrImprimante;
public:
	cOrdinateur();//Constructeur par défaut
	cOrdinateur(string UneMarque, string LeModele, float LaTailleEcran, float LavitesseduProcesseur, int LaTailleRam);//Constructeur initialisation
	// Les getters
	string getMarque();
	string getModele();
	float getTailleEcran();
	float getVitesseProcesseur();
	int getTailleRam();
	void Afficher();
	void AttribuerPropietaire(Cetudiant* ptrEtudiant);
	void AfficherProprietaire();
	void AttribuerImprimante(Cimprimante* ptrImprimantefinale);
	void AfficherImprimante();
};
#endif // !Ordinateur_H