#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "araclar/BaslangicGirdiIslemleri.h"



// private fonksiyonlar (header'da olmayanlar)

int *stringiSayiyaCevir(char *sayilarString, int uzunluk, int* sayiDiziUz)
{
	int* sayiDizi = (int*)malloc(sizeof(int) * uzunluk);
    
    if (sayiDizi == NULL) return NULL; // bellek hata verirse

    int i = 0;
    char* sayiSt = strtok(sayilarString, " ");
    
    while (sayiSt != NULL && i < uzunluk) {
        sayiDizi[i] = atoi(sayiSt); 
        sayiSt = strtok(NULL, " "); 
        i++;
    }
    *sayiDiziUz = i;

    return sayiDizi;
}

// public fonksiyonlar

//todo sayiDizinin uzunluğunu da döndürmeli

int* sayiDiziAl(int* sayiDiziUz){

    char sayilarString[100];
	int uzunluk = 100; // sayilarString'in maksimum uzunluğu
	printf("Sayi dizisini giriniz (xx xx xx formatinda): ");
	fgets(sayilarString, uzunluk, stdin);
	
	// fgetsten arta kalan sondaki '\n' karakterini kaldırmak için
	sayilarString[strcspn(sayilarString, "\n")] = '\0';

    int* sayiDizi = stringiSayiyaCevir(sayilarString, uzunluk, sayiDiziUz);
    return sayiDizi;
}

int turSayisiAl(){
    int turSayisi;
    printf("Tur sayisini giriniz: ");
    scanf("%d", &turSayisi);
    while(getchar() != '\n');

    return turSayisi;
}

BaslangicGirdiIslemleri new_BaslangicGirdiIslemleri(){
    BaslangicGirdiIslemleri this;
    this = (BaslangicGirdiIslemleri)malloc(sizeof(struct BASLANGIC_GIRDI_ISLEMLERI));
    this->turSayisiAl = &turSayisiAl;
    this->sayiDiziAl = &sayiDiziAl;
    this->delete_Bgi = &delete_Bgi;
    return this;
}

void delete_Bgi(BaslangicGirdiIslemleri this){
    if(this != NULL) free(this);
}

