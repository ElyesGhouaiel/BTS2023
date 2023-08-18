// Console_Classe_Etudiant.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "CEtudiant.h"
#include "COrdinateur.h"

int main()
{
    // creer un objet CEtudiant avec vos données
    Cetudiant Elyes("Ghouaiel", "Elyes", 19, 9); 
    // Afficher les donées de l'objet
    Elyes.Afficher();

    cout << "Le Nom de l'objet est " << Elyes.returnNom();
    cout << "\nLe Prenom de l'objet est " << Elyes.returnPrenom();
    cout << "\nLAge de l'objet est " << Elyes.returnAge();
    cout << "\nLe Numero etudiant de l'objet est " << Elyes.returnNumEtudiant();

    //Creation d'un objet avec les paramètres de mon PC
    cOrdinateur Monordi("Lenovo","Thinkcentre",22,2.4,16);
    Monordi.Afficher();

    //Attribuer l'ordinateur à l'étudiant crée auparavant
    Monordi.AttribuerPropietaire(&Elyes);
    //On afficher les données du propriétaire de l'ordinateur
    cout << "\nLe proprietaire est : ";
    Monordi.AfficherProprietaire();

    Cimprimante MonImprimante("Dell", 19.5, "Jaune");
    Monordi.AttribuerImprimante(&MonImprimante);
    Monordi.AfficherImprimante();
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
