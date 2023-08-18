// triangle rectangle.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//chenal    killian
//29/09/2021
//
// triangle rectangle.
//
//le programme doit demander trois longeurs des trois côtés d'un triangle sans ordre précis et il doit déterliner si le triangle est rectangle.
//

#include <iostream>
using namespace std;
//Déclaration des variables
float ab, ac, bc,flag;

int main() //début

{
    cout << "Entrer trois longueurs quelqonques";
    cin >> (ab) >> (bc) >> (ac);
    
    if ((ab * ab) == (bc * bc) + (ac * ac))
    {
        cout << "le triangle est rectangle";
        flag = 1;
    }
        if ((bc * bc) == (ab * ab) + (ac * ac))
        {
            cout << "le triangle est rectangle";
            flag = 1;

        }
        if ((ac * ac) == (ab * ab) + (bc * bc))
        {
            cout << "le triangle est rectangle";
            flag = 1;
        }
        if (flag == 0)
        {
            cout << "le triangle n'est pas rectangle";
        }
      
}


