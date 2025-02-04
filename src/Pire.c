#include "Pire.h"
#include "Bitki.h"
#include "Bocek.h"
#include "Sinek.h"
#include <stdlib.h>

typedef void* Object;

Pire new_Pire(int x,int y){
	Pire this = (Pire)malloc(sizeof(struct PIRE));
	this->super= new_Bocek(x,y);
	this->yemek = &yemek_Pire;
	this->delete_Pire=&delete_Pire;
	
	return this;
}

void yemek_Pire(Object* kazananPtr,char **karakter_matris,int **matris,int i,int j,int sutun_sayisi,int satir_sayisi,CanliTuru* kazanan_turu,int *tipDegistiMiPtr){
	Pire pire = (Pire)(*kazananPtr);
	int x=pire->super->super->konum.x;   //Satır
	int y=pire->super->super->konum.y;    //Sutun

	//Bitki pireyi yer
	if(karakter_matris[i][j]=='B'){
		*tipDegistiMiPtr=1;
		karakter_matris[x][y]='X'; // Kazanan kaybetti ve yeni kazanan bitki
		pire->delete_Pire(pire);
		*kazanan_turu = BITKI_TURU;
		*kazananPtr=(Object)new_Bitki(i,j);
	}
	//Sinek pireyi yer
	else if(karakter_matris[i][j]=='S'){
		*tipDegistiMiPtr = 1;
		karakter_matris[x][y]='X'; // Kazanan kaybetti ve yeni kazanan sinek
		pire->delete_Pire(pire);
		*kazanan_turu=SINEK_TURU;
		*kazananPtr=(Object)new_Sinek(i,j); // Yeni kazanan oluşturulur
	}
	else if(karakter_matris[i][j]=='C'){
		*tipDegistiMiPtr=1;
		karakter_matris[x][y]='X'; // Kazanan kaybetti ve yeni kazanan böcek
		pire->delete_Pire(pire);
		*kazanan_turu = BOCEK_TURU;
		*kazananPtr=(Object)new_Bocek(i,j);
	}
	
	  
	else if(karakter_matris[i][j]=='P'){
		if(matris[x][y]>matris[i][j]){
			karakter_matris[i][j]='X';
		}
		else if(matris[x][y] < matris[i][j]){
			karakter_matris[x][y]='X';  
			pire->delete_Pire(pire);
			*kazanan_turu=PIRE_TURU;
			*kazananPtr=(Object)new_Pire(i,j);	
		}
		else if(matris[x][y]==matris[i][j]){
			karakter_matris[i][j]='X';
		}
	} 
}

// Önce canlı sonra böcek en son pire yok edilir
void delete_Pire(const Pire this){
	if(this == NULL) return;
	this->super->delete_Bocek(this->super);
	free(this);
}

