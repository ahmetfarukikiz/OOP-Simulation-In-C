#ifndef BASLANGIC_KURAL_HESAPLAYICI_H
#define BASLANGIC_KURAL_HESAPLAYICI_H

struct BASLANGIC_KURAL_HESAPLAYICI
{
	int (*gercekSayiHesapla)(int);
	int (*gercekNufusHesapla)(int,int);
	void (*delete_Bkh)(struct BASLANGIC_KURAL_HESAPLAYICI*);
};
typedef struct BASLANGIC_KURAL_HESAPLAYICI* BaslangicKuralHesaplayici;

BaslangicKuralHesaplayici new_BaslangicKuralHesaplayici();
// Mahalleleri ilçelere eşit dağılabilir hale getirir
int gercekSayiHesapla(int);

// toplam nüfus sayıyı mahalle sayısına dağılabilir (bölünebilir hale getirir)
// örn: 18->24 24 % 4 == 0
int gercekNufusHesapla(int, int);
void delete_Bkh(BaslangicKuralHesaplayici);

#endif