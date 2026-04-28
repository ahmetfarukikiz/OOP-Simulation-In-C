#ifndef ILCE_H
#define ILCE_H

#include "Yerlesim.h"

struct ILCE
{
	Yerlesim super;
};

typedef struct ILCE* Ilce;

void ekranaYazdir_Ilce(const Ilce); // Override
char* toString_Ilce(const Ilce); // Override
void yaslandir_Ilce(const Ilce); // Override
#endif