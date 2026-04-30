#include "modeller/Ilce.h"
#include "modeller/Mahalle.h"
#include "araclar/SahteVeriUretici.h"
#include <stdlib.h>
#include <stdio.h>


Ilce new_Ilce(int nufus){
	SahteVeriUretici Svu_STATIC = get_SvuInstance();

    Ilce this;
    this = (Ilce)malloc(sizeof(struct ILCE));

    this->mahalleKapasitesi = 10; // Başlangıçta 10 mahalle kapasitesi
    this->mahalleSayisi = 0;      // Başlangıçta içi boş

    this->mahalleler = (Mahalle*)malloc(sizeof(Mahalle) * this->mahalleKapasitesi); 

    char* rastgeleAd = Svu_STATIC->getSehirAd(); 
    this->super = new_Yerlesim(rastgeleAd, nufus);
    
    free(rastgeleAd);

    this->getMahalleler = &getMahalleler;
    this->mahalleEkle = &mahalleEkle;
    this->popMahalle = &popMahalle;
    this->nufusArttir_Ilce = &nufusArttir_Ilce;
    this->nufusGuncelle_Ilce = &nufusGuncelle_Ilce;
    this->bolun_Ilce = &bolun_Ilce;
    this->delete_Ilce = &delete_Ilce;

    this->super->toString = &toString_Ilce; 
    this->super->ekranaYazdir = &ekranaYazdir_Ilce; 
    this->super->yaslandir = &yaslandir_Ilce; 


    return this;

	
}
Mahalle* getMahalleler(const Ilce this){
	if (this == NULL) return NULL;
    return this->mahalleler;
}
void mahalleEkle(const Ilce this, Mahalle mahalle){
	if (this == NULL || mahalle == NULL) return;

    // Kapasite doldu mu kontrolü
    if (this->mahalleSayisi >= this->mahalleKapasitesi) {
        
        this->mahalleKapasitesi *= 2; // Dolunca iki katına çıkar
        
        this->mahalleler = (Mahalle*)realloc(this->mahalleler, sizeof(Mahalle) * this->mahalleKapasitesi);
        
        if (this->mahalleler == NULL) {
            printf("hata: bellek dolu (Ilce - mahalleEkle)\n");
            exit(1); 
        }
    }

    // Yeni mahalleyi diziye ekle ve sayacı artır
    this->mahalleler[this->mahalleSayisi] = mahalle;
    this->mahalleSayisi++;
}

// Bu fonksiyon mahalleyi silmez, referansı döndürüp dizideki sayıyı azaltır.
Mahalle popMahalle(const Ilce this){
	if (this == NULL || this->mahalleSayisi == 0) return NULL;
    
    this->mahalleSayisi--;
    return this->mahalleler[this->mahalleSayisi];
}
int nufusArttir_Ilce(const Ilce this, int artisOrani){
    int yeniNufus = 0;

    // her bir mahalle kendi nüfusunu hesaplar ve döndürür
    for (int i = 0; i < this->mahalleSayisi; i++) {
		yeniNufus += this->mahalleler[i]->nufusArttir_Mahalle(this->mahalleler[i], artisOrani);
	}

	this->super->nufus = yeniNufus;
    return this->super->nufus;
}
int nufusGuncelle_Ilce(const Ilce this){
    int toplamNufus = 0;

	// her bir ilçe kendi nüfusunu hesaplar ve döndürür
	for (int i = 0; i < this->mahalleSayisi; i++) {
			toplamNufus += this->mahalleler[i]->nufusGuncelle_Mahalle(this->mahalleler[i]);
	}
	
	this->super->nufus = toplamNufus; // yeni nüfus
    return this->super->nufus;
}
Ilce bolun_Ilce(const Ilce this){
    Ilce yeniIlce = new_Ilce(0);
	int mahalleSayisi = this->mahalleSayisi;

	// 1 ilçe 1 mahalle:
	if (mahalleSayisi == 1) {
		//tek mahalle varsa ilk mahalledir
		Mahalle yeniMahalle = this->mahalleler[0]->bolun_Mahalle(this->mahalleler[0]);
		yeniIlce->mahalleEkle(yeniIlce, yeniMahalle);
	}
	// 1 ilçe 2 veya 2+ mahalle
	else {
		int aktMahSay = mahalleSayisi / 2;
		for (int i = 0; i < aktMahSay; i++) {
			yeniIlce->mahalleEkle(yeniIlce, this->popMahalle(this));
		}
	}
	return yeniIlce;
}



void ekranaYazdir_Ilce(const Ilce this){}
char* toString_Ilce(const Ilce this){}
void yaslandir_Ilce(const Ilce this){
    for(int i = 0; i < this->mahalleSayisi; i++){
		this->mahalleler[i]->super->yaslandir(this->mahalleler[i]);
	}
}

void delete_Ilce(const Ilce this){
	if (this == NULL) return;

    // Mahalle yapılarını tek tek sil
    while (this->mahalleSayisi > 0) {
        Mahalle silinecekMahalle = this->popMahalle(this);
        if (silinecekMahalle != NULL) {
            silinecekMahalle->delete_Mahalle(silinecekMahalle);
        }
    }

    // Mahalleler dizisini sil
    if (this->mahalleler != NULL) {
        free(this->mahalleler);
    }

    // Yerleşim (super) yapısını sil
    if (this->super != NULL) {
        this->super->delete_Yerlesim(this->super);
    }

    // Ilce yapısını sil
    free(this);
}