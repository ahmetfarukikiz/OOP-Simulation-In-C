/**
*
* @author Ahmet Faruk İkiz faruk.ikiz@ogr.sakarya.edu.tr
* @since 26.04.2026
* <p>
* Yerlesim birimleriyle ilgili ortak bilgileri ve metotları tutan model sınıf.
* </p>
*/

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