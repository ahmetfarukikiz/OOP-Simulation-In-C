#include "modeller/Sehir.h"
#include "araclar/SahteVeriUretici.h"
#include <stdlib.h>
#include <stdio.h>


//private fonksiyonlar (header'da olmayanlar)
int getNufusArtisOrani(Sehir this) {
	int onlar, birler, nufus;
	nufus = this->super->nufus;

	onlar = (nufus % 100) / 10;
	birler = nufus % 10;
	return onlar + birler;
}

// public fonksiyonlar

Sehir new_Sehir(int nufus){

	SahteVeriUretici Svu_STATIC = new_SahteVeriUretici();

	Sehir this;
	this = (Sehir)malloc(sizeof(struct SEHIR));

	this->ilceKapasitesi = 10; // başlangıçta 10 ilçe kapasitesi todo
    this->ilceSayisi = 0; // Başlangıçta içi boş

	this->ilceler = (Ilce*)malloc(sizeof(Ilce) * this->ilceKapasitesi); 

	//burası değişebilir todo (belki buffer parametre olarak gönderilebilir)
	char* rastgeleAd = Svu_STATIC->getSehirAd();
	this->super = new_Yerlesim(rastgeleAd, nufus);
	// Svu malloc ile alan açtığındna free ile temizliyoruz
	free(rastgeleAd);

	this->getIlceler = &getIlceler;
	this->ilceEkle = &ilceEkle;
	this->popIlce = &popIlce;
	this->nufusArttir = &nufusArttir;
	this->nufusGuncelle = &nufusGuncelle;
	this->dortBasasamakli = &dortBasasamakli;
	this->bolun = &bolun;
	this->delete_Sehir = &delete_Sehir;

	// Override edilen metotlar
	this->super->toString = &toString_Sehir; 
	this->super->ekranaYazdir = &ekranaYazdir_Sehir; 
	this->super->yaslandir = &yaslandir_Sehir; 

	Svu_STATIC->delete_Svu(Svu_STATIC);

	return this;
}
Ilce* getIlceler(const Sehir this){

}
void ilceEkle(const Sehir this, Ilce ilce){
	if (this == NULL || ilce == NULL) return;

	// kapasite doldu mu kontrolü
    if (this->ilceSayisi >= this->ilceKapasitesi) {

        this->ilceKapasitesi *= 2; //dolunca iki katına çıkar
        
        this->ilceler = (Ilce*)realloc(this->ilceler, sizeof(Ilce) * this->ilceKapasitesi);
        
        if (this->ilceler == NULL) {
            printf("hata: bellek dolu\n");
            exit(1); 
        }
    }

    // Yeni ilçeyi diziye ekle ve sayacı artır
    this->ilceler[this->ilceSayisi] = ilce;
    this->ilceSayisi++;
}

//bu fonksiyon ilceyi silmez referansı döndürüp dizideki sayıyı azaltır.
Ilce popIlce(const Sehir this){
    if (this == NULL || this->ilceSayisi == 0) return NULL;
    this->ilceSayisi--;
    return this->ilceler[this->ilceSayisi];
}
void yaslandir_Sehir(const Sehir this){

}
void nufusArttir(const Sehir this){

}
void nufusGuncelle(const Sehir this){

}
void ekranaYazdir_Sehir(const Sehir this){

}
char* toString_Sehir(const Sehir this){ // Override

} 
boolean dortBasasamakli(const Sehir this){
	return (this->super->nufus >= 1000);
}
Sehir bolun(const Sehir this){

}
void delete_Sehir(Sehir this){
	// ilçe yapılarını tek tek sil
	while (this->ilceSayisi > 0) {
        Ilce silinecekIlce = this->popIlce(this);
        if (silinecekIlce != NULL) {
            silinecekIlce->delete_Ilce(silinecekIlce);
        }
    }
	// ilceler dizisini sil
	if (this->ilceler != NULL) {
        free(this->ilceler);
    }
	// Yerleşim super yapısını sil
	if (this->super != NULL) {
		this->super->delete_Yerlesim(this->super);
	}
	//Sehir'i sil
	free(this);
}