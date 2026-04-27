#include "araclar/BaslangicKuralHesaplayici.h"
#include <stdlib.h>


BaslangicKuralHesaplayici new_BaslangicKuralHesaplayici(){
	BaslangicKuralHesaplayici this;
	this = (BaslangicKuralHesaplayici)malloc(sizeof(struct BASLANGIC_KURAL_HESAPLAYICI));
	this->gercekSayiHesapla = &gercekSayiHesapla;
	this->gercekNufusHesapla = &gercekNufusHesapla;
	this->delete_Bkh = &delete_Bkh;
}

// Mahalleleri ilçelere eşit dağılabilir hale getirir
int gercekSayiHesapla(int sayi){
		int gercekSayi = sayi;
		int onlar, birler;
		onlar = (sayi % 100) / 10;
		birler = sayi % 10;

		while (birler == 0 || birler % onlar != 0) {
			birler = (birler + 1) % 10;
		}

		gercekSayi = (onlar * 10) + birler;
		return gercekSayi;
}

// toplam nüfus sayıyı mahalle sayısına dağılabilir (bölünebilir hale getirir)
// örn: 18->24 24 % 4 == 0
int gercekNufusHesapla(int nufus, int mahalleSayisi){
	int gercekNufus = nufus;
    
    while (gercekNufus % mahalleSayisi != 0) {
        gercekNufus++;
    }
    
    return gercekNufus;
}

void delete_Bkh(BaslangicKuralHesaplayici this){
	if(this != NULL) free(this);
}