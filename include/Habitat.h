#ifndef HABITAT_H
#define HABITAT_H

#include "Bitki.h"
#include "Bocek.h"
#include "Sinek.h"
#include "Pire.h"




struct HABITAT{

void (*savasAlani)(struct HABITAT*,char**,int**,int,int);  
void (*delete_yokEtme)(struct HABITAT*);	
	
};
typedef struct HABITAT* Habitat;

Habitat new_Habitat();  //Kurucu Fonk
void savasAlani(Habitat,char**,int**,int,int); 
void delete_yokEtme(const Habitat);
















#endif
