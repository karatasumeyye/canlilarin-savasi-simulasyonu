#include "Bitki.h"
#include <stdlib.h>
#include <string.h>

typedef void* Object;

Bitki new_Bitki(int x,int y){
	Bitki this = (Bitki)malloc(sizeof(struct BITKI));
	this->super= new_Canli(x,y);
	this->yemek=&yemek_Bitki;    // Canlıdaki soyut yemek sınıfına 
	this->delete_Bitki=&delete_Bitki;
	
	return this;
}


void yemek_Bitki(Object* kazananPtr,char **karakter_matris,int **matris,int i,int j,int sutun_sayisi,int satir_sayisi,CanliTuru* kazanan_turu,int* tipDegistiMiPtr){
	Bitki bitki = (Bitki)(*kazananPtr);
	int x=bitki->super->konum.x;   //Satır
	int y=bitki->super->konum.y;    //Sutun

	//Bitki pire yer
	if(karakter_matris[i][j]=='P'){
		karakter_matris[i][j]='X'; 
	}
	//Bitki sinek yer
	else if(karakter_matris[i][j]=='S') {
		karakter_matris[i][j]='X';  
	}
	//Böcek bitkiyi yer
	else if(karakter_matris[i][j]=='C'){
		*tipDegistiMiPtr=1;
		karakter_matris[x][y]='X'; // Kazanan kaybetti ve yeni kazanan böcek
		bitki->delete_Bitki(bitki);
		*kazanan_turu = BOCEK_TURU;
		*kazananPtr=(Object)new_Bocek(i,j);  //yeni kazanan  oluşturulur
		
	}  
	 //Aynı olma durumu
	else if(karakter_matris[i][j]=='B'){
		if(matris[x][y]>matris[i][j]){
			karakter_matris[i][j]='X';
		}
		else if(matris[x][y] < matris[i][j]){
			karakter_matris[x][y]='X';  
			bitki->delete_Bitki(bitki);
			*kazananPtr=(Object)new_Bitki(i,j);  //Konum bilgisi değişir ve yeni kazanan bikti güncellenir
		}
		else if(matris[x][y]==matris[i][j]){
			karakter_matris[i][j]='X';   //Bitişe yakın olan öldü, kazanan değişmez
		}
	}  
}

//Önce canlı sonra bitki yok edilir
void delete_Bitki(const Bitki this){
	if(this == NULL) return;
	this->super->delete_Canli(this->super);
	free(this);
}

