#include "servisler/OyunBaslaticiServis.h"
#include "araclar/BaslangicKuralHesaplayici.h"

#include "modeller/Sehir.h"
#include "modeller/Ilce.h"
#include "modeller/Mahalle.h"
#include "modeller/Kisi.h"

#include <stdlib.h>

//private fonkların deklarasyonları
void ilceleriOlustur(Sehir, int, int);
void mahalleleriOlustur(Ilce, int);
void kisileriOlustur(Mahalle);

// tüm gövdeler:

OyunBaslaticiServis new_OyunBaslaticiServis(){
	OyunBaslaticiServis this; 
	this = (OyunBaslaticiServis)malloc(sizeof(struct OYUNBASLATICISERVIS));
	this->yerleskeOlustur = &yerleskeOlustur;
	this->delete_OyunBaslaticiServis = &delete_OyunBaslaticiServis;
	return this;
}

// Oyunun başlangıç değerlerini ayarlar ve içi dolu şehir listesini döndürür
Sehir* yerleskeOlustur(const OyunBaslaticiServis this, int* sayiDizi, int sayiDiziUz){
	BaslangicKuralHesaplayici Bkh_STATIC = new_BaslangicKuralHesaplayici();
	Sehir* sehirler = (Sehir*)malloc(sizeof(Sehir) * sayiDiziUz);

	//birim sayılarını tutan değişkenler
	int sehirSayisi, ilceSayisi, b_mahalleSayisi, nufus;
	sehirSayisi = sayiDiziUz;

	//şehirler döngüsü
	for(int i = 0; i < sehirSayisi; i++){

		// mahalleler ilcelere esit paylasılabiliyor
		sayiDizi[i] = Bkh_STATIC->gercekSayiHesapla(sayiDizi[i]);

		int onlar, birler;
		onlar = (sayiDizi[i] % 100) / 10;
		birler = sayiDizi[i] % 10;

		ilceSayisi = onlar;

		// nufus mahallelere eşit paylaştırılabiliyor															
		nufus = Bkh_STATIC->gercekNufusHesapla(sayiDizi[i], birler);

		//TODO NEW_SEHIR eklenecek ve nüfus parametresi gönderilecek
		//Sehir sehir = 

		// ilçe başına mahalle sayısı
		b_mahalleSayisi = birler/onlar;

	}

	return NULL;
}

void ilceleriOlustur(Sehir sehir, int ilceSayisi, int mahalleSayisi){}
void mahalleleriOlustur(Ilce ilce, int mahalleSayisi){}
void kisileriOlustur(Mahalle mahalle){}

void delete_OyunBaslaticiServis(OyunBaslaticiServis this){
	if(this != NULL) free(this);
}
