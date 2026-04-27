#ifndef BASLANGIC_GIRDI_ISLEMLERI_H
#define BASLANGIC_GIRDI_ISLEMLERI_H


//TODO NEW VE DELETE FONKSIYONLARI EKLE
struct BASLANGIC_GIRDI_ISLEMLERI
{
	int (*turSayisiAl)();
	int* (*sayiDiziAl)(int* sayiDiziUz);
	void (*delete_Bgi)(struct BASLANGIC_GIRDI_ISLEMLERI*);
};
typedef struct BASLANGIC_GIRDI_ISLEMLERI* BaslangicGirdiIslemleri;

BaslangicGirdiIslemleri new_BaslangicGirdiIslemleri();

//statik metot olduklarından this parametresi almıyorlar.
int turSayisiAl();
int* sayiDiziAl(int* sayiDiziUz);
void delete_Bgi(BaslangicGirdiIslemleri this);

#endif