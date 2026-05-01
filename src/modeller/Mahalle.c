#include "modeller/Mahalle.h"
#include "modeller/Kisi.h"
#include "araclar/SahteVeriUretici.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Mahalle new_Mahalle(int nufus){
	SahteVeriUretici Svu_STATIC = get_SvuInstance();

    Mahalle this;
    this = (Mahalle)malloc(sizeof(struct MAHALLE));

    // Dinamik dizi (ArrayList) kapasite ayarları
    this->kisiKapasitesi = 10;
    this->kisiSayisi = 0;
    
    this->kisiler = (Kisi*)malloc(sizeof(Kisi) * this->kisiKapasitesi);

    char* rastgeleAd = Svu_STATIC->getMahalleAd(); 
    this->super = new_Yerlesim(rastgeleAd, nufus);
	
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

int nufusArttir_Mahalle(const Mahalle this, int artisOrani){
   if (this == NULL) return 0;

    int eklenecekKisiSayisi, yeniNufus;
    int mevcutNufus = this->super->nufus;

    if (artisOrani == 0) {
        eklenecekKisiSayisi = 1;
        yeniNufus = mevcutNufus + 1;
    } else {
        int eskiNufus = mevcutNufus;
        yeniNufus = artisOrani * mevcutNufus;
        eklenecekKisiSayisi = yeniNufus - eskiNufus;
    }


    for (int i = 0; i < eklenecekKisiSayisi; i++) {
        this->kisiEkle(this, new_Kisi());
    }

    this->super->nufus = yeniNufus;
    return this->super->nufus;
}
int nufusGuncelle_Mahalle(const Mahalle this){
    this->super->nufus = this->kisiSayisi;
    return this->super->nufus;
}
Mahalle bolun_Mahalle(const Mahalle this){
    Mahalle yeniMahalle = new_Mahalle(0);
	int kisiSayisi = this->super->nufus;

	// tam sayı bölmesi nüfus tekse fazlalık eskide kalıcak
	int aktKisiSay = kisiSayisi / 2;
	for (int i = 0; i < aktKisiSay; i++) {
		//eski mahalleden kişiler aktarılıyor
		yeniMahalle->kisiEkle(yeniMahalle, this->popKisi(this));
	}

	return yeniMahalle;       
}

 // Override
void ekranaYazdir_Mahalle(const Mahalle this){
    if (this == NULL) return;

    char* mahalleString = this->super->toString(this);
    
    if (mahalleString != NULL) {
        printf("%s\n", mahalleString); 
        free(mahalleString); //heapte oluşturulan stringi serbest bırak
    }
    printf("Kisiler:\n");
	for(int i = 0; i < this->kisiSayisi; i++){
		this->kisiler[i]->ekranaYazdir_Kisi(this->kisiler[i]);
	}
}
 // Override
char* toString_Mahalle(const Mahalle this){
    if (this == NULL) return NULL;

    char tampon[50];

    snprintf(tampon, sizeof(tampon), "Mahalle: %s-Nufus: %d", this->super->ad, this->super->nufus);

    char* sonuc = (char*)malloc((strlen(tampon) + 1) * sizeof(char));
    strcpy(sonuc, tampon);

    return sonuc; // Çağıran kişi bunu free ile serbest bırakmalı.
} 
// Override
void yaslandir_Mahalle(const Mahalle this){
    for(int i = 0; i < this->kisiSayisi; i++){
		this->kisiler[i]->yaslandir_Kisi(this->kisiler[i]);
	}
}

void delete_Mahalle(const Mahalle this){
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