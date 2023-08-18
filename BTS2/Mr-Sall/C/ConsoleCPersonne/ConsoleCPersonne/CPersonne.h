#pragma once
#ifndef CPERSONNE_H
#define CPERSONNE_H
#include <iostream>
using namespace std;

class CPersonne {
private:
	string nom;
	string prenom;
	int age;
public:
	CPersonne(string nom, string prenom, int age);
	void Afficher();
};

#endif // !CPERSONNE_H
