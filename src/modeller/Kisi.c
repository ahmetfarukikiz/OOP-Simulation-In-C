#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "modeller/Kisi.h"
#include "araclar/SahteVeriUretici.h"

static int NextId = 100;

Kisi new_Kisi(){
	Kisi this = (Kisi)malloc(sizeof(struct KISI));
	this->ad = NULL;
	this->soyad = NULL;
	this->yas = 0;;
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
void yaslandir_Kisi(Kisi this){
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
void delete_Kisi(Kisi this){}