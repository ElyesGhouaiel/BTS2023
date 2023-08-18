#include <iostream>
using namespace std;

int main()
{
    int a,flag=0;
    while(flag==0){
        cout << "Donnez un chiffre pair supérieur à 10 : ";
        cin >>a;
     try{
        if(a<10) throw 1;
        if(a==10) throw 2;
        if(a%2==1) throw 3;
        cout << "Félicitations,Vous avez bien donné un chiffre pair un supérieur à 10"<<endl;
        flag=1;
        }
      catch(int b){
            cout <<"Error !!!!";
            switch (b) {
                case 1: cout << "Inferieur à 10 "<<endl;break;
                case 2:  cout << "Egale à 10 "<<endl;break;
                case 3:  cout << "Impair "<<endl;break;
            }
            flag =0;
        }
    }

}
