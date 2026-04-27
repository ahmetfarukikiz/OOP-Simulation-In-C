#include <stdio.h>
#include <string.h>
#include "araclar/BaslangicGirdiIslemleri.h"
#include "motor/Oyun.h"

int main() {
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

	return 0;
}
