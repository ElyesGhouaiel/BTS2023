#include <iostream>
using namespace std;

int nombrealeatoire(int min,int max){
    srand(time(NULL));
    return rand()%(max-min)+min;

}

int main()
{
    int min,max;
    cout << "Donner le nombre minimum"<<endl;
    cin >> min;
    cout << "Donner le nombre maximum"<<endl;
    cin >> max;
    cout << "Votre nombre est " << nombrealeatoire(min,max) <<
            ", donc il est bien entre " << min << "et" << max << ".";
}
