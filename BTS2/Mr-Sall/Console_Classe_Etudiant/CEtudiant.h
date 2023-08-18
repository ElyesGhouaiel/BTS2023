#pragma once
#ifndef Etudiant_H
#define Etudiant_H
#include <iostream>
using namespace std;

// Definition de la classe CEtudiant
class Cetudiant {
public:
	//M�thodes membres de la classe
	Cetudiant(string leNom, string lePrenom, int unAge, int unNumEtud);
	void Afficher();
	int returnNumEtudiant();
	string returnNom();
	string returnPrenom();
	int returnAge();
private:
	//Definition des donn�es membres de la classe 
	string nom;
	string prenom;
	int age;
	int  numEtudiant;
};


#endif // !Etudiant_H


