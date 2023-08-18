#pragma once
#ifndef CImprimante_H
#define CImprimante_H
#include <iostream>

using namespace std;

class Cimprimante {
private:
	string nomImprimante;
	float vitesse;
	string couleur;
public:
	Cimprimante();
	Cimprimante(string LeNomImprimante, float Lavitesse, string Lacouleur);
	string getnomImprimante();
	string getcouleur();
	float getVitesse();
	void Afficher();
};

#endif // !CImprimante_H
