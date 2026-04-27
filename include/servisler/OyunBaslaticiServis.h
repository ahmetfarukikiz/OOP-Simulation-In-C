#ifndef OYUNBASLATICISERVIS_H
#define OYUNBASLATICISERVIS_H

#include "modeller/Sehir.h"

struct OYUNBASLATICISERVIS
{
	Sehir* (*yerleskeOlustur)(struct OYUNBASLATICISERVIS*, int*);
	void (*delete_OyunBaslaticiServis)(struct OYUNBASLATICISERVIS*);
};
typedef struct OYUNBASLATICISERVIS* OyunBaslaticiServis;

OyunBaslaticiServis new_OyunBaslaticiServis();
Sehir* yerleskeOlustur(const OyunBaslaticiServis this, int*);
void delete_OyunBaslaticiServis(OyunBaslaticiServis);

#endif