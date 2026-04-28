struct SAHTE_VERI_URETICI
{
	char* (*getKisiAd)();
	char* (*getKisiSoyad)();
	char* (*getSehirAd)();
	char* (*getIlceAd)();
	char* (*getMahalleAd)();	
	void (*delete_Svu)(struct SAHTE_VERI_URETICI*);
};

typedef struct SAHTE_VERI_URETICI* SahteVeriUretici;

SahteVeriUretici new_SahteVeriUretici();
char* getKisiAd();
char* getKisiSoyad();
char* getSehirAd();
char* getIlceAd();
char* getMahalleAd();	
void delete_Svu(const SahteVeriUretici this);