#include "servisler/YazdirServis.h"
#include <stdio.h>
#include <stdlib.h>


YazdirServis new_YazdirServis(){
	YazdirServis this;
	this = (YazdirServis) malloc(sizeof(struct YAZDIR_SERVIS));
	this->turYazdir = &turYazdir;
	this->detayYazdir = &detayYazdir;
	this->ekraniTemizle = &ekraniTemizle;
	this->delete_YazdirServis = &delete_YazdirServis;
	return this;
}

// her tur sonu şehirlerin nüfusunu ekrana [xx]-[xx] formatında basar
void turYazdir(Sehir* sehirler, int sehirSayisi) {
    int i = 1; // sütun sayacı
    
    for (int j = 0; j < sehirSayisi; j++) {
        Sehir sehir = sehirler[j];
        
        printf("[%d]", sehir->super->nufus);

        // satır sonu veya eleman sonu değilse - koy
        if (i % 5 != 0 && i != sehirSayisi) {
            printf("-");
        }
        
        // 5 eleman sonra alt satıra geç
        if (i % 5 == 0) {
            printf("\n");
        }

        i++;
    }
    
    printf("\n"); 
}

//indexteki şehirde hiyerarşik olarak yukardan aşağı ekrana yazdırır.
void detayYazdir(Sehir* sehirler, int index){
    sehirler[index]->super->ekranaYazdir(sehirler[index]);
}

void ekraniTemizle(){
	// İşletim sistemi Windows ise bu kısmı derle
    #ifdef _WIN32
        system("cls");
    
    // Windows değilse (Linux, Mac vb.) bu kısmı derle
    #else
        system("clear");
    #endif
}
void delete_YazdirServis(YazdirServis this){
	if(this != NULL){
		free(this);
	}
}