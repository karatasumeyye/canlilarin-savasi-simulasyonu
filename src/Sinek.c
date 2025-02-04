#include "Sinek.h"
#include "Bocek.h"
#include "Bitki.h"
#include <stdlib.h>

typedef void* Object;

Sinek new_Sinek(int x,int y){
	Sinek this = (Sinek)malloc(sizeof(struct SINEK));
	this->super= new_Bocek(x,y);
	this->yemek=&yemek_Sinek;
	this->delete_Sinek=&delete_Sinek;
	
	return this;
}

void yemek_Sinek(Object* kazananPtr,char** karakter_matris,int** matris,int i,int j,int sutun_sayisi,int satir_sayisi,CanliTuru* kazanan_turu,int *tipDegistiMiPtr){
	Sinek sinek = (Sinek)(*kazananPtr);
	int x=sinek->super->super->konum.x;   //Satır
	int y=sinek->super->super->konum.y;    //Sutun

	//sinek böcek yer
	if(karakter_matris[i][j]=='C'){
		karakter_matris[i][j]='X'; 
	}
	//sinek pire yer
	else if(karakter_matris[i][j]=='P') {
		karakter_matris[i][j]='X';  
	}
	//Bitki Sinek yer
	else if(karakter_matris[i][j]=='B'){
		*tipDegistiMiPtr = 1;
		karakter_matris[x][y]='X'; // Kazanan kaybetti ve yeni kazanan bitki
		sinek->delete_Sinek(sinek);
		*kazanan_turu=BITKI_TURU;
		*kazananPtr=(Object)new_Bitki(i,j);
	}  
	
	else if(karakter_matris[i][j]=='S'){
		if(matris[x][y]>matris[i][j]){
			karakter_matris[i][j]='X';
		}
		else if(matris[x][y] < matris[i][j]){
			karakter_matris[x][y]='X';  
			sinek->delete_Sinek(sinek);
			*kazanan_turu=SINEK_TURU;
			*kazananPtr=(Object)new_Sinek(i,j);
		}
		else if(matris[x][y]==matris[i][j]){
			//En son bakılan canlı bitişe yakın olandır
			karakter_matris[i][j]='X';
			
		}
	}  
}

// Önce canlı sonra böcek en son sinek yok edilir
void delete_Sinek(const Sinek this){
	if(this == NULL) return;
	this->super->delete_Bocek(this->super);
	free(this);
}