/**
*
* @author Ahmet Faruk İkiz faruk.ikiz@ogr.sakarya.edu.tr
* @since 27.04.2026
* <p>
* Aldığı sayıları BaslangicKuralHesaplayici sınıfı yardımıyla kullanmaya uygun hale getirir. 
* Bu sayılarla Yerleşke ve kişi modellerini oluşturur. Oyun sınıfına içi dolu Şehir listesi döndürür.
* </p>
*/

#ifndef OYUNBASLATICISERVIS_H
#define OYUNBASLATICISERVIS_H

#include "modeller/Sehir.h"

struct OYUNBASLATICISERVIS
{
	Sehir* (*yerleskeOlustur)(struct OYUNBASLATICISERVIS*, int*, int);
	void (*delete_OyunBaslaticiServis)(struct OYUNBASLATICISERVIS*);
};
typedef struct OYUNBASLATICISERVIS* OyunBaslaticiServis;

OyunBaslaticiServis new_OyunBaslaticiServis();
Sehir* yerleskeOlustur(const OyunBaslaticiServis this, int*, int);
void delete_OyunBaslaticiServis(OyunBaslaticiServis);

#endif