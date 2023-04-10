#ifndef syaiful_h
#include <math.h>
#include <stdbool.h>
#define true 1
#define false 0

float Hitungpersen(float persen, float total){// mencari persentase
float hasil;
hasil = (persen/total)*100;

return hasil;
}

float Input_htgprsn(){
	float a,b;
	float hsl;
	printf("Berapa persen : ");
	scanf("%f", &a);
	printf("Dari jumlah total : ");
	scanf("%f", &b);
	hsl=Hitungpersen(a,b);
	printf("Adalah : %2.lf Persen\n\n", hsl); 

}

double Hitungdesimal(float pembilang, float penyebut){//mencari desimal
	double hsldsml;
	hsldsml=(double)pembilang/penyebut;
	
	return hsldsml;
}

float Input_desimal(){//desimal
	float a,b;
	float hdsml;
	printf("Masukkan pembilang : ");
	scanf("%f", &a);
	printf("Masukkan penyebut : ");
	scanf("%f", &b);
	hdsml=Hitungdesimal(a,b);
	printf("Hasil desimal :%.2f \n",hdsml);
}

//modul boolean
bool lebih_besar(double bil1,double bil2){
	return bil1>bil2;
}

bool lebih_kecil(double bil1,double bil2){
	return bil1<bil2;
}

bool sama(double bil1,double bil2){
	return bil1==bil2;
}

//modul perpangkatan
double exponent(double konst, double var){
	return pow(konst,var);	
}

//modul akar
double sqroot(double konst, double var){
	return pow(var, 1.0/konst);
}

//modul faktorial
int faktorial(int bil){
	int faktorial = 1, i;
	
	for (i = 1; i <= bil; i++) {
        faktorial = faktorial * i;
    }

    return faktorial;
}

#endif








