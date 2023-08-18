#include <iostream>
#include <string.h>
using namespace std;


int main()
{
    string a;
    cout << "Taper un mot"<<endl;
    cin >>a;
    getline(cin,a);
    cout << "Voici le nombre de lettres dans votre mot" << a.length();
}

