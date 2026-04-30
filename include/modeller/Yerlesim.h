#ifndef YERLESIM_H
#define YERLESIM_H

struct YERLESIM {
	char *ad;
	int nufus;
	//abstract metotlar
	char* (*toString)(); 
	void (*ekranaYazdir)();
	void (*yaslandir)();
	// destructor
	void (*delete_Yerlesim)(struct YERLESIM*);
};
typedef struct YERLESIM* Yerlesim;

Yerlesim new_Yerlesim(char*, int);
void delete_Yerlesim(const Yerlesim);

#endif