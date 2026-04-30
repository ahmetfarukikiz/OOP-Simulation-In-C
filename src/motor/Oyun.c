#include <stdlib.h>
#include <stdio.h>
#include "motor/Oyun.h"

// private fonksiyonlar
void oyunSonuSatirSutunSor(const Oyun this){
	int satir, sutun, index;

    printf("Satir Girin (0'dan baslar):\n");
    scanf("%d", &satir);

    printf("Sutun Girin (0'dan baslar):\n");
    scanf("%d", &sutun);

    index = satir * 5 + sutun; // her satirda 5 eleman var

    this->yazdirici->detayYazdir(this->sehirler, index);
}

// public fonksiyonlar
Oyun new_Oyun(int turSayisi, int* sayiDizi, int sayiDiziUz){
	Oyun this;
	this = (Oyun) malloc(sizeof(struct OYUN));
	this->toplamTurSayisi = turSayisi;
	this->sayiDizi = sayiDizi;
	this->sayiDiziUz = sayiDiziUz;
	this->sehirler = NULL; //OyunBaslaticiServisten alacak.
	this->sehirSayisi = sayiDiziUz;
	this->oyunBaslaticiServis = new_OyunBaslaticiServis();
	this->yazdirici = new_YazdirServis();
	this->baslat = &baslat;
	this->delete_Oyun = &delete_Oyun;
	return this;
}

void baslat(Oyun this){
	this->sehirler = this->oyunBaslaticiServis->
	yerleskeOlustur(this->oyunBaslaticiServis, this->sayiDizi, this->sayiDiziUz);
	
	printf("Baslangic Durumu:\n");
	this->yazdirici->turYazdir(this->sehirler, this->sehirSayisi);

	// ana loop (TUR DÖNGÜSÜ)
		for (int tur = 1; tur <= this->toplamTurSayisi; tur++) {
		// her tur bölünmeyle oluşacak şehirleri tutacak geçici liste
        Sehir* yeniSehirler = (Sehir*)malloc(sizeof(Sehir) * this->sehirSayisi);
        int yeniSehirSayisi = 0;

        // tur işlemleri
        for (int i = 0; i < this->sehirSayisi; i++) {
            Sehir sehir = this->sehirler[i];
            
            sehir->nufusArttir_Sehir(sehir);
            sehir->super->yaslandir(sehir);

            //şehrin tur işlemlerinden sonra dört basamaklıysa böl
            if (sehir->dortBasamakli(sehir)) {
                Sehir yeniSehir = sehir->bolun_Sehir(sehir);
                yeniSehirler[yeniSehirSayisi] = yeniSehir;
                yeniSehirSayisi++;
            }
        }

        // tur bittikten sonra bölünmeyle gelen şehirleri asıl listeye ekle
        if (yeniSehirSayisi > 0) {
            this->sehirler = (Sehir*)realloc(this->sehirler, sizeof(Sehir) * (this->sehirSayisi + yeniSehirSayisi));
            
            for (int i = 0; i < yeniSehirSayisi; i++) {
                this->sehirler[this->sehirSayisi + i] = yeniSehirler[i];
            }
            this->sehirSayisi += yeniSehirSayisi;
        }
        free(yeniSehirler);

        printf("%d.tur sonu:\n", tur);
        this->yazdirici->turYazdir(this->sehirler, this->sehirSayisi);
        this->yazdirici->ekraniTemizle();
			
		}

		printf("Oyun Sonu:\n");
		this->yazdirici->turYazdir(this->sehirler, this->sehirSayisi);

    	oyunSonuSatirSutunSor(this);
}


// TODO
void delete_Oyun(Oyun this){
	if(this->sayiDizi != NULL){
		free(this->sayiDizi);
	}
	if(this->sehirler != NULL){
		for(int i = 0; i < this->sehirSayisi; i++){
			this->sehirler[i]->delete_Sehir(this->sehirler[i]);
		}
		free(this->sehirler);
	}
	if(this->oyunBaslaticiServis != NULL){
		this->oyunBaslaticiServis->delete_OyunBaslaticiServis(this->oyunBaslaticiServis);
	}
	if(this->yazdirici != NULL){
		this->yazdirici->delete_YazdirServis(this->yazdirici);
	}
	free(this);
}
