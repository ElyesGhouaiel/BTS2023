#include <iostream>

using namespace std;

int main()
{
    int a,b;
    cout << "Entrer un nombre supérieur à 1 :";
    cin >> a;
    b=a%b;
    while (a>=1){
        if (b*b==a){
            cout<<"Votre Nombre est un carré parfait";
        }else{
            cout<<"Votre Nombre n'est pas un carré parfait";
        }
        return 0;
    }
}
