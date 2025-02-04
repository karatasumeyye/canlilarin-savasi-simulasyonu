#ifndef PIRE_H
#define PIRE_H

#include "Bocek.h"


struct PIRE{
	Bocek super;
	void (*delete_Pire)(struct PIRE*);
	void (*yemek)(Object*, char**, int**, int, int, int, int, CanliTuru*,int*);
};
typedef struct PIRE* Pire;

Pire new_Pire(int x,int y);
void delete_Pire(const Pire);
void yemek_Pire(Object*,char**,int**,int,int,int,int,CanliTuru*,int*);


#endif