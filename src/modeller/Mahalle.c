#include "modeller/Mahalle.h"
#include "modeller/Kisi.h"
#include "araclar/SahteVeriUretici.h"
#include <stdlib.h>
#include <stdio.h>

Mahalle new_Mahalle(int nufus){
	SahteVeriUretici Svu_STATIC = get_SvuInstance();

    Mahalle this;
    this = (Mahalle)malloc(sizeof(struct MAHALLE));

    // Dinamik dizi (ArrayList) kapasite ayarları
    this->kisiKapasitesi = 10;
    this->kisiSayisi = 0;
    
    this->kisiler = (Kisi*)malloc(sizeof(Kisi) * this->kisiKapasitesi);

    char* rastgeleAd = Svu_STATIC->getSehirAd(); 
    this->super = new_Yerlesim(rastgeleAd, nufus);
    free(rastgeleAd);
	
    this->getKisiler = &getKisiler;
    this->kisiEkle = &kisiEkle;
    this->popKisi = &popKisi;
    this->nufusArttir_Mahalle = &nufusArttir_Mahalle;
    this->nufusGuncelle_Mahalle = &nufusGuncelle_Mahalle;
    this->bolun_Mahalle = &bolun_Mahalle;
	this->delete_Mahalle = &delete_Mahalle;

    // Override edilen metotlar
    this->super->toString = &toString_Mahalle;
    this->super->ekranaYazdir = &ekranaYazdir_Mahalle;
    this->super->yaslandir = &yaslandir_Mahalle;


    return this;
}
Kisi* getKisiler(const Mahalle this){
	if (this == NULL) return NULL;
    return this->kisiler;
}
void kisiEkle(const Mahalle this, Kisi kisi){
	if (this == NULL || kisi == NULL) return;

    // kapasite doldu mu kontrolü
    if (this->kisiSayisi >= this->kisiKapasitesi) {
        
        this->kisiKapasitesi *= 2; 
        
        this->kisiler = (Kisi*)realloc(this->kisiler, sizeof(Kisi) * this->kisiKapasitesi);
        
        if (this->kisiler == NULL) {
            printf("HATA: Bellek dolu (Mahalle - kisiEkle)\n");
            exit(1);
        }
    }

    // Yeni kisiyi diziye ekle ve sayacı artır
    this->kisiler[this->kisiSayisi] = kisi;
    this->kisiSayisi++;
}
Kisi popKisi(const Mahalle this){
	if (this == NULL || this->kisiSayisi == 0) return NULL;
    this->kisiSayisi--;
    return this->kisiler[this->kisiSayisi];
}
void nufusArttir_Mahalle(const Mahalle this){}
void nufusGuncelle_Mahalle(const Mahalle this){}
Mahalle bolun_Mahalle(const Mahalle this){}


void ekranaYazdir_Mahalle(const Mahalle this){

}
char* toString_Mahalle(const Mahalle this){

} // Override
void yaslandir_Mahalle(const Mahalle this){
    for(int i = 0; i < this->kisiSayisi; i++){
		this->kisiler[i]->yaslandir_Kisi(this->kisiler[i]);
	}
}

void delete_Mahalle(Mahalle this){
	if (this == NULL) return;

    // Kisileri tek tek sil
    while (this->kisiSayisi > 0) {
        Kisi silinecekKisi = this->popKisi(this);
        if (silinecekKisi != NULL) {
            silinecekKisi->delete_Kisi(silinecekKisi); // Kisi.c içindeki yıkıcı
        }
    }

    // Kisiler dizisini temizle
    if (this->kisiler != NULL) {
        free(this->kisiler);
    }

    // Yerlesim super yapısını sil
    if (this->super != NULL) {
        this->super->delete_Yerlesim(this->super);
    }

    // Mahalleyi sil
    free(this);
}