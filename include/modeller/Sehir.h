#ifndef SEHIR_H
#define SEHIR_H
typedef enum{false, true} boolean;

#include "Yerlesim.h"
#include "Ilce.h"

struct SEHIR
{
	Yerlesim super;
	Ilce* ilceler;
	int ilceSayisi;
    int ilceKapasitesi;

	Ilce* (*getIlceler)(struct SEHIR*);
	void (*ilceEkle)(struct SEHIR*, Ilce);
	Ilce (*popIlce)(struct SEHIR*);
	void (*nufusArttir)(struct SEHIR*);
	void (*nufusGuncelle)(struct SEHIR*);
	boolean (*dortBasasamakli)(struct SEHIR*);
	struct SEHIR* (*bolun)(struct SEHIR*);
	void (*delete_Sehir)(struct SEHIR*);

};
typedef struct SEHIR* Sehir;

Sehir new_Sehir(int);
Ilce* getIlceler(const Sehir);
void ilceEkle(const Sehir, Ilce);
Ilce popIlce(const Sehir);
void nufusArttir(const Sehir);
void nufusGuncelle(const Sehir);
boolean dortBasasamakli(const Sehir);
Sehir bolun(const Sehir);
void delete_Sehir(const Sehir);

void ekranaYazdir_Sehir(const Sehir); // Override
char* toString_Sehir(const Sehir); // Override
void yaslandir_Sehir(const Sehir); // Override


#endif