#ifndef _PROF_H
#define _PROF_H


#include "Personne.h"
#include <string>
using namespace std;

class Prof : public Personne {
  protected:
    string matiere;


  public:
    Prof(string unNom, string unPrenom, int unAge, string uneMatiere);

     void sePresenter();

};
#endif
