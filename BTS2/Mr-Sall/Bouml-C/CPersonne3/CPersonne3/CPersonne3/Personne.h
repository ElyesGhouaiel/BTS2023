#ifndef _PERSONNE_H
#define _PERSONNE_H


#include <iostream>
using namespace std;

class Personne {
  protected:
    string nom;

    string prenom;

    int age;


  public: 
    Personne(string unNom, string unPrenom, int unAge);

     virtual void sePresenter();

};
#endif
