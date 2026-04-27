#ifndef SEHIR_H
#define SEHIR_H
typedef enum{false, true} boolean;

#include "Yerlesim.h"
#include "Ilce.h"

struct SEHIR
{
	Yerlesim super;
	Ilce* ilceler;

};
typedef struct SEHIR* Sehir;

Sehir new_Sehir(int);
Ilce* getIlceler(Sehir);
void ilceEkle(Sehir, Ilce);
void ilceSil(Sehir, Ilce);
Ilce popIlce(Sehir);
void yaslandir(Sehir);
void nufusArttir(Sehir);
void nufusGuncelle(Sehir);
void ekranaYazdir(Sehir);
char* toString_Sehir(Sehir); // Override
boolean dortBasasamakli(Sehir);
Sehir bolun();
Sehir delete_Sehir(Sehir);


#endif