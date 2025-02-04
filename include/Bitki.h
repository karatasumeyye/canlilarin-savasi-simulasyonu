#ifndef BITKI_H
#define BITKI_H

#include "Canli.h"
#include "Bocek.h"

struct BITKI{
	Canli super;
	void (*delete_Bitki)(struct BITKI*);
	void (*yemek)(Object*, char**, int**, int, int, int, int, CanliTuru*,int*);
	
	
};
typedef struct BITKI* Bitki;

Bitki new_Bitki(int x, int y);
void yemek_Bitki(Object*,char**,int**,int,int,int,int,CanliTuru*,int*);
void delete_Bitki(const Bitki);






#endif