struct SAHTE_VERI_URETICI
{
	// Verileri ram'de tutacak diziler
    char** isimler;
    char** soyisimler;
    char** sehirler;
    char** ilceler;
    char** mahalleler;
    int veriSayisi;

	char* (*getKisiAd)();
	char* (*getKisiSoyad)();
	char* (*getSehirAd)();
	int (*getKisiYas)();
	char* (*getIlceAd)();
	char* (*getMahalleAd)();	
	void (*delete_Svu)();
};

typedef struct SAHTE_VERI_URETICI* SahteVeriUretici;

//içerde kurucusunu çağırır ve tek static instance'ı döndürür
SahteVeriUretici get_SvuInstance(); 
char* getKisiAd();
char* getKisiSoyad();
int getKisiYas();
char* getSehirAd();
char* getIlceAd();
char* getMahalleAd();
void delete_Svu();