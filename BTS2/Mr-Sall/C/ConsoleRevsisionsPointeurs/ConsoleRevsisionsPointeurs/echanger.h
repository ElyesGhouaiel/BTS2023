#pragma once
#ifndef ECHANGER_H
#define ECHANGER_H

void echanger(int valint1, int valint2); // passage des param�tres par valeur 
void echanger2(int& valint1, int& valint2);// passage par r�f�rence sp�cifique au C++
void echanger3(int* ptrint1, int* ptrint2);//passage par adresse ou pointeur



#endif // !ECHANGER_H
