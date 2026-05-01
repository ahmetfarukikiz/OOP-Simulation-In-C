#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "modeller/Kisi.h"
#include "araclar/SahteVeriUretici.h"

static int NextId = 100;

Kisi new_Kisi(){
	SahteVeriUretici Svu_STATIC = get_SvuInstance();
	Kisi this = (Kisi)malloc(sizeof(struct KISI));

	// SVU'dan isim ve soyismi çekiyoruz
    char* rastgeleAd = Svu_STATIC->getKisiAd();
    char* rastgeleSoyad = Svu_STATIC->getKisiSoyad();

    // Gelen değerleri deep copy ile ata.
    this->ad = (char*)malloc((strlen(rastgeleAd) + 1) * sizeof(char));
    strcpy(this->ad, rastgeleAd);

    this->soyad = (char*)malloc((strlen(rastgeleSoyad) + 1) * sizeof(char));
    strcpy(this->soyad, rastgeleSoyad);

    this->yas = Svu_STATIC->getKisiYas();
	this->id = NextId++;
	this->ekranaYazdir_Kisi = &ekranaYazdir_Kisi;
	this->yaslandir_Kisi = &yaslandir_Kisi;
	this->toString_Kisi = &toString_Kisi;
	this->delete_Kisi = &delete_Kisi;

	return this;
}
void ekranaYazdir_Kisi(const Kisi this){
	if (this == NULL) return;

    // toString_Kisi'den gelen stringi al (heap)
    char* kisiString = this->toString_Kisi(this);
    
    if (kisiString != NULL) {
        printf("%s\n", kisiString); 
        free(kisiString); //heapte oluşturulan stringi serbest bırak
    }
}
void yaslandir_Kisi(const Kisi this){
	this->yas++;
}
char* toString_Kisi(const Kisi this){
	if (this == NULL) return NULL;

    char tampon[50];

    snprintf(tampon, sizeof(tampon), "\t%d-%s %s-%d", this->id, this->ad, this->soyad, this->yas);

    char* sonuc = (char*)malloc((strlen(tampon) + 1) * sizeof(char));
    strcpy(sonuc, tampon);

    return sonuc; // Çağıran kişi bunu free ile serbest bırakmalı.
}
void delete_Kisi(const Kisi this){
	if (this == NULL) return;
    
    if (this->ad != NULL) free(this->ad);
    if (this->soyad != NULL) free(this->soyad);
    
    free(this);
}