#ifndef SINEK_H
#define SINEK_H

#include "Bocek.h"


struct SINEK{
	Bocek super;
	void (*delete_Sinek)(struct SINEK*);
	void (*yemek)(Object*, char**, int**, int, int, int, int, CanliTuru*,int*);
	
};
typedef struct SINEK* Sinek;

Sinek new_Sinek(int x,int y);
void delete_Sinek(const Sinek);
void yemek_Sinek(Object*,char**,int**,int,int,int,int,CanliTuru*,int*);


#endif