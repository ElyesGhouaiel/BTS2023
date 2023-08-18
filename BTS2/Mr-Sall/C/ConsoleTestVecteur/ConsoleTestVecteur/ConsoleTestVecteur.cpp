// ConsoleTestVecteur.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <vector>
#include "C:\Users\Etudiant\source\repos\ConsoleCPersonne\ConsoleCPersonne\CPersonne.h"
using namespace std;

int main()
{
    // un vecteur est un tableau générique (peut contenir tous les types ) dynamique
    vector<int> v; // vecteur d'entier
    vector<CPersonne> vectPersonne;
    // on ajoute 10 element aux vecteurs
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i); //ajout d’un element au vecteur à la fin
    }
    //on affiche 
    for (int i = 0; i < 10; i++)
    {
        cout << v[i] << ",";
    }
    // crer un vecteur de cPersonne
    vectPersonne.push_back(CPersonne("\nMARTIN","Jacques",25));
    vectPersonne.push_back(CPersonne("\nDUPONT", "Robert", 30));
    //afficher le nombre d'élément du vecteur 
    cout << "nombre de persone : " << vectPersonne.size();
    // afficher le contenu vecteur
    for (int i = 0; i < vectPersonne.size(); i++) {
        vectPersonne[i].Afficher();
    }
    //effcer le vecteur
    cout << "\n afficher le vecteur après l'avoir rendu vide : ";
    vectPersonne.clear();
    // afficher le contenu vecteur
    for (int i = 0; i < vectPersonne.size(); i++) {
        vectPersonne[i].Afficher();
    }
     return (0);
}

