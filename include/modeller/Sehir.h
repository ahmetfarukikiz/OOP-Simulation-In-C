/**
*
* @author Ahmet Faruk İkiz faruk.ikiz@ogr.sakarya.edu.tr
* @since 26.04.2026
* <p>
* Sehre ait verileri tutar ve bu verilere ait iç hesaplamaları (bölünme vb) yapar.
* </p>
*/

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
	void (*nufusArttir_Sehir)(struct SEHIR*);
	void (*nufusGuncelle_Sehir)(struct SEHIR*);
	boolean (*dortBasamakli)(struct SEHIR*);
	struct SEHIR* (*bolun_Sehir)(struct SEHIR*);
	void (*delete_Sehir)(struct SEHIR*);

};
typedef struct SEHIR* Sehir;

Sehir new_Sehir(int);
Ilce* getIlceler(const Sehir);
void ilceEkle(const Sehir, Ilce);
Ilce popIlce(const Sehir);
void nufusArttir_Sehir(const Sehir);
void nufusGuncelle_Sehir(const Sehir);
boolean dortBasamakli(const Sehir);
Sehir bolun_Sehir(const Sehir);
void delete_Sehir(const Sehir);

void ekranaYazdir_Sehir(const Sehir); // Override
char* toString_Sehir(const Sehir); // Override
void yaslandir_Sehir(const Sehir); // Override


#endif