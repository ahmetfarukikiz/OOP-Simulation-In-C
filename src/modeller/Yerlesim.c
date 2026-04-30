#include <stdlib.h>
#include <string.h>
#include "modeller/Yerlesim.h"

Yerlesim new_Yerlesim(char* ad, int nufus){
	Yerlesim this = (Yerlesim)malloc(sizeof(struct YERLESIM));
	this->ad = (char*)malloc((strlen(ad) + 1) * sizeof(char));
    strcpy(this->ad, ad);
	this->nufus = nufus;
	this->delete_Yerlesim = &delete_Yerlesim;
	return this;
}
void delete_Yerlesim(const Yerlesim this){
	if(this->ad != NULL) free(this->ad);
	if(this != NULL) free(this);
}