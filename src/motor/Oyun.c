#include <stdlib.h>
#include "motor/Oyun.h"
#include "servisler/OyunBaslaticiServis.h"

// private fonksiyonlar
void OyunSonuSatirSutunSor(const Oyun this){

}

// public fonksiyonlar
Oyun new_Oyun(int turSayisi, int* sayiDizi){
	Oyun this;
	this = (Oyun) malloc(sizeof(struct OYUN));
	this->toplamTurSayisi = turSayisi;
	this->sayiDizi = sayiDizi;
	this->sehirler = NULL; //OyunBaslaticiServisten alacak.
	this->oyunBaslaticiServis = new_OyunBaslaticiServis();
	this->baslat = &baslat;
	this->delete_Oyun = &delete_Oyun;
	return this;
}

void baslat(Oyun this){
	this->sehirler = this->oyunBaslaticiServis->yerleskeOlustur(this->oyunBaslaticiServis);
}


// TODO
static void delete_Oyun(const Oyun this){
	if(this->sayiDizi != NULL){
		free(this->sayiDizi);
	}
	if(this->sehirler != NULL){
		free(this->sehirler);
	}
	if(this->oyunBaslaticiServis != NULL){
		free(this->oyunBaslaticiServis);
	}
	free(this);
}
