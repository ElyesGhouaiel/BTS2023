// CPersonne3.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include "Personne.h"
#include "Etudiant.h"
#include "Prof.h"
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	
	
	//déclaration des variables
	string unNom,unPrenom,uneClasse,uneMatiere; 
	int unAge;
	
	//demander a l'utilisateur les infos sur un etudiant et l'ajouter au vecteur
	//demander a 'utilisateur les infos sur un prof et l'ajouter au vecteur
	//parcourir le vecteur et demander aux elements presents de se presenter
	
	//creer une personne
	Personne Elyes("chenal", "killian", 17);
	//creer un etudiant 
	Etudiant luca("gaudino", "cesar", 22, "1Tsnir");
	//creer un prof
	Prof carta("carta", "jean-claude", 56, "francais");
	//dire a la personne de se presenter 
	Elyes.sePresenter();
	//dire a l'etudiant de se presenter 
	luca.sePresenter();
	//dire au prod de se presenter 
	carta.sePresenter();

	//déclarer un vecteur de personne
	vector<Personne*> vecteurpersonne;

	//saisie de la personne
	cout << "\nnom de la personne : ";
	cin >> unNom;
	cout << "\nprenom de la personne : ";
	cin >> unPrenom;
	cout << "\nage de la personne : ";
	cin >> unAge;
	cout << " \n";

	//ajouter une personne avec lesdonnées saisies dans le vecteur
	vecteurpersonne.push_back(new Personne(unNom, unPrenom, unAge)); //saisie de la personne
	
	//saisie de etudiant
	cout << "\nnom de la etudiant : ";
	cin >> unNom;
	cout << "\nprenom de la etudiant : ";
	cin >> unPrenom;
	cout << "\nage de la etudiant : ";
	cin >> unAge;
	cout << "\nclasse de la etudiant : ";
	cin >> uneClasse;
	cout << " \n";

	//ajouter une personne avec lesdonnées saisies dans le vecteur
	vecteurpersonne.push_back(new Etudiant(unNom, unPrenom, unAge,uneClasse));

	//saisie d'un prof
	cout << "\nnom du prof : ";
	cin >> unNom;
	cout << "\nprenom du prof : ";
	cin >> unPrenom;
	cout << "\nage du prof : ";
	cin >> unAge;
	cout << "\nmatiere du prof : ";
	cin >> uneMatiere;
	cout << " \n";
	//ajouter une personne avec lesdonnées saisies dans le vecteur
	vecteurpersonne.push_back(new Prof(unNom, unPrenom, unAge, uneMatiere));

	//parcourir le vecteur et demander aux personnes de se presenter
	for (int i = 0; i < vecteurpersonne.size(); ++i)
	{
		vecteurpersonne[i]->sePresenter();
	}
}

