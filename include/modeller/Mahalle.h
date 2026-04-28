#ifndef MAHALLE_H
#define MAHALLE_H

#include "Yerlesim.h"

struct MAHALLE
{
	Yerlesim super;
};
typedef struct MAHALLE* Mahalle;

void ekranaYazdir_Mahalle(const Mahalle); // Override
char* toString_Sehir(const Mahalle); // Override
void yaslandir_Sehir(const Mahalle); // Override
#endif