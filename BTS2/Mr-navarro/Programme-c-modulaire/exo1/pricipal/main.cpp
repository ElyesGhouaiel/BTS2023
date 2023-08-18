#include <iostream>
#include "prototype.h"

using namespace std;
int main()
{
    string nom1,nom2;
    int n,aquidejouer=1;
    nom1=nom_1();
    nom2=nom_2();
    cout <<endl<<endl<<endl<< " --- Debut du jeu --- ";
    n = nombrealeatoire(5,35);
    while (n!=0){
    nombresallumettes(n);
    aquidejouer = TourparTour(aquidejouer,nom1,nom2);
    n = enlever(n);
    }
    Vainqueur(n,nom1,nom2,aquidejouer);

}
