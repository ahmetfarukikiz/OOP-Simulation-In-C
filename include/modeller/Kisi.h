#ifndef KISI_H
#define KISI_H

struct KISI
{
	char *ad, *soyad;
	int id, yas;
	char* (*toString)(const struct KISI*); 
	void (*ekranaYazdir)(const struct KISI*);
	void (*yaslandir)(const struct KISI*);
	void (*toString_Kisi)(struct KISI*);
};
typedef struct KISI* Kisi;

Kisi new_Kisi();
void ekranaYazdir(const Kisi);
void yaslandir(const Kisi);
char* toString_Kisi(const Kisi);
void delete_Kisi(Kisi);


#endif