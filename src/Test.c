#include <stdio.h>
#include <stdlib.h>

#include "Canli.h"
#include "Bitki.h"
#include "Bocek.h"
#include "Sinek.h"
#include "Pire.h"
#include "Habitat.h"

int main() {
    FILE *dosya;
    int satir_sayisi = 0;
    int sutun_sayisi = 0;
    int karakter,onceki_karakter;

    // Dosyayı aç
    dosya = fopen("Veri.txt", "r");

    // Dosyanın başarılı bir şekilde açılıp açılmadığını kontrol et
    if (dosya == NULL) {
        printf("Dosya açılamadı!\n");
        return 1; // Programı sonlandır
    }

    // İlk satırı okuyarak sutun sayısını bul
    while ((karakter = fgetc(dosya)) != '\n' && karakter != EOF) {
        if (karakter == ' ') {
            sutun_sayisi++;
        }
    }
     sutun_sayisi++; // Son sayıyı da sayıya ekle
  
    rewind(dosya);   //Dosyayı başa al

    onceki_karakter = '\n'; // İlk karakteri yeni satır karakteri olarak varsay

    // satır sayısını bul
    while ((karakter = fgetc(dosya)) != EOF) {
        if (karakter == '\n') {
            satir_sayisi++;
        }      
        onceki_karakter = karakter; // Karakteri sakla
    }

    if (onceki_karakter != '\n' && karakter == EOF) {
        satir_sayisi++; // Eğer son karakter yeni satır karakteri değilse ve EOF ise, satır sayısını bir artır
    }
    // Dosyayı başa al
    rewind(dosya);

    // Satır ve sütun sayısına göre matrisi oluştur
    int **matris = (int **)malloc(sizeof(int *) * satir_sayisi);
    for (int i = 0; i < satir_sayisi; i++) {
        matris[i] = (int *)malloc(sizeof(int) * sutun_sayisi);
    }

    // Dosyadan verileri matrise yerleştir
    for (int i = 0; i < satir_sayisi; i++) {
        for (int j = 0; j < sutun_sayisi; j++) {
            fscanf(dosya, "%d", &matris[i][j]);
        }
    }
	
    //Karakter matris oluştur
	char **karakter_matris = (char **)malloc(satir_sayisi * sizeof(char *));
	for (int i = 0; i < satir_sayisi; i++) {
		karakter_matris[i] = (char *)malloc(sutun_sayisi * sizeof(char));
		}
		
	// Matristeki sayıları belirli aralıklara göre karakterlere dönüştür
	for (int i = 0; i < satir_sayisi; i++) {
		for (int j = 0; j < sutun_sayisi; j++) {
			int sayi = matris[i][j];
			char karakter;
			if (1 <= sayi && sayi <= 9) {
				karakter = 'B'; // 1-9 arası sayılar için 'B' karakteri
			} else if (10 <= sayi && sayi <= 20) {
				karakter = 'C'; // 10-20 arası sayılar için 'C' karakteri
			} else if (21 <= sayi && sayi <= 50) {
				karakter = 'S'; // 21-50 arası sayılar için 'S' karakteri
			} else if (51 <= sayi && sayi <= 99) {
				karakter = 'P'; // 51-99 arası sayılar için 'P' karakteri
			} else if (sayi == 100) {
				karakter = 'X'; // 100 sayısı için 'X' karakteri
			} 
			karakter_matris[i][j] = karakter;
		}
	}
	
  
	// Habitat oluştur
     Habitat habitat = new_Habitat();

    // Habitat'ın savaş alanı
     savasAlani(habitat, karakter_matris,matris, satir_sayisi, sutun_sayisi);


        //Kazanan yazdırma
    	for (int i = 0; i < satir_sayisi; i++) {
            for (int j = 0; j < sutun_sayisi; j++) {
                if(karakter_matris[i][j]=='X'){
                    continue;
                }
                else {
                     printf("Kazanan: %c : (%d,%d)",karakter_matris[i][j],i,j);
                }
            }
	}

     // Habitat'ı yok et
     delete_yokEtme(habitat);

    // Belleği serbest bırak
    for (int i = 0; i < satir_sayisi; i++) {
        free(matris[i]);
    }
    free(matris);
	
	for (int i = 0; i < satir_sayisi; i++) {
        free(karakter_matris[i]);
    }
    free(karakter_matris);

    // Dosyayı kapat
    fclose(dosya);

    return 0;
}