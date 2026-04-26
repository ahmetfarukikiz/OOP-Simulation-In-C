#include <stdio.h>
#include "motor/Oyun.h"

int main() {
	
	Oyun oyun = new_Oyun();
	oyun->baslat(oyun);
	oyun->delete_Oyun(oyun);
	return 0;
}