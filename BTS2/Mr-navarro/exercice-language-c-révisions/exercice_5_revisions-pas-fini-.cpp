#include <iostream>
using namespace std;

void debut(){
    cout<< "C'est au joueur 1 de jouer ";
    cout<< "C'est au joueur 2 de jouer ";
}

void bandeaudebut(){
    cout << "======== Jeu des Allumettes ========";
}

void lesjoueurs(){
    string J1,J2;
    cout<< "Entrer le nom du joueur No 1";
    cin >> J1;
    cout<< "Entrer le nom du joueur No 2";
    cin >> J2;
}

int nombrealeatoire(int min,int max){

    srand(time(NULL));
    cout << "|"* (min,max);
    return rand()%(max-min)+min;

}

int main()
{
    lesjoueurs();
    nombrealeatoire(5,35);

}
