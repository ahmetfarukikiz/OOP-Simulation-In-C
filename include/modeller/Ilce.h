#ifndef ILCE_H
#define ILCE_H

#include "Yerlesim.h"

struct ILCE
{
	Yerlesim super;
	void (*delete_Ilce)(struct ILCE*);
};

typedef struct ILCE* Ilce;

Ilce new_Ilce();
void delete_Ilce(const Ilce this);

void ekranaYazdir_Ilce(const Ilce); // Override
char* toString_Ilce(const Ilce); // Override
void yaslandir_Ilce(const Ilce); // Override
#endif