#ifndef _ETUDIANT_H
#define _ETUDIANT_H


#include "Personne.h"
#include <iostream>
using namespace std;

class Etudiant : public Personne {
  protected:
    string classe;


  public:
    Etudiant(string unNom, string unPrenom, int unAge, string uneClasse);

      void sePresenter();

};
#endif
