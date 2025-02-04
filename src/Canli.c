#include <stdlib.h>
#include "Canli.h"


// Canlı oluşturulurken matristen konum bilgisi alınır ve oluşturulan canlının konumu biliniyor olur.
Canli new_Canli(int x,int y){
	Canli this= (Canli)malloc(sizeof(struct CANLI));
	this->konum.x=x;
	this->konum.y=y;
	this->gorunum=gorunum;
	this->delete_Canli=delete_Canli;
	
	return this;
}

// Parametre olarak alınan karakter matrisi yazdırılır. Satır ve sütun sayısı dosya okunurken belirlenir.
char* gorunum(const Object kazanan,char **karakter_matris,int satir_sayisi,int sutun_sayisi){
	
	for (int i = 0; i < satir_sayisi; i++) {
				for (int j = 0; j < sutun_sayisi; j++) {
					printf("%c ", karakter_matris[i][j]);
				}
				printf("\n");
				
	    	}
			system("cls");
			printf("\n");
	
	return "Canlinin gorunumu";
}

// Oluşturulan canlı serbest bırakılır.
void delete_Canli(const Canli this){
	if(this== NULL) return;
	free(this);
}