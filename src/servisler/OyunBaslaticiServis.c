#include "servisler/OyunBaslaticiServis.h"
#include <stdlib.h>

OyunBaslaticiServis new_OyunBaslaticiServis(){
	OyunBaslaticiServis this; 
	this = (OyunBaslaticiServis)malloc(sizeof(struct OYUNBASLATICISERVIS));
	this->yerleskeOlustur = &yerleskeOlustur;
	this->delete_OyunBaslaticiServis = &delete_OyunBaslaticiServis;
	return this;
}

Sehir* yerleskeOlustur(const OyunBaslaticiServis this, int* sayiDizi){
	
	return NULL;
}

void delete_OyunBaslaticiServis(OyunBaslaticiServis this){
	if(this != NULL) free(this);
}
