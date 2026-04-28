#include "araclar/SahteVeriUretici.h"

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


char* getKisiAd(){}
char* getKisiSoyad(){}
char* getSehirAd(){}
char* getIlceAd(){}
char* getMahalleAd(){}	

void delete_Svu(const SahteVeriUretici this){
	free(this);
}