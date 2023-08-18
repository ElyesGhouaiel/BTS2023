//------------------------------------------------------
//Nom: Ghouaiel             Prénom:Elyes
//Date de creation : 21/09/2021
//Date de dernière modif: 21/09/2021
//------------------------------------------------------
//Comparaison
//Le programme demande 3 nombres et affiche le plus petit des 3
//------------------------------------------------------

#include <iostream>

using namespace std;

float NB1,NB2,NB3;

int main()
{
    cout << "Saisir 3 nombres" << endl;
    cin >> NB1 >> NB2 >> NB3 ;
    if( NB1 <NB2 && NB1< NB3)
        cout << NB1;
    else{
        if ( NB2 < NB3 && NB2 < NB1 )
            cout << NB2;
        else{
            if( NB3 < NB1 && NB3 < NB2)
                cout << NB3;
        }
    }
}
