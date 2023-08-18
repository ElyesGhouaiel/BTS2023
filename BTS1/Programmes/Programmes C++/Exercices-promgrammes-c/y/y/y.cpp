// y.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
using namespace std;
float nombre;

int main()
{
    do
    {
        cout << "saisir un nombre entre 10 et 20";
        cin >> nombre;
        if (nombre <= 10)
        {
            cout << "Plus grand";
        }
        if (nombre >= 20)
        {
            cout << "Plus petit";
        }while (nombre >= 10 && nombre <= 20);
    }



