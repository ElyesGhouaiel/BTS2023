#include "echanger.h"

// définition des éléments déclarés dans "échanger.h"
/*******************passage par valeur*******************/
void echanger(int param1, int param2) 
{
		//échanger le contenu des paramètres 
		int temp;
		temp = param1;
		param1 = param2;
		param2 = temp;
}


/*******************passage par référence*******************/
void echanger2(int& param1, int& param2)
{
		//échanger le contenu des paramètres 
		int temp;
		temp = param1;
		param1 = param2;
		param2 = temp;
}

void echanger3(int* ptrint1, int* ptrint2)
{
	int temp;
	temp = *ptrint1; //temp reçoit ce qui est pointé par ptrInt1
	*ptrint1 = *ptrint2;
	*ptrint2 = temp; // ptrint2 reçoit l'adresse de temp
}

