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
Mahalle* getMahalleler(Ilce this){
	if (this == NULL) return NULL;
    return this->mahalleler;
}
void mahalleEkle(Ilce this, Mahalle mahalle){
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
Mahalle popMahalle(Ilce this){
	if (this == NULL || this->mahalleSayisi == 0) return NULL;
    
    this->mahalleSayisi--;
    return this->mahalleler[this->mahalleSayisi];
}
void nufusArttir_Ilce(Ilce this){}
void nufusGuncelle_Ilce(Ilce this){}
Ilce bolun_Ilce(Ilce this){}

void delete_Ilce(Ilce this){
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

void ekranaYazdir_Ilce(const Ilce this){}
char* toString_Ilce(const Ilce this){}
void yaslandir_Ilce(const Ilce this){}