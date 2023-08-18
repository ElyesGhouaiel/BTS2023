#include <iostream>

using namespace std;

int fct(int min,int max){
    srand(time(NULL));
    return rand()%(max-min)+min;
}

int main()
{
    int min,max;
    cout << "entrer votre max" << endl;
    cin>> max;
    cout << "entrer votre min" << endl;
    cin >> min;
    cout << fct(min,max);
}
