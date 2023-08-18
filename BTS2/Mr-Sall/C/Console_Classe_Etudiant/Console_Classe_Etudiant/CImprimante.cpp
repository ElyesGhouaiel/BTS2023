#include <iostream>
#include "CImprimante.h"

using namespace std;

Cimprimante::Cimprimante() {
	nomImprimante=" ";
	vitesse=0.0;
	couleur=" ";
}

Cimprimante::Cimprimante(string LeNomImprimante, float Lavitesse, string Lacouleur) {
	nomImprimante = LeNomImprimante;
	vitesse = Lavitesse;
	couleur = Lacouleur;
}

string Cimprimante::getnomImprimante() {
	return nomImprimante;
}
string Cimprimante::getcouleur() {
	return couleur;
}
float Cimprimante::getVitesse() {
	return vitesse;
}
void Cimprimante::Afficher() {
	cout << "\nLe nom de l'Imprimante : " << nomImprimante;
	cout << "\nLa vitesse de l'Imprimante : " << vitesse;
	cout << "\nLa couleur de l'Imprimante : " << couleur;
}

