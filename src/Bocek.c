#include "Bocek.h"
#include "Sinek.h"
#include <stdlib.h>
#include <stdio.h>


typedef void* Object;

Bocek new_Bocek(int x,int y){
	Bocek this = (Bocek)malloc(sizeof(struct BOCEK));
	this->super= new_Canli(x,y);
	this->super->yemek = &yemek_Bocek;
	this->yemek=&yemek_Bocek;
	this->delete_Bocek=&delete_Bocek;
	
	return this;
}

void yemek_Bocek(Object* kazananPtr,char **karakter_matris,int **matris,int i,int j,int sutun_sayisi,int satir_sayisi,CanliTuru* kazanan_turu, int* tipDegistiMiPtr){
	Bocek bocek = (Bocek)(*kazananPtr);
	int x=bocek->super->konum.x;   //Satır
	int y=bocek->super->konum.y;    //Sutun

	//Bitki yendiğinde
	if(karakter_matris[i][j]=='B'){
		karakter_matris[i][j]='X';
	}
	//Pire yendiğinde
	else if(karakter_matris[i][j]=='P') {
		karakter_matris[i][j]='X';  

	}
	//Sinek böcek yediğinde
	else if(karakter_matris[i][j]=='S'){
		*tipDegistiMiPtr = 1;
		karakter_matris[x][y]='X'; // Kazanan kaybetti ve yeni kazanan sinek
		bocek->delete_Bocek(bocek);
		*kazanan_turu=SINEK_TURU;
		*kazananPtr=(Object)new_Sinek(i,j); // Yeni kazanan sinek oluşturulur
	}
	
	else if(karakter_matris[i][j]=='C'){
		if(matris[x][y]>matris[i][j]){
			karakter_matris[i][j]='X';
		}
		else if(matris[x][y] < matris[i][j]){
			karakter_matris[x][y]='X';  
			bocek->delete_Bocek(bocek);
			*kazananPtr=(Object)new_Bocek(i,j); // Yeni kazanan bocek oluşturuldu
		}
		else if(matris[x][y]==matris[i][j]){
			//Bitiş noktasına yakınlık kontrolu
			karakter_matris[i][j]='X';
		}
	}  
}


void delete_Bocek(const Bocek this){
	if(this == NULL) return;
	this->super->delete_Canli(this->super);
	free(this);
}

