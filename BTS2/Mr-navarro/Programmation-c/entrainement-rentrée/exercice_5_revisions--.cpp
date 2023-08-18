#include <iostream>
using namespace std;

string nom_1(){

    cout << "======== Jeu des Allumettes ========"<<endl<<endl;
    string  nom1 = "";
    cout<< "Entrer le nom du joueur No 1 : ";
    cin >> nom1;
    return (nom1);
}


string nom_2(){

    string  nom2 = "";
    cout<< "Entrer le nom du joueur No 2 : ";
    cin >> nom2;
    return (nom2);
}

int nombrealeatoire(int min,int max){
    srand(time(NULL));
    return rand()%(max-min)+min;
}

void nombresallumettes(int n){
    cout<<endl<<endl<<endl;
    for(int i=0;i<n;i++){
        cout << "| ";
    }
}

int TourparTour(int aquidejouer,string nom1,string nom2){
    if (aquidejouer==1){
        cout <<endl<<endl<< nom1 ;
        aquidejouer++;
    }else if (aquidejouer==2) {
        cout <<endl<<endl<< nom2 ;
        aquidejouer--;
    }
    return aquidejouer;
}

int enlever(int n){
   int chiffresup;
   cout << ", Combien d'allumettes voulez vous supprimer ? ";
   cin >> chiffresup;
   while(chiffresup<1 || chiffresup>3){
        cout << "Veuillez saisir un chiffre entre 1 et 3 : ";
        cin >> chiffresup ;
   }
   while(n<chiffresup){
       cout << "ERROR, Vous voulez supprimer trop d'allumettes : ";
       cin >> chiffresup;
   }
   n=n-chiffresup;
   return n;
}

void Vainqueur(int n,string nom1,string nom2, int aquidejouer){
    if (n==0 && aquidejouer==1){
        cout << "Victoire de " << nom1 << " !";
    }else if (n==0 && aquidejouer==2) {
        cout << "Victoire de " << nom2 << " !";
    }
    cout <<endl<<endl;
}

int main()
{
    string nom1,nom2;
    int n,aquidejouer=1;
    nom1=nom_1();
    nom2=nom_2();
    cout <<endl<<endl<<endl<< " --- Debut du jeu --- ";
    n = nombrealeatoire(5,35);
    while (n!=0){
    nombresallumettes(n);
    aquidejouer = TourparTour(aquidejouer,nom1,nom2);
    n = enlever(n);
    }
    Vainqueur(n,nom1,nom2,aquidejouer);

}
