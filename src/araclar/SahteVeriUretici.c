#include "araclar/SahteVeriUretici.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

static SahteVeriUretici instance = NULL;
#define MAX_BUFFER 256

//private
char** dosyaOku(const char* dosyaAdi, int satirSayisi);

// private kurucu get instance ilk kez kullanıldığında çalışır
SahteVeriUretici new_SahteVeriUretici(){
	SahteVeriUretici this;
	this = (SahteVeriUretici)malloc(sizeof(struct SAHTE_VERI_URETICI));

	this->veriSayisi = 10000;
    
    srand(time(NULL));

    // Dosyaları RAM'e yükle
    this->isimler = dosyaOku("SahteVeri/isimler.txt", this->veriSayisi);
    this->soyisimler = dosyaOku("SahteVeri/soyisimler.txt", this->veriSayisi);
    this->sehirler = dosyaOku("SahteVeri/sehirler.txt", this->veriSayisi);
    this->ilceler = dosyaOku("SahteVeri/ilceler.txt", this->veriSayisi);
    this->mahalleler = dosyaOku("SahteVeri/mahalleler.txt", this->veriSayisi);

	this->getKisiAd = &getKisiAd;
	this->getKisiSoyad = &getKisiSoyad;
	this->getSehirAd = &getSehirAd;
	this->getIlceAd = &getIlceAd;
	this->getKisiYas = &getKisiYas;
	this->getMahalleAd = &getMahalleAd;
	this->delete_Svu = &delete_Svu;

	return this;
}

//private
// Dosyadaki verileri okuyup ram'e aktarıp dinamik bir dizide tutan fonksiyon.
char** dosyaOku(const char* dosyaAdi, int satirSayisi) {
    char** dizi = (char**)malloc(satirSayisi * sizeof(char*));
    FILE* dosya = fopen(dosyaAdi, "r");
    
    if (dosya == NULL) {
        printf("HATA: %s dosyasi bulunamadi!\n", dosyaAdi);
        exit(1);
    }

    char buffer[MAX_BUFFER];
    int i = 0;
    
    while (i < satirSayisi && fgets(buffer, MAX_BUFFER, dosya) != NULL) {
        // Satır sonundaki \n ve \r karakterlerini temizler
        buffer[strcspn(buffer, "\r")] = 0; 
        buffer[strcspn(buffer, "\n")] = 0;
        
        dizi[i] = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(dizi[i], buffer);
        i++;
    }
    
    fclose(dosya);
    return dizi;
}



//dışardan çağrılan bellekteki tek örneği döndüren fonksiyon.
SahteVeriUretici get_SvuInstance() {
    // Eğer daha önce hiç üretilmediyse yeni bir örnek oluştur
    if (instance == NULL) {
        instance = new_SahteVeriUretici(); 
    }
    
    // zaten bellekte varsa olan pointerı döndür
    return instance; 
}

char* getKisiAd(){ return instance->isimler[rand() % instance->veriSayisi]; }
char* getKisiSoyad(){ return instance->soyisimler[rand() % instance->veriSayisi]; }
char* getSehirAd(){ return instance->sehirler[rand() % instance->veriSayisi]; }
char* getIlceAd(){ return instance->ilceler[rand() % instance->veriSayisi]; }
char* getMahalleAd(){ return instance->mahalleler[rand() % instance->veriSayisi]; }
int getKisiYas(){ return rand() % 51; }

// static instance'ı temizleyen fonksiyon, program sonunda çağrılır.
void delete_Svu(){
    if (instance == NULL) return;
    for (int i = 0; i < instance->veriSayisi; i++) {
        free(instance->isimler[i]);
        free(instance->soyisimler[i]);
        free(instance->sehirler[i]);
        free(instance->ilceler[i]);
        free(instance->mahalleler[i]);
    }
    free(instance->isimler);
    free(instance->soyisimler);
    free(instance->sehirler);
    free(instance->ilceler);
    free(instance->mahalleler);
        
    free(instance); 
    instance = NULL;     
    
}






