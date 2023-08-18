#include "echanger.h"

// d�finition des �l�ments d�clar�s dans "�changer.h"
/*******************passage par valeur*******************/
void echanger(int param1, int param2) 
{
		//�changer le contenu des param�tres 
		int temp;
		temp = param1;
		param1 = param2;
		param2 = temp;
}


/*******************passage par r�f�rence*******************/
void echanger2(int& param1, int& param2)
{
		//�changer le contenu des param�tres 
		int temp;
		temp = param1;
		param1 = param2;
		param2 = temp;
}

void echanger3(int* ptrint1, int* ptrint2)
{
	int temp;
	temp = *ptrint1; //temp re�oit ce qui est point� par ptrInt1
	*ptrint1 = *ptrint2;
	*ptrint2 = temp; // ptrint2 re�oit l'adresse de temp
}

