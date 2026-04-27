#include "servisler/OyunBaslaticiServis.h"
#include <stdlib.h>

OyunBaslaticiServis new_OyunBaslaticiServis(){
	OyunBaslaticiServis this; 
	this = (OyunBaslaticiServis)malloc(sizeof(struct OYUNBASLATICISERVIS));
	this->yerleskeOlustur = &yerleskeOlustur;
	this->delete_OyunBaslaticiServis = &delete_OyunBaslaticiServis;
	return this;
}

// Oyunun başlangıç değerlerini ayarlar ve içi dolu şehir listesini döndürür
Sehir* yerleskeOlustur(const OyunBaslaticiServis this, int* sayiDizi, int sayiDiziUz){
	Sehir* sehirler = (Sehir*)malloc(sizeof(Sehir) * sayiDiziUz);

	//birim sayılarını tutan değişkenler
	int sehirSayisi, ilceSayisi, b_mahalleSayisi, nufus;
	sehirSayisi = sayiDiziUz;

	//şehirler döngüsü
	for(int i = 0; i < sehirSayisi; i++){
		sayiDizi[i];
	}

	return NULL;
}

void delete_OyunBaslaticiServis(OyunBaslaticiServis this){
	if(this != NULL) free(this);
}
