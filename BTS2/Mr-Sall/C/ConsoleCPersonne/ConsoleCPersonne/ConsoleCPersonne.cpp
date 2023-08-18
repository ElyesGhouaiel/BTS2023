// ConsoleCPersonne.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "CPersonne.h"

using namespace std;
int main()
{
    ////créer un objet ded type cPersonne statiquement
    //CPersonne Elyes("BEZIN", "Gaspard", 52);
    //// afficher les informations de l'objet
    //Elyes.Afficher();

    ////déclarer un pointeur sur des objets de type cPersonne
    //CPersonne* ptrPersonne;
    //// création dynamique d'un objet cPersonne pointé par ptrPersonne 
    //ptrPersonne = new CPersonne("Gaudino", "Balthazar", 100);
    //ptrPersonne->Afficher(); // appel de la methode afficher de l'objet
    //                         // pointé par ptrPersonne 

    int nbrdetudiants,Unage;
    int i=1;
    CPersonne* tabEtudiant[10];
    string unNom, unPrenom;
    cout << "Combien d etudiants a saisir : ";
    cin >> nbrdetudiants;
    for (i = 0; i < nbrdetudiants; i++) 
    { 
        cout << "\nEntrer le nom de l etudiant numero " << i << " :";
        cin >> unNom;
        cout << "\nEntrer le prenom de l etudiant numero " << i << " :";
        cin >> unPrenom;
        cout << "\nEntrer l age de l etudiant numero " << i << " :";
        cin >> Unage;
        tabEtudiant[i] = new CPersonne(unNom,unPrenom,Unage);
    }
    cout << "**********************Recapitulatif des donées**********************" << endl;
    for (i = 0; i < nbrdetudiants; i++)
    {
    cout << tabEtudiant[i] << endl;
    }
    return 0;
    
}


