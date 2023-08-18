#include <iostream>

using namespace std;

void bandeaudebut(){

    cout << "======== Jeu des Allumettes ========";

}

//affiche le tour du joueur
int tourjoueur(string nj){

    cout<< "\nC'est au joueur "<<nj<<" de jouer : ";
    int nbjoueur;
    cin>>nbjoueur;
    if(nbjoueur<1 or nbjoueur>3)
    {
        while (nbjoueur<1 or nbjoueur>3) {


        cout<<" chiffres non valide ressayer : ";
        cin>>nbjoueur;}
    }
    return nbjoueur;

}




//cette procédure répéte le nombre d'alumettes selon le chiffres envoyé, en sachant que le nombre envoyé est aléatoire.
void alumettes(int n)
{

    int i;
    for (i=0;i<n;i++)
    {

        cout<<" | ";
    }

}




int nombrealeatoire(int min,int max){
    srand(time(NULL));
    return rand()%(max-min)+min;
}




int main()
{
//ici on appelle le début du jeu qui doit s'afficher, en plus il demande le nom des joueurs.
    bandeaudebut();
    cout<<"\nEntre nom du joueur 1 : ";
    string j1;
    cin>>j1;
    cout<<"\nEntre nom du joueur 2 : ";
    string j2;
    cin>>j2;

//ici on envoie le choix du joueur sélectionner et on enlève les alumettes.

    int n;
    n=nombrealeatoire(5,35);
do
   {
    alumettes(n);
        cout<<"\n"<<n<<"\n";
        n=n-tourjoueur(j1);
        alumettes(n);
            cout<<"\n"<<n<<"\n";
            n=n-tourjoueur(j2);


if(n==0 and tourjoueur(j1))
{
    cout<<j2<<" tu as gagné ";
    exit(0);
    }
if(n==0 and tourjoueur(j2))
{
    cout<<j1<<" tu as gagné ";
    exit(0);
    }


    }while (n>0);


}
