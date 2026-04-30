struct SAHTE_VERI_URETICI
{
	char* (*getKisiAd)();
	char* (*getKisiSoyad)();
	char* (*getSehirAd)();
	char* (*getKisiYas)();
	char* (*getIlceAd)();
	char* (*getMahalleAd)();	
	void (*delete_Svu)();
};

typedef struct SAHTE_VERI_URETICI* SahteVeriUretici;

//içerde kurucusunu çağırır ve tek static instance'ı döndürür
SahteVeriUretici get_SvuInstance(); 
char* getKisiAd();
char* getKisiSoyad();
char* getKisiYas();
char* getSehirAd();
char* getIlceAd();
char* getMahalleAd();
void delete_Svu();