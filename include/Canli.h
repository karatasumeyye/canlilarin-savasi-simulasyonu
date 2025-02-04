#ifndef CANLI_H
#define CANLI_H

#include <stdio.h>


// CanliTuru enum yapısı, void* kullanıldığı için habitat.c de canlı türlerinin oluşturulmasında kullanılır.
typedef enum {
    BITKI_TURU,    
    BOCEK_TURU,
    SINEK_TURU,
    PIRE_TURU
} CanliTuru;


// Canlıların matristeki konumunu belirlemek için oluşturulmuştur.
typedef struct{
	int x;
	int y;
}Konum;


typedef void* Object;

struct CANLI{

Konum konum;  //Canlıların matristeki konumları 
char* (*gorunum)(const Object,char**,int, int);   // Karakter matrisini parametre olarak alır ve ekrana matrisi yazdırır.
void (*yemek)();   // abstract , her canlı türünün stratejisine göre değişiklik gösteren fonksiyon
void (*delete_Canli)(struct CANLI*);	
	
};
typedef struct CANLI* Canli;

Canli new_Canli(int x, int y);  //Kurucu Fonk
char* gorunum(const Object, char**,int,int);  //Bütün kalıtım alanlarda kullanılacak
void delete_Canli(const Canli);   



















#endif