// Trinôme du second degré.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//chenal    killian
//29/09/2021
//
// trinôme du seond dregré.
//
//le programme doit demander les coefficients a, b et c d'un trinôme et il calcul la racine de ce trinôme si elle éxiste.
//
#include <iostream>
using namespace std;
//Déclaration des variables
float a, b, c, d, x1, x2, x0;

int main() //début
{
    cout << "Inserer un trinome a,b et c";
    cin >> a >> b >> c;
    d = ((b * b) -4 * a * c);
    if (d > 0)
    {
        x1 = ((-b + sqrt(d)) / (2 * a));
        x2 = ((-b - sqrt(d)) / (2 * a));
        cout << "les racines de ce trinomes sont"<< endl;
        cout << "x1= " << x1<< endl;
        cout << "x2= " << x2<<endl;
    }
    else
    {
        if (d==0)
        {
            x0 = ((-b) / 2 * a);
            cout << "la racine de ce trinome est:" << x0;
        }
        else
        {
            cout << "aucune racine n'est possible";
        }
    }




 }