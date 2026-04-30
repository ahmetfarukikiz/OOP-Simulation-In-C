#ifndef ILCE_H
#define ILCE_H

#include "Yerlesim.h"
#include "Mahalle.h"

struct ILCE
{
	Yerlesim super;
	Mahalle* mahalleler;
	int mahalleSayisi;
	int mahalleKapasitesi;
	Mahalle* (*getMahalleler)(struct ILCE*);
	void (*mahalleEkle)(struct ILCE*, Mahalle);
	Mahalle (*popMahalle)(struct ILCE*);
	void (*nufusArttir_Ilce)(struct ILCE*);
	void (*nufusGuncelle_Ilce)(struct ILCE*);
	struct ILCE* (*bolun_Ilce)(struct ILCE*);
	void (*delete_Ilce)(struct ILCE*);
};

typedef struct ILCE* Ilce;

Ilce new_Ilce(int nufus);
Mahalle* getMahalleler(const Ilce);
void mahalleEkle(const Ilce, Mahalle);
Mahalle popMahalle(const Ilce);
void nufusArttir_Ilce(const Ilce);
void nufusGuncelle_Ilce(const Ilce);
struct ILCE* bolun_Ilce(const Ilce);
void delete_Ilce(const Ilce this);

void ekranaYazdir_Ilce(const Ilce); // Override
char* toString_Ilce(const Ilce); // Override
void yaslandir_Ilce(const Ilce); // Override
#endif