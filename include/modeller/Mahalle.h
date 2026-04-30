#ifndef MAHALLE_H
#define MAHALLE_H

#include "Yerlesim.h"
#include "Kisi.h"

struct MAHALLE
{
	Yerlesim super;
	Kisi* kisiler;
	int kisiSayisi;
	int kisiKapasitesi;
	Kisi* (*getKisiler)(struct MAHALLE*);
	void (*kisiEkle)(struct MAHALLE*, Kisi);
	Kisi (*popKisi)(struct MAHALLE*);
	void (*nufusArttir_Mahalle)(struct MAHALLE*);
	void (*nufusGuncelle_Mahalle)(struct MAHALLE*);
	struct MAHALLE* (*bolun_Mahalle)(struct MAHALLE*);
	void (*delete_Mahalle)(struct MAHALLE*);
};
typedef struct MAHALLE* Mahalle;

Mahalle new_Mahalle(int nufus);
Kisi* getKisiler(const Mahalle);
void kisiEkle(const Mahalle, Kisi);
Kisi popKisi(const Mahalle);
void nufusArttir_Mahalle(const Mahalle);
void nufusGuncelle_Mahalle(const Mahalle);
Mahalle bolun_Mahalle(const Mahalle);
void delete_Mahalle(Mahalle this);

void ekranaYazdir_Mahalle(const Mahalle); // Override
char* toString_Mahalle(const Mahalle); // Override
void yaslandir_Mahalle(const Mahalle); // Override
#endif