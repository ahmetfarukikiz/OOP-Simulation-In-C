#ifndef YERLESIM_H
#define YERLESIM_H

struct YERLESIM {
	char *ad;
	int nufus;
	
	void (*delete_Yerlesim)(struct YERLESIM*);
};
typedef struct YERLESIM* Yerlesim;

Yerlesim new_Yerlesim(char*, int);
char* toString_Yerlesim(Yerlesim);
void delete_Yerlesim(Yerlesim);

#endif