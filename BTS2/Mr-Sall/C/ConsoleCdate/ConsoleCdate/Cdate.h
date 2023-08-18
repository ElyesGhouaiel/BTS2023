#pragma once
// definition de la classe date
using namespace std;

class DATE {
public:

	DATE(); // constructeur par d�faut
	DATE(int leJour, int leMois, int uneAnnee); //constructeur avec param�tres
	
	void Afficher();
	
	int RetournJour();
	int RetournMois();
	int RetournAnnee();

	void ModifieJour(int unJour);
	void ModifieMois(int unMois);
	void ModifieAnnee(int uneAnnee);

private:
	int jour;
	int mois;
	int annee;

};