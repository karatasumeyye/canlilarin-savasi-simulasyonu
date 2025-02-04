#include "Habitat.h"
#include <stdlib.h>

Habitat new_Habitat(){
	Habitat habitat= (Habitat)malloc(sizeof(struct HABITAT));
	habitat->savasAlani= &savasAlani;
	habitat->delete_yokEtme=&delete_yokEtme;
	
	return habitat;
}



Object kazanan;    // kazanan güncelleneceği için object(void*) tipinden oluşturulmuştur.
CanliTuru kazanan_turu;   // kazanan türüne göre nesnelerin fonksiyonları çağırılacaktır.

void savasAlani(Habitat habitat,char **karakter_matris,int **matris,int satir_sayisi,int sutun_sayisi){
	
	//Matrisin ilk elemanı kazanan canlı türü olarak atanır.
	
	if(karakter_matris[0][0]=='B'){
		kazanan = (Bitki)new_Bitki(0,0);
		kazanan_turu= BITKI_TURU;
	}else if(karakter_matris[0][0]=='C'){
		kazanan = (Bocek)new_Bocek(0,0);		
		kazanan_turu=BOCEK_TURU;
	}else if(karakter_matris[0][0]=='S'){
		kazanan = (Sinek)new_Sinek(0,0);
		kazanan_turu= SINEK_TURU;
	}else if(karakter_matris [0][0]=='P'){
		kazanan = (Pire)new_Pire(0,0);
		kazanan_turu=PIRE_TURU;
	}

	

	for (int i = 0; i < satir_sayisi; i++) {
				for (int j = 0; j < sutun_sayisi; j++) {
					printf("%c ", karakter_matris[i][j]);
				}
				printf("\n");
				
	}
	printf("\n");
	system("pause");   // Bir tuşa basıldığında programın çalışmasını sağlar

	
	int tipDegistiMi = 0;    // kazanan Object tipinde olduğu için ve  pointerların da kullanılması sonucu referans alınan değeri değiştirmek için oluşturuldu. canlı türü değiştiğinde kazananın türü güncellenir

	for(int i=0;i<satir_sayisi;i++){
		for(int j=0;j<sutun_sayisi;j++){
			if(i==0 && j ==0){
				continue;    // (0,0) elemanını kazanan olarak işlediğimiz için döngüde tekrar işleme girmez
			}

			//Kazananın türüne göre yemek fonksiyonu çağrılır.

			if(kazanan_turu==BITKI_TURU){
				Bitki bitkiKazanan=(Bitki)kazanan;
				bitkiKazanan->yemek(&kazanan,karakter_matris,matris,i,j,sutun_sayisi,satir_sayisi, &kazanan_turu,&tipDegistiMi);
				
				if (tipDegistiMi == 1) {   // Tip değiştiyse kazananın tipi de değişir.
					kazanan = (Bocek)kazanan;    
				}
			}else if(kazanan_turu==BOCEK_TURU){
				Bocek bocekKazanan=(Bocek)kazanan;
				bocekKazanan->yemek(&kazanan,karakter_matris,matris,i,j,sutun_sayisi,satir_sayisi, &kazanan_turu, &tipDegistiMi);
				if (tipDegistiMi == 1) {
					kazanan = (Sinek)kazanan;
				}
			}
			else if(kazanan_turu==SINEK_TURU){
				Sinek sinekKazanan=(Sinek)kazanan;
				sinekKazanan->yemek(&kazanan,karakter_matris,matris,i,j, sutun_sayisi, satir_sayisi, &kazanan_turu,&tipDegistiMi);
				if (tipDegistiMi == 1) {
					kazanan = (Bitki)kazanan;
				}

			 }else if(kazanan_turu==PIRE_TURU){
			 	Pire pireKazanan=(Pire)kazanan;
			 	pireKazanan->yemek(&kazanan,karakter_matris,matris,i,j,sutun_sayisi,satir_sayisi, &kazanan_turu,&tipDegistiMi);
				
			 }

			 gorunum(kazanan, karakter_matris, satir_sayisi, sutun_sayisi);    // Ekrana yazdırma
            
		 	 }
			
		printf("\n");
		
	}	
}

void delete_yokEtme(const Habitat habitat){
	if(habitat!=NULL){
		free(habitat);
	}
}