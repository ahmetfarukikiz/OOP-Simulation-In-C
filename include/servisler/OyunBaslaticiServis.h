#ifndef OYUNBASLATICISERVIS_H
#define OYUNBASLATICISERVIS_H

#include "modeller/Sehir.h"

struct OYUNBASLATICISERVIS
{
	Sehir (*yerleskeOlustur)(struct OYUNBASLATICISERVIS*);
};
typedef struct OYUNBASLATICISERVIS* OyunBaslaticiServis;

OyunBaslaticiServis new_OyunBaslaticiServis();
Sehir yerleskeOlustur(const OyunBaslaticiServis);

#endif