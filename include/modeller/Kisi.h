/**
*
* @author Ahmet Faruk İkiz faruk.ikiz@ogr.sakarya.edu.tr
* @since 26.04.2026
* <p>
* Kisiye ait verileri tutar ve bu verilere ait iç hesaplamaları yapar.
* </p>
*/

#ifndef KISI_H
#define KISI_H

struct KISI
{
	char *ad, *soyad;
	int id, yas;
	void (*yaslandir_Kisi)(struct KISI*);
	void (*ekranaYazdir_Kisi)( struct KISI*);
	char* (*toString_Kisi)(struct KISI*);
	void (*delete_Kisi)(struct KISI*);
};
typedef struct KISI* Kisi;

Kisi new_Kisi();
void yaslandir_Kisi(const Kisi);
void ekranaYazdir_Kisi(const Kisi);
char* toString_Kisi(const Kisi);
void delete_Kisi(const Kisi);


#endif