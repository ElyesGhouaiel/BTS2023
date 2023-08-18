//------------------------------------------------------
//Nom: Ghouaiel             Prénom:Elyes
//Date de creation : 21/09/2021
//Date de dernière modif: 21/09/2021
//------------------------------------------------------
//trinome du second degré
//Le programme demande les coefficients a,b et c d'un trinome et qui calcule les racines de ce trinome si elles existent.
//------------------------------------------------------

#include <iostream>
#include <math.h>

using namespace std;

float a,b,c,D,x1,x2,x0;

int main()    //Début
{
    cout << "Insérer un trinome a,b,c";
    cin >> a >> b >> c;
    D = (b*b-4*a*c);
    if(D>0)
    {
        x1 = (((-b)+sqrt(D)))/(2*a);
        x2 = (((-b)-sqrt(D)))/(2*a);
    cout << (" les racines de ce trinome sont = ") << x1 << x2;
    }
    else {
        if (D==0)
        {
            x0 = ((-b)/2*a);
        cout << "La racine de ce trinome est" << x0 << endl;
        }
        else{
            cout << "Aucune racine est possible" ;
    }
        }
}
//FIN
