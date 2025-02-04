#ifndef BOCEK_H
#define BOCEK_H

#include "Canli.h"

struct BOCEK{
	Canli super;
	void (*delete_Bocek)(struct BOCEK*);
	void (*yemek)(Object*, char**, int**, int, int, int, int, CanliTuru*,int*);
};
typedef struct BOCEK* Bocek;

Bocek new_Bocek(int x,int y);
void delete_Bocek(const Bocek);
void yemek_Bocek(Object*,char**,int**,int,int,int,int,CanliTuru*,int*);


#endif