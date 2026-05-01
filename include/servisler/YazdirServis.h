/**
*
* @author Ahmet Faruk İkiz faruk.ikiz@ogr.sakarya.edu.tr
* @since 29.04.2026
* <p>
* Aldığı sehir sınıfının verilerini uygun formatta yazdıran servis sınıfı
* </p>
*/


#ifndef YAZDIR_SERVIS_H
#define YAZDIR_SERVIS_H

#include "modeller/Sehir.h"

struct YAZDIR_SERVIS
{
	void (*turYazdir)(Sehir*, int);
	void (*detayYazdir)(Sehir*, int); 
	void (*ekraniTemizle)();
	void (*delete_YazdirServis)(struct YAZDIR_SERVIS*);
};

typedef struct YAZDIR_SERVIS* YazdirServis;

YazdirServis new_YazdirServis();
void turYazdir(Sehir*, int);
void detayYazdir(Sehir*, int);
void ekraniTemizle();
void delete_YazdirServis(YazdirServis);


#endif