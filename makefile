hepsi: derle calistir

derle:
	gcc -I ./include/ -o ./lib/BaslangicKuralHesaplayici.o -c ./src/araclar/BaslangicKuralHesaplayici.c
	gcc -I ./include/ -o ./lib/BaslangicGirdiIslemleri.o -c ./src/araclar/BaslangicGirdiIslemleri.c
	gcc -I ./include/ -o ./lib/Ilce.o -c ./src/modeller/Ilce.c
	gcc -I ./include/ -o ./lib/Kisi.o -c ./src/modeller/Kisi.c
	gcc -I ./include/ -o ./lib/Mahalle.o -c ./src/modeller/Mahalle.c
	gcc -I ./include/ -o ./lib/Sehir.o -c ./src/modeller/Sehir.c
	gcc -I ./include/ -o ./lib/Yerlesim.o -c ./src/modeller/Yerlesim.c
	gcc -I ./include/ -o ./lib/Oyun.o -c ./src/motor/Oyun.c
	gcc -I ./include/ -o ./lib/OyunBaslaticiServis.o -c ./src/servisler/OyunBaslaticiServis.c
	gcc -I ./include/ -o ./bin/program.exe ./lib/BaslangicKuralHesaplayici.o ./lib/BaslangicGirdiIslemleri.o ./lib/Ilce.o ./lib/Kisi.o ./lib/Mahalle.o ./lib/Sehir.o ./lib/Yerlesim.o ./lib/Oyun.o ./lib/OyunBaslaticiServis.o ./src/main/Main.c

calistir: ./bin/program.exe
	./bin/program.exe