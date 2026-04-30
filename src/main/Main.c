#include <stdio.h>
#include <string.h>
#include "araclar/BaslangicGirdiIslemleri.h"
#include "araclar/SahteVeriUretici.h"
#include "motor/Oyun.h"

int main() {
	// singleton yapı ile static sınıf benzetimi, program başında ilk kez oluşur sonra hep aynı örneği döndürür.
	SahteVeriUretici svu = get_SvuInstance(); 

	int turSayisi, sayiDiziUz, *sayiDizi;
   	sayiDiziUz = 0; turSayisi = 0;
	sayiDizi = NULL;	
	
	BaslangicGirdiIslemleri BGI_STATIC = new_BaslangicGirdiIslemleri();
	turSayisi = BGI_STATIC->turSayisiAl();
	//içerde sayiDiziUz'a da değer atayacak outer parametre
	sayiDizi = BGI_STATIC->sayiDiziAl(&sayiDiziUz); 
	BGI_STATIC->delete_Bgi(BGI_STATIC);

	Oyun oyun = new_Oyun(turSayisi, sayiDizi, sayiDiziUz);
	oyun->baslat(oyun);
	oyun->delete_Oyun(oyun);

	svu->delete_Svu(); //Bellekte 1 adet oluşturulan SahteVeriUretici örneğini temizler.
	return 0;
}
