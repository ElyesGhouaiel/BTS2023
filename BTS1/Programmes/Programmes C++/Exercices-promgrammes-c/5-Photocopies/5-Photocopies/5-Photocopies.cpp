// Photocopies.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//chenal    killian
//21/09/2021
//
// nombres de photocopies
//
// le programme doit demander à l'itilisateur le nombre de photocopies effectuées puis, il doit afficher le mmotant total à payer en euros!
//

#include <iostream>
using namespace std;
//Déclaration des variables
float y,x;

int main() //début
{
	cout << "Inserer le nombres de phtocopies effectues ";
	cin >> x;
	if (x<10 && x >=0)
	{
		y = x*0.20;
		
	}
	else
	{
		if (x > 10 && x <= 30)
		{
			y = 10 * 0.2 + ((x - 10) * 0.10);
		}		
		else
		{
			y = (10 * 0.2) + (20 * 0.1) +( (x - 30) * 0.05);
		

		}
		
	}
	cout << "le montant a payer est de : " << y;

}
