#ifndef _ETUDIANT_H
#define _ETUDIANT_H


#include <string>
using namespace std;
#include "Personne.h"

class Etudiant : public Personne {
  protected:
    string INE;

    string NomClasse;


  public:
    Etudiant(string unNom, string unPrenom, int unAge, string unINE, string uneClasse);

    void Afficher();

    string getINE();
 string getNomClasse();

};
#endif
