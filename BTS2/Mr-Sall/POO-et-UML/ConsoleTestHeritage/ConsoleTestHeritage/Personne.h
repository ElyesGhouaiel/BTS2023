#ifndef _PERSONNE_H
#define _PERSONNE_H


#include <string>
using namespace std;

class Personne {
  protected:
    string nom;

    string prenom;

    int age;


  public:
    Personne(string unNom, string unPrenom, int unAge);

    void Afficher();

    string getNom();

    string getPrenom();

    int getAge();

};
#endif
