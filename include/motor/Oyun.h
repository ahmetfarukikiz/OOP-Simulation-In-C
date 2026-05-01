/**
*
* @author Ahmet Faruk İkiz faruk.ikiz@ogr.sakarya.edu.tr
* @since 27.04.2026
* <p>
* Oyun döngüsünü ve servis sınıflarını yöneten motor sınıfı
* </p>
*/

#ifndef OYUN_H
#define OYUN_H

#include "modeller/Sehir.h"
#include "servisler/OyunBaslaticiServis.h"
#include "servisler/YazdirServis.h"

struct OYUN
{
	int* sayiDizi;
	int sayiDiziUz;
	int toplamTurSayisi;
	Sehir* sehirler;
	int sehirSayisi;
	OyunBaslaticiServis oyunBaslaticiServis;
	YazdirServis yazdirici;

	void (*baslat)(struct OYUN*);
	void (*delete_Oyun)(struct OYUN*);

};
typedef struct OYUN* Oyun;

//public fonksiyonlar
Oyun new_Oyun(int turSayisi, int* sayiDizi, int sayiDiziUz);
void baslat(Oyun);
void delete_Oyun(Oyun);

#endif