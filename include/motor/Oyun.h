#ifndef OYUN_H
#define OYUN_H

#include "modeller/Sehir.h"
#include "servisler/OyunBaslaticiServis.h"

struct OYUN
{
	int* sayiDizi;
	int sayiDiziUz;
	int toplamTurSayisi;
	Sehir* sehirler;
	OyunBaslaticiServis oyunBaslaticiServis;

	void (*baslat)(struct OYUN*);
	void (*delete_Oyun)(struct OYUN*);

};
typedef struct OYUN* Oyun;

//public fonksiyonlar
Oyun new_Oyun(int turSayisi, int* sayiDizi, int sayiDiziUz);
void baslat(const Oyun);
void delete_Oyun(Oyun);

#endif