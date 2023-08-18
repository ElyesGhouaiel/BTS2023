// ConsoleTestString.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <iostream>
#include <string>
using namespace std;
int main()
{
    //manipuler le type "string" de la STL(Standard Lib)
    int nba = 0;
    string text = "abc defga"; //cration d'une chaine de caracteres 
    // afficher la chaine , sa longueur et le nombre de 'a' dans cette chaine
    cout <<"lachaine est " <<  text;
    cout << "\nsa longeur est " << text.length() <<"caractères ";
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] == 'a')
        {
            nba++;
        }
    }
    cout << "\nNombre de 'a' : " << nba;
}
