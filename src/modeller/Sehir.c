#include "modeller/Sehir.h"
#include "modeller/Ilce.h"	
#include "araclar/SahteVeriUretici.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


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

	SahteVeriUretici Svu_STATIC = get_SvuInstance();

	Sehir this;
	this = (Sehir)malloc(sizeof(struct SEHIR));

	this->ilceKapasitesi = 10; // başlangıçta 10 ilçe kapasitesi todo
    this->ilceSayisi = 0; // Başlangıçta içi boş

	this->ilceler = (Ilce*)malloc(sizeof(Ilce) * this->ilceKapasitesi); 

	char* rastgeleAd = Svu_STATIC->getSehirAd();
	this->super = new_Yerlesim(rastgeleAd, nufus);

	this->getIlceler = &getIlceler;
	this->ilceEkle = &ilceEkle;
	this->popIlce = &popIlce;
	this->nufusArttir_Sehir = &nufusArttir_Sehir;
	this->nufusGuncelle_Sehir = &nufusGuncelle_Sehir;
	this->dortBasamakli = &dortBasamakli;
	this->bolun_Sehir = &bolun_Sehir;
	this->delete_Sehir = &delete_Sehir;

	// Override edilen metotlar
	this->super->toString = &toString_Sehir; 
	this->super->ekranaYazdir = &ekranaYazdir_Sehir; 
	this->super->yaslandir = &yaslandir_Sehir; 

	return this;
}

Ilce* getIlceler(const Sehir this){
	if (this == NULL) return NULL;
    return this->ilceler;
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

 // Override
void yaslandir_Sehir(Sehir this){
	for(int i = 0; i < this->ilceSayisi; i++){
		this->ilceler[i]->super->yaslandir(this->ilceler[i]);
	}
}

// artış oranına göre hesaplaması için bir alt sınıfın metodunu çağırır dönen
// değerleri toplar
void nufusArttir_Sehir(const Sehir this){
	int toplamNufus = 0;
	int artisOrani = getNufusArtisOrani(this);

	// her bir ilçe kendi nüfusunu hesaplar ve döndürür
	for (int i = 0; i < this->ilceSayisi; i++) {
			toplamNufus += this->ilceler[i]->nufusArttir_Ilce(this->ilceler[i], artisOrani);
	}

	this->super->nufus = toplamNufus; // yeni nüfus
}

// ilçelerinin nüfuslarını toplar ve yeni nüfusu hesaplar
void nufusGuncelle_Sehir(const Sehir this){
	int toplamNufus = 0;

	// her bir ilçe kendi nüfusunu hesaplar ve döndürür
	for (int i = 0; i < this->ilceSayisi; i++) {
		toplamNufus += this->ilceler[i]->nufusGuncelle_Ilce(this->ilceler[i]);
	}
	
	this->super->nufus = toplamNufus; // yeni nüfus
}

 // Override
void ekranaYazdir_Sehir(const Sehir this){
	if (this == NULL) return;

    char* sehirString = this->super->toString(this);
    
    if (sehirString != NULL) {
        printf("%s\n", sehirString); 
        free(sehirString); //heapte oluşturulan stringi serbest bırak
    }

	for(int i = 0; i < this->ilceSayisi; i++){
		this->ilceler[i]->super->ekranaYazdir(this->ilceler[i]);
	}
}

 // Override
char* toString_Sehir(const Sehir this){
	 if (this == NULL) return NULL;

    char tampon[50];

    snprintf(tampon, sizeof(tampon), "Sehir: %s-Nufus: %d", this->super->ad, this->super->nufus);

    char* sonuc = (char*)malloc((strlen(tampon) + 1) * sizeof(char));
    strcpy(sonuc, tampon);

    return sonuc; // Çağıran kişi bunu free ile serbest bırakmalı.
} 
boolean dortBasamakli(const Sehir this){
	return (this->super->nufus >= 1000);
}
Sehir bolun_Sehir(const Sehir this){
	Sehir yeniSehir = new_Sehir(0);
		int ilceSayisi = this->ilceSayisi;

		// 1 ilçe
		if (ilceSayisi == 1) {
			Ilce yeniIlce = this->ilceler[0]->bolun_Ilce(this->ilceler[0]);
			yeniSehir->ilceEkle(yeniSehir, yeniIlce);
		}

		// 2 veya 2+ ilçe
		else {
			int aktIlceSay = ilceSayisi / 2;

			for (int i = 0; i < aktIlceSay; i++) {
				yeniSehir->ilceEkle(yeniSehir, this->popIlce(this));
			}
		}

		//yeniSehir'in nüfusunu güncelle
		yeniSehir->nufusGuncelle_Sehir(yeniSehir);
		//Ardından eski şehirin
		this->nufusGuncelle_Sehir(this);

		return yeniSehir;
}
void delete_Sehir(const Sehir this){
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