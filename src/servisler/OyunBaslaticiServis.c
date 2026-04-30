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

		Sehir sehir = new_Sehir(nufus);

		// ilçe başına mahalle sayısı
		b_mahalleSayisi = birler/onlar;

		ilceleriOlustur(sehir, ilceSayisi, b_mahalleSayisi);
		sehirler[i] = sehir;
	}

	Bkh_STATIC->delete_Bkh(Bkh_STATIC);
	return sehirler;
}

void ilceleriOlustur(Sehir sehir, int ilceSayisi, int mahalleSayisi){
	if (sehir == NULL || sehir->super == NULL || ilceSayisi == 0) return;

	// eşit paylaştır bölünmeme ihtimali yok çünkü tüm sayı birlere, birler onlara bölünüyor.
	int ilceNufusu = sehir->super->nufus / ilceSayisi; 
														

	for (int i = 0; i < ilceSayisi; i++) {
		Ilce ilce = new_Ilce(ilceNufusu);
		mahalleleriOlustur(ilce, mahalleSayisi);

		sehir->ilceEkle(sehir, ilce);

	}

}
void mahalleleriOlustur(Ilce ilce, int mahalleSayisi){
	if (ilce == NULL || ilce->super == NULL || mahalleSayisi <= 0) return;

	int mahalleNufusu = ilce->super->nufus / mahalleSayisi;

	for (int i = 0; i < mahalleSayisi; i++) {
		Mahalle mahalle = new_Mahalle(mahalleNufusu);
		kisileriOlustur(mahalle);
		ilce->mahalleEkle(ilce, mahalle);
	}
}
void kisileriOlustur(Mahalle mahalle){
	if (mahalle == NULL || mahalle->super == NULL) return;
	
	int kisiSayisi = mahalle->super->nufus;

	for (int i = 0; i < kisiSayisi; i++) {
		Kisi kisi = new_Kisi();
		mahalle->kisiEkle(mahalle, kisi);
	}
}

void delete_OyunBaslaticiServis(OyunBaslaticiServis this){
	if(this != NULL) free(this);
}
