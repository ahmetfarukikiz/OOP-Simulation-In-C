/**
*
* @author Ahmet Faruk İkiz faruk.ikiz@ogr.sakarya.edu.tr
* @since 28.04.2026
* <p>
* SahteVeri klasöründeki txt dosyalarından verileri okur ve belleğe alır.
* </p>
*/

struct SAHTE_VERI_URETICI
{
	// Verileri ram'de tutacak diziler
    char** isimler;
    char** soyisimler;
    char** sehirler;
    char** ilceler;
    char** mahalleler;
    int veriSayisi;

	//public funclar
	char* (*getKisiAd)();
	char* (*getKisiSoyad)();
	char* (*getSehirAd)();
	int (*getKisiYas)();
	char* (*getIlceAd)();
	char* (*getMahalleAd)();	
	void (*delete_Svu)();
};

typedef struct SAHTE_VERI_URETICI* SahteVeriUretici;

//ilk kez kullanıldığında private kurucusunu çağırır ve 
// tek static instance'ı döndürür
SahteVeriUretici get_SvuInstance(); 

char* getKisiAd();
char* getKisiSoyad();
int getKisiYas();
char* getSehirAd();
char* getIlceAd();
char* getMahalleAd();
void delete_Svu();