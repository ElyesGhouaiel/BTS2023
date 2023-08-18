// Calcul d'équation de droite.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//------------------------------------------------------
//Nom: Ghouaiel             Prénom:Elyes
//Date de creation : 21/09/2021
//Date de dernière modif: 21/09/2021
//------------------------------------------------------
//Calcul_d'équation_de_droite
//Le programme affiche le montant à payer sachant que les 10 premières photocopies valent 20 centimes l'une , 10 centimes //(l'une) les vingts suivantes et 5 centimes (l'une) au delà .
//------------------------------------------------------

#include <iostream>

//Déclaration des variables
int y,x;

using namespace std;

int main()
{
    cout <<"Mettre le nombre de photocopies";
    cin >> x ;
    if (x<10 && x>=0)
        y= x*0.20
        else {
                if (x>10 && x<=30)
                y= 10*0.2+(x-10)*0.10
                else{ y=10*0.2+(x-10)*0.10
}
}
    cout <<"le montant à payer est de=" << x ;


    }

    return 0;
}
