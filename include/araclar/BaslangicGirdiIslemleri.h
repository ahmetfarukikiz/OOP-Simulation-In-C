/**
*
* @author Ahmet Faruk İkiz faruk.ikiz@ogr.sakarya.edu.tr
* @since 27.04.2026
* <p>
* Kullanıcıdan alınan string verisini OyunBaşlatıcıServis'in kullanabileceği int[] türüne dönüştürür.
* </p>
*/

#ifndef BASLANGIC_GIRDI_ISLEMLERI_H
#define BASLANGIC_GIRDI_ISLEMLERI_H


struct BASLANGIC_GIRDI_ISLEMLERI
{
	int (*turSayisiAl)();
	int* (*sayiDiziAl)(int*);
	void (*delete_Bgi)(struct BASLANGIC_GIRDI_ISLEMLERI*);
};
typedef struct BASLANGIC_GIRDI_ISLEMLERI* BaslangicGirdiIslemleri;

BaslangicGirdiIslemleri new_BaslangicGirdiIslemleri();

//statik metot olduklarından this parametresi almıyorlar.
int turSayisiAl();
int* sayiDiziAl(int*);
void delete_Bgi(BaslangicGirdiIslemleri);

#endif