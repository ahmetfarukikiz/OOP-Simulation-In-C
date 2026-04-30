#include "araclar/SahteVeriUretici.h"
#include <stdlib.h>

static SahteVeriUretici instance = NULL;

// private kurucu get instance ilk kez kullanıldığında çalışır
SahteVeriUretici new_SahteVeriUretici(){
	SahteVeriUretici this;
	this = (SahteVeriUretici)malloc(sizeof(struct SAHTE_VERI_URETICI));
	this->getKisiAd = &getKisiAd;
	this->getKisiSoyad = &getKisiSoyad;
	this->getSehirAd = &getSehirAd;
	this->getIlceAd = &getIlceAd;
	this->getMahalleAd = &getMahalleAd;
	this->delete_Svu = &delete_Svu;

	return this;
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

char* getKisiAd(){ return "Ahmet"; }
char* getKisiSoyad(){ return "İkiz"; }
int getKisiYas(){ return 5; }
char* getSehirAd(){ return "Ankara"; }
char* getIlceAd(){ return "Çankaya"; }
char* getMahalleAd(){ return "Kızılay"; }	

// static instance'ı temizleyen fonksiyon, program sonunda çağrılır.
void delete_Svu(){
	if (instance != NULL) {
        free(instance); 
        instance = NULL; 
    }
}






