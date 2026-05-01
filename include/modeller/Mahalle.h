/**
*
* @author Ahmet Faruk İkiz faruk.ikiz@ogr.sakarya.edu.tr
* @since 26.04.2026
* <p>
* Mahalleye ait verileri tutar ve bu verilere ait iç (bölünme, yaşlanma vb) hesaplamaları yapar.
* </p>
*/

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
	int (*nufusArttir_Mahalle)(struct MAHALLE*, int);
	int (*nufusGuncelle_Mahalle)(struct MAHALLE*);
	struct MAHALLE* (*bolun_Mahalle)(struct MAHALLE*);
	void (*delete_Mahalle)(struct MAHALLE*);
};
typedef struct MAHALLE* Mahalle;

Mahalle new_Mahalle(int nufus);
Kisi* getKisiler(const Mahalle);
void kisiEkle(const Mahalle, Kisi);
Kisi popKisi(const Mahalle);
int nufusArttir_Mahalle(const Mahalle, int);
int nufusGuncelle_Mahalle(const Mahalle);
Mahalle bolun_Mahalle(const Mahalle);
void delete_Mahalle(const Mahalle);

void ekranaYazdir_Mahalle(const Mahalle); // Override
char* toString_Mahalle(const Mahalle); // Override
void yaslandir_Mahalle(const Mahalle); // Override
#endif