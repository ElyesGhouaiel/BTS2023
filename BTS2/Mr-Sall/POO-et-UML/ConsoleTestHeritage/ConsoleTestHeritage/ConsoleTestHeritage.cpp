// ConsoleTestHeritage.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <vector>
#include "Etudiant.h"
#include "Personne.h"
using namespace std;
int main()
{
    //créer une personne
    Personne jacques("Martin", "Jacques", 40);
    //créer un etudiant
    Etudiant kiki("Kylliannee", "Jacques-Francois", 22, "15664JUZHI", "2TSSNIR");
    
    //aficher les données de la personne
    jacques.Afficher();
    //afficher les données de l'etudiant
    kiki.Afficher();
    //afficher l'age de la personne
    cout << "jacques  a " << jacques.getAge() << " ans\n";
    //déclarer un pointeur sur un etudiant 
    Etudiant  *elyes;
  
    //crer dynamiquement un nouvel etudiant
     elyes= new  Etudiant("gaudino","balthazar",10, "15664JU", "2TSSNIR");
    //aficher la classe de cet etudiant
   cout<<"classe de l'etudiant : "<<  elyes->getNomClasse();
    //creer un tableau contenatn les etudiant de la classe 2 tssnir
   Etudiant* tabclasse[21]; //création d'un tableau de 21 pointeurs sur etudiant
   tabclasse[0] = &kiki;
   tabclasse[1] = elyes;



   //afficher les deux premier element du tableau
   for (int i = 0; i < 2; i++) {
       tabclasse[i]->Afficher();
   }


     
}

