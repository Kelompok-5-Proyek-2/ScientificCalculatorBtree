#ifndef Konversi_Suhu_H
#define Konversi_Suhu_H
#include <stdio.h>
#include <stdlib.h>


/********************* SIN, COS, TAN *********************/

// konversi sudut dalam derajat ke radian
double to_radian(double derajat) {
    return derajat * (3.14159265359 / 180.0);
}

// menghitung nilai sinus
double sinus(double derajat) {
    double radian = to_radian(derajat);
    double result = radian;
    double term = radian;
    int i;

    for (i = 1; i <= 10; i++) {
        term = -term * radian * radian / ((2 * i) * (2 * i + 1));
        result += term;
    }

    return result;
}

// menghitung nilai kosinus
double cosinus(double derajat) {
    double radian = to_radian(derajat);
    double result = 1;
    double term = 1;
    int i;

    for (i = 1; i <= 10; i++) {
        term = -term * radian * radian / ((2 * i - 1) * (2 * i));
        result += term;
    }

    return result;
}

// menghitung nilai tangen
double tangen(double derajat) {
    return sinus(derajat) / cosinus(derajat);
}


void trigonometri (){
	int pilih;
	double derajat;
    system("cls");
    printf("\n\t1. Hitung Sin\n\t2. Hitung Cos\n\t3. Hitung Tan\n\t4. Menu utama");
    printf("\n\tMasukkan pilihan : ");
    scanf("%d", &pilih);
    switch(pilih){
    	case 1 :
    		system("cls");
    		printf("Masukan nilai Sin :");
    		scanf("%lf", &derajat);
    		printf("Sin %lf = %.2lf\n", derajat, sinus(derajat));
    		break;
    	case 2 :
    		system("cls");
    		printf("Masukan nilai Cos :");
    		scanf("%lf", &derajat);
    		printf("Cos %lf = %.2lf\n", derajat, cosinus(derajat));
    		break;
    	case 3 :
    		system("cls");
    		printf("Masukan nilai Tan :");
    		scanf("%lf", &derajat);
    		printf("Tan %lf = %.2lf\n", derajat, tangen(derajat));
    		break;
    	case 4 :
    		//CalArit();
    		break;
		default :
			exit(1);
		
		
	}
	system("pause");
}


/********************* NILAI MUTLAK *********************/

double nilai_mutlak(double bilangan){
	if (bilangan < 0){
		return -bilangan;
	}
	else 
		return bilangan;
}

void input_mutlak(){
	system ("cls");
	double bilangan, hasil;
	printf("Masukan bilangan : ");
	scanf("%lf", &bilangan);
	hasil = nilai_mutlak(bilangan);
	printf("Nilai mutlak dari %.2lf = %.2lf\n", bilangan, hasil);
	system("pause");
} 

/********************* LOGARITMA *********************/

//double logaritma(double bilangan) {
//    double hasil = 0.0;
//    double akhir = 0.000001;
//    double eksponen = (bilangan - 1) / bilangan;
//    double pangkat = eksponen;
//    double i = 1;
//
//    while (pangkat > akhir) {
//        hasil = hasil + pangkat / i;
//        pangkat = pangkat * eksponen;
//        i++;
//    }
//     return hasil / 2.302585;
//}

double logbase(double a, double base){
	return log(a) / log(base);
}

//void input_logaritma(){
//	system("cls");
//	double bilangan, hasil;
//    printf("Masukkan bilangan : ");
//    scanf("%lf", &bilangan);
//    hasil = logaritma(bilangan);
//	printf("Logaritma dari %.2lf = %.2lf\n", bilangan, hasil);
//	system ("pause");
//}


/********************* KONVERSI SUHU *********************/

//CELCIUS KE FAHRENHEIT
float konversi_celciusfahrenheit (float celcius){
	return (celcius * 1.8) + 32;
}
//CELCIUS KE KELVIN
float konversi_celciuskelvin (float celcius){
	return celcius * 273.15;
}
//CELCIUS KE REAMUR
float konversi_celciusreamur (float celcius){
	return 0.8 * celcius;
}
//KELVIN KE CELCIUS
float konversi_kelvincelcius (float kelvin){
	return kelvin - 273.15;
}
//KELVIN KE FAHRENHEIT
float konversi_kelvinfahrenheit (float kelvin){
	return (kelvin * 1.8) - 459.67;
}
//KELVIN KE REAMUR
float konversi_kelvinreamur (float kelvin){
	return (kelvin - 273.15) * 0.8;
}
//FAHRENHEIT KE CELCIUS
float konversi_fahrenheitcelcius (float fahrenheit){
	return (fahrenheit - 32) / 1.8;
}
//FAHRENHEIT KE KELVIN
float konversi_fahrenheitkelvin (float fahrenheit){
	return (fahrenheit + 459.67) / 1.8;
}
//FAHRENHEIT KE REAMUR
float konversi_fahrenheitreamur (float fahrenheit){
	return (fahrenheit - 32) * 0.5556;
}
//REAMUR KE CELCIUS
float konversi_reamurcelcius (float reamur){
	return 0.8 * reamur;
}
//REAMUR KE KELVIN
float konversi_reamurkelvin (float reamur){
	return 0.8 * (reamur + 273.15);
}
//REAMUR KE FAHRENHEIT
float konversi_reamurfahrenheit (float reamur){
	return 2.25 * reamur + 32;
}

/************ KONVERSI JARAK ************/

//Konversi km ke hm
float km_hm (float x){
	return x*10;
}
//Konversi km ke dam
float km_dam (float x){
	return x*100;
}
//Konversi km ke m
float km_m (float x){
	return x*1000;
}
//Konversi km ke dm
float km_dm (float x){
	return x*10000;
}
//Konversi km ke cm
float km_cm (float x){
	return x*100000;
}
//Konversi km ke mm
float km_mm (float x){
	return x*1000000;
}
//Konversi hm ke km
float hm_km (float x){
	return x/10;
}
//Konversi hm ke dam
float hm_dam (float x){
	return x*10;
}
//Konversi hm ke m
float hm_m (float x){
	return x*100;
}
//Konversi hm ke dm
float hm_dm (float x){
	return x*1000;
}
//Konversi hm ke cm
float hm_cm (float x){
	return x*10000;
}
//Konversi hm ke mm
float hm_mm (float x){
	return x*100000;
}
//Konversi dam ke km
float dam_km (float x){
	return x/100;
}
//Konversi dam ke hm
float dam_hm (float x){
	return x/10;
}
//Konversi dam ke m
float dam_m (float x){
	return x*10;
}
//Konversi dam ke dm
float dam_dm (float x){
	return x*100;
}
//Konversi dam ke cm
float dam_cm (float x){
	return x*1000;
}
//Konversi dam ke mm
float dam_mm (float x){
	return x*10000;
}
//Konversi m ke km
float m_km (float x){
	return x/1000;
}
//Konversi m ke hm
float m_hm (float x){
	return x/100;
}
//Konversi m ke dam
float m_dam (float x){
	return x/10;
}
//Konversi m ke dm
float m_dm (float x){
	return x*10;
}
//Konversi m ke cm
float m_cm (float x){
	return x*100;
}
//Konversi m ke mm
float m_mm (float x){
	return x*1000;
}
//Konversi dm ke km
float dm_km (float x){
	return x/10000;
}
//Konversi dm ke hm
float dm_hm (float x){
	return x/1000;
}
//Konversi dm ke dam
float dm_dam (float x){
	return x/100;
}
//Konversi dm ke m
float dm_m (float x){
	return x/10;
}
//Konversi dm ke cm
float dm_cm (float x){
	return x*10;
}
//Konversi dm ke mm
float dm_mm (float x){
	return x*100;
}
//Konversi cm ke km
float cm_km (float x){
	return x/100000;
}
//Konversi cm ke hm
float cm_hm (float x){
	return x/10000;
}
//Konversi cm ke dam
float cm_dam (float x){
	return x/1000;
}
//Konversi cm ke m
float cm_m (float x){
	return x/100;
}
//Konversi cm ke dm
float cm_dm (float x){
	return x/10;
}
//Konversi cm ke mm
float cm_mm (float x){
	return x*10;
}
//Konversi mm ke km
float mm_km (float x){
	return x/1000000;
}
//Konversi mm ke hm
float mm_hm (float x){
	return x/100000;
}
//Konversi mm ke dam
float mm_dam (float x){
	return x/10000;
}
//Konversi mm ke m
float mm_m (float x){
	return x/1000;
}
//Konversi mm ke dm
float mm_dm (float x){
	return x/100;
}
//Konversi mm ke cm
float mm_cm (float x){
	return x/10;
}

/************ KONVERSI JARAK ************/

//Konversi km ke hg 
float kg_hg (float x){
	return x*10;
}
//Konversi kg ke dag
float kg_dag (float x){
	return x*100;
}
//Konversi kg ke g
float kg_g (float x){
	return x*1000;
}
//Konversi kg ke dg
float kg_dg (float x){
	return x*10000;
}
//Konversi kg ke cg
float kg_cg (float x){
	return x*100000;
}
//Konversi kg ke mg
float kg_mg (float x){
	return x*1000000;
}
//Konversi hg ke kg
float hg_kg (float x){
	return x/10;
}
//Konversi hg ke dag
float hg_dag (float x){
	return x*10;
}
//Konversi hg ke g
float hg_g (float x){
	return x*100;
}
//Konversi hg ke dg
float hg_dg (float x){
	return x*1000;
}
//Konversi hg ke cg
float hg_cg (float x){
	return x*10000;
}
//Konversi hg ke mg
float hg_mg (float x){
	return x*100000;
}
//Konversi dag ke kg
float dag_kg (float x){
	return x/100;
}
//Konversi dag ke hg
float dag_hg (float x){
	return x/10;
}
//Konversi dag ke g
float dag_g (float x){
	return x*10;
}
//Konversi dag ke dg
float dag_dg (float x){
	return x*100;
}
//Konversi dag ke cg
float dag_cg (float x){
	return x*1000;
}
//Konversi dag ke mg
float dag_mg (float x){
	return x*10000;
}
//Konversi g ke kg
float g_kg (float x){
	return x/1000;
}
//Konversi g ke hg
float g_hg (float x){
	return x/100;
}
//Konversi g ke dag
float g_dag (float x){
	return x/10;
}
//Konversi g ke dg
float g_dg (float x){
	return x*10;
}
//Konversi g ke cg
float g_cg (float x){
	return x*100;
}
//Konversi g ke mg
float g_mg (float x){
	return x*1000;
}
//Konversi dg ke kg
float dg_kg (float x){
	return x/10000;
}
//Konversi dg ke hg
float dg_hg (float x){
	return x/1000;
}
//Konversi dg ke dag
float dg_dag (float x){
	return x/100;
}
//Konversi dg ke g
float dg_g (float x){
	return x/10;
}
//Konversi dg ke cg
float dg_cg (float x){
	return x*10;
}
//Konversi dg ke mg
float dg_mg (float x){
	return x*100;
}
//Konversi cg ke kg
float cg_kg (float x){
	return x/100000;
}
//Konversi cg ke hg
float cg_hg (float x){
	return x/10000;
}
//Konversi cg ke dag
float cg_dag (float x){
	return x/1000;
}
//Konversi cg ke g
float cg_g (float x){
	return x/100;
}
//Konversi cg ke dg
float cg_dg (float x){
	return x/10;
}
//Konversi cg ke mg
float cg_mg (float x){
	return x*10;
}
//Konversi mg ke kg
float mg_kg (float x){
	return x/1000000;
}
//Konversi mg ke hg
float mg_hg (float x){
	return x/100000;
}
//Konversi mg ke dag
float mg_dag (float x){
	return x/10000;
}
//Konversi mg ke g
float mg_g (float x){
	return x/1000;
}
//Konversi mg ke dg
float mg_dg (float x){
	return x/100;
}
//Konversi mg ke cg
float mg_cg (float x){
	return x/10;
}


/********************** A L G O R I T M A **********************/

void input_suhu(){
	float celcius, kelvin, fahrenheit, reamur;
	int pilih;
	system("cls");
	printf("\n\t1. Celcius\n\t2. Fahrenheit\n\t3. Kelvin\n\t4. Reamur\n");
	printf("\tSatuan suhu awal : ");
	scanf("%s",&pilih);
	printf("\tKonversi suhu ke : ");
	scanf("%s",&pilih);
	printf("Masukan suhu  :");
	scanf("%f", &celcius);
	if (pilih==1 && pilih==2){ //mengubah celcius ke fahrenheit
		printf("Masukan suhu celcius :");
		scanf("%f", &celcius);
		fahrenheit = konversi_celciusfahrenheit(celcius);
		printf ("%.2f celcius = %.2f fahrenheit\n", celcius, fahrenheit);
	} else if (pilih==1 && pilih==3){ //mengubah celcius ke kelvin
		printf("Masukan suhu celcius :");
		scanf("%f", &celcius);
		kelvin = konversi_celciuskelvin(celcius);
		printf ("%.2f celcius = %.2f kelvin\n", celcius, kelvin);
	} else if (pilih==1 && pilih==4){ //mengubah celcius ke reamur
		printf("Masukan suhu celcius :");
		scanf("%f", &celcius);
		reamur = konversi_celciusreamur(celcius);
		printf ("%.2f celcius = %.2f reamur\n", celcius, reamur);
	} else if (pilih==2 && pilih==1){ //mengubah fahrenheit ke celcius
		printf("Masukan suhu Fahrenheit :"); 
	 	scanf("%f", &fahrenheit);
		celcius = konversi_fahrenheitcelcius(fahrenheit);
		printf ("%.2f fahrenheit = %.2f celcius\n", fahrenheit, celcius);
	} else if (pilih==2 && pilih==3){ //mengubah fahrenheit ke kelvin
		printf("Masukan suhu Fahrenheit :"); 
		scanf("%f", &fahrenheit);	
		kelvin = konversi_fahrenheitkelvin(fahrenheit);
		printf ("%.2f fahrenheit = %.2f kelvin\n", fahrenheit, kelvin);
	} else if (pilih==2 && pilih==4){ //mengubah fahrenheit ke reamur
		printf("Masukan suhu Fahrenheit :"); 
		scanf("%f", &fahrenheit);
		reamur = konversi_fahrenheitreamur(fahrenheit);
		printf ("%.2f fahrenheit = %.2f reamur\n", fahrenheit, reamur);
	} else if (pilih==3 && pilih==1){ //mengubah kelvin ke celcius
		printf("Masukan suhu Kelvin :"); 
		scanf("%f", &kelvin);
		celcius = konversi_kelvincelcius(kelvin);
		printf ("%.2f kelvin = %.2f celcius\n", kelvin, celcius);
	} else if (pilih==3 && pilih==2){ //mengubah kelvin ke fahrenheit
		printf("Masukan suhu Kelvin :"); 
		scanf("%f", &kelvin);
		fahrenheit = konversi_kelvinfahrenheit(kelvin);
		printf ("%.2f kelvin = %.2f fahrenheit\n", kelvin, fahrenheit);
	} else if (pilih==3 && pilih==4){ //mengubah kelvin ke reamur
		printf("Masukan suhu Kelvin :"); 
		scanf("%f", &kelvin);
		reamur = konversi_kelvinreamur(kelvin);
		printf("%.2f kelvin = %.2f reamur\n", kelvin, reamur);
	} else if (pilih==4 && pilih==1){ //mengubah reamur ke celcius
		printf("Masukan suhu reamur :"); 
		scanf("%f", &reamur);
		celcius = konversi_reamurcelcius(reamur);
		printf ("%.2f reamur = %.2f celcius\n", reamur, celcius);
	} else if (pilih==4 && pilih==2){ //mengubah reamur ke fahrenheit
		printf("Masukan suhu reamur :"); 
		scanf("%f", &reamur);
		fahrenheit = konversi_reamurfahrenheit(reamur);
		printf ("%.2f reamur = %.2f fahrenheit\n", reamur, fahrenheit);
	} else if (pilih==4 && pilih==3){ //mengubah reamur ke kelvin
		printf("Masukan suhu reamur :"); 
		scanf("%f", &reamur);
		kelvin = konversi_reamurkelvin(reamur);
		printf ("%.2f reamur = %.2f reamur\n", reamur, kelvin);
	} else {
		printf("Angka yang anda masukan salah\n");
	}
	system("pause");
}

void input_jarak(){
	float km, hm, dam, m, dm, cm, mm, x;
	int awal, akhir;
	system("cls");
	printf("\n\t1. km\n\t2. hm\n\t3. dam\n\t4. m\n\t5. dm\n\t6. cm\n\t7. mm\n");
	printf("\tMasukan satuan jarak awal : ");
	scanf("%d",&awal); 
	printf("\tKonversi jarak ke satuan : ");
	scanf("%d",&akhir);
	printf("Masukan jarak :");
	scanf("%f", &x); 
	//system("cls"); 
	if (awal==1 && akhir==2){ //mengubah satuan jarak km ke hm
		hm = km_hm (x);
		printf("\nHasil Konversi : \nJarak %.2f km = %.2f hm\n", x,hm);
	} else if (awal==1 && akhir==3){ //mengubah satuan jarak km ke dam
		dam = km_dam (x);
		printf("\nHasil Konversi : \nJarak %.2f km = %.2f dam\n", x,dam);
	} else if (awal==1 && akhir==4){ //mengubah satuan jarak km ke m
		m = km_m (x);
		printf("\nHasil Konversi : \nJarak %.2f km = %.2f m\n", x,m);
	} else if (awal==1 && akhir==5){ //mengubah satuan jarak km ke dm
		dm = km_dm (x);
		printf("\nHasil Konversi : \nJarak %.2f km = %.2f dm\n", x,dm);
	} else if (awal==1 && akhir==6){ //mengubah satuan jarak km ke cm
		cm = km_cm (x);
		printf("\nHasil Konversi : \nJarak %.2f km = %.2f cm\n", x,cm);
	} else if (awal==1 && akhir==7){ //mengubah satuan jarak km ke mm
		mm = km_mm (x);
		printf("\nHasil Konversi : \nJarak %.2f km = %.2f mm\n", x,mm);
	} else if (awal==2 && akhir==1){ //mengubah satuan jarak hm ke km
		km = hm_km (x);
		printf("\nHasil Konversi : \nJarak %.2f hm = %.2f km\n", x,km);
	} else if (awal==2 && akhir==2){ //mengubah satuan jarak hm ke dam
		dam = hm_dam (x);
		printf("\nHasil Konversi : \nJarak %.2f hm = %.2f dam\n", x,dam);
	} else if (awal==2 && akhir==3){ //mengubah satuan jarak hm ke m
		m = hm_m (x);
		printf("\nHasil Konversi : \nJarak %.2f hm = %.2f m\n", x,m);
	} else if (awal==2 && akhir==4){ //mengubah satuan jarak hm ke dm
		dm = hm_dm (x);
		printf("\nHasil Konversi : \nJarak %.2f hm = %.2f dm\n", x,dm);
	} else if (awal==2 && akhir==5){ //mengubah satuan jarak hm ke cm
		cm = hm_cm (x);
		printf("\nHasil Konversi : \nJarak %.2f hm = %.2f cm\n", x,cm);
	} else if (awal==2 && akhir==6){ //mengubah satuan jarak hm ke cm
		cm = hm_cm (x);
		printf("\nHasil Konversi : \nJarak %.2f hm = %.2f cm\n", x,cm);
	} else if (awal==2 && akhir==7){ //mengubah satuan jarak hm ke mm
		mm = hm_mm (x);
		printf("\nHasil Konversi : \nJarak %.2f hm = %.2f mm\n", x,mm);
	} else if (awal==3 && akhir==1){ //mengubah satuan jarak dam ke km
		km = dam_km (x);
		printf("\nHasil Konversi : \nJarak %.2f dam = %.2f km\n", x,km);
	} else if (awal==3 && akhir==2){ //mengubah satuan jarak dam ke hm
		hm = dam_hm (x);
		printf("\nHasil Konversi : \nJarak %.2f dam = %.2f hm\n", x,hm);
	} else if (awal==3 && akhir==4){ //mengubah satuan jarak dam ke m
		m = dam_m (x);
		printf("\nHasil Konversi : \nJarak %.2f dam = %.2f m\n", x,m);
	} else if (awal==3 && akhir==5){ //mengubah satuan jarak dam ke dm
		dm = dam_dm (x);
		printf("\nHasil Konversi : \nJarak %.2f dam = %.2f dm\n", x,dm);
	} else if (awal==3 && akhir==6){ //mengubah satuan jarak dam ke cm
		cm = dam_cm (x);
		printf("\nHasil Konversi : \nJarak %.2f dam = %.2f cm\n", x,cm);
	} else if (awal==3 && akhir==7){ //mengubah satuan jarak dam ke mm
		mm = dam_mm (x);
		printf("\nHasil Konversi : \nJarak %.2f dam = %.2f mm\n", x,mm);
	} else if (awal==4 && akhir==1){ //mengubah satuan jarak m ke km
		km = m_km (x);
		printf("\nHasil Konversi : \nJarak %.2f m = %.2f km\n", x,km);
	} else if (awal==4 && akhir==2){ //mengubah satuan jarak m ke hm
		hm = m_hm (x);
		printf("\nHasil Konversi : \nJarak %.2f m = %.2f hm\n", x,hm);
	} else if (awal==4 && akhir==3){ //mengubah satuan jarak m ke dam
		dam = m_dam (x);
		printf("\nHasil Konversi : \nJarak %.2f m = %.2f dam\n", x,dam);
	} else if (awal==4 && akhir==5){ //mengubah satuan jarak m ke dm
		dm = m_dm (x);
		printf("\nHasil Konversi : \nJarak %.2f m = %.2f dm\n", x,dm);
	} else if (awal==4 && akhir==6){ //mengubah satuan jarak m ke cm
		cm = m_cm (x);
		printf("\nHasil Konversi : \nJarak %.2f m = %.2f cm\n", x,cm);
	} else if (awal==4 && akhir==7){ //mengubah satuan jarak m ke mm
		mm = m_mm (x);
		printf("\nHasil Konversi : \nJarak %.2f m = %.2f mm\n", x,mm);
	} else if (awal==5 && akhir==1){ //mengubah satuan jarak dm ke km
		km = dm_km (x);
		printf("\nHasil Konversi : \nJarak %.2f dm = %.2f km\n", x,km);
	} else if (awal==5 && akhir==2){ //mengubah satuan jarak dm ke hm
		hm = dm_hm (x);
		printf("\nHasil Konversi : \nJarak %.2f dm = %.2f hm\n", x,hm);
	} else if (awal==5 && akhir==3){ //mengubah satuan jarak dm ke dam
		dam = dm_dam (x);
		printf("\nHasil Konversi : \nJarak %.2f dm = %.2f dam\n", x,dam);
	} else if (awal==5 && akhir==4){ //mengubah satuan jarak dm ke m
		m = dm_m (x);
		printf("\nHasil Konversi : \nJarak %.2f dm = %.2f m\n", x,m);
	} else if (awal==5 && akhir==6){ //mengubah satuan jarak dm ke cm
		cm = dm_cm (x);
		printf("\nHasil Konversi : \nJarak %.2f dm = %.2f cm\n", x,cm);
	} else if (awal==5 && akhir==7){ //mengubah satuan jarak dm ke mm
		mm = dm_mm (x);
		printf("\nHasil Konversi : \nJarak %.2f dm = %.2f mm\n", x,mm);
	} else if (awal==6 && akhir==1){ //mengubah satuan jarak cm ke km
		km = cm_km (x);
		printf("\nHasil Konversi : \nJarak %.2f cm = %.2f km\n", x,km);
	} else if (awal==6 && akhir==2){ //mengubah satuan jarak cm ke hm
		hm = cm_hm (x);
		printf("\nHasil Konversi : \nJarak %.2f cm = %.2f hm\n", x,hm);
	} else if (awal==6 && akhir==3){ //mengubah satuan jarak cm ke dam
		dam = cm_km (x);
		printf("\nHasil Konversi : \nJarak %.2f cm = %.2f dam\n", x,dam);
	} else if (awal==6 && akhir==4){ //mengubah satuan jarak cm ke m
		m = cm_m (x);
		printf("\nHasil Konversi : \nJarak %.2f cm = %.2f m\n", x,m);
	} else if (awal==6 && akhir==5){ //mengubah satuan jarak cm ke dm
		dm = cm_dm (x);
		printf("\nHasil Konversi : \nJarak %.2f cm = %.2f dm\n", x,dm);
	} else if (awal==6 && akhir==7){ //mengubah satuan jarak cm ke mm
		mm = cm_mm (x);
		printf("\nHasil Konversi : \nJarak %.2f cm = %.2f mm\n", x,mm);
	} else if (awal==7 && akhir==1){ //mengubah satuan jarak mm ke km
		km = mm_km (x);
		printf("\nHasil Konversi : \nJarak %.2f mm = %.2f km\n", x,km);
	} else if (awal==7 && akhir==2){ //mengubah satuan jarak mm ke hm
		hm = mm_hm (x);
		printf("\nHasil Konversi : \nJarak %.2f mm = %.2f hm\n", x,hm);
	} else if (awal==7 && akhir==3){ //mengubah satuan jarak mm ke dam
		dam = mm_dam (x);
		printf("\nHasil Konversi : \nJarak %.2f mm = %.2f dam\n", x,dam);
	} else if (awal==7 && akhir==4){ //mengubah satuan jarak mm ke m
		m = mm_m (x);
		printf("\nHasil Konversi : \nJarak %.2f mm = %.2f m\n", x,m);
	} else if (awal==7 && akhir==5){ //mengubah satuan jarak mm ke dm
		dm = mm_dm (x);
		printf("\nHasil Konversi : \nJarak %.2f mm = %.2f dm\n", x,dm);
	} else if (awal==7 && akhir==6){ //mengubah satuan jarak mm ke cm
		cm = mm_cm (x);
		printf("\nHasil Konversi : \nJarak %.2f mm = %.2f cm\n", x,cm);
	}
	system ("pause");
}

/* KONVERSI MASSA */

void input_massa(){
	float kg, hg, dag, g, dg, cg, mg, x;
	int awal, akhir;
	system("cls");
	printf("\n\t1. kg\n\t2. hg\n\t3. dag\n\t4. g\n\t5. dg\n\t6. cg\n\t7. mg\n");
	printf("\tMasukan satuan jarak awal : ");
	scanf("%d",&awal);
	printf("\tKonversi jarak ke satuan : ");
	scanf("%d",&akhir);
	printf("Masukan jarak :");
	scanf("%f", &x); 
//	system("cls"); 
	if (awal==1 && akhir==2){ //mengubah satuan jarak kg ke hg
		hg = kg_hg (x);
		printf("\nHasil Konversi : \nJarak %.2f kg = %.2f hg\n", x,hg);
	} else if (awal==1 && akhir==3){ //mengubah satuan jarak kg ke dag
		dag = kg_dag (x);
		printf("\nHasil Konversi : \nJarak %.2f kg = %.2f dag\n", x,dag);
	} else if (awal==1 && akhir==4){ //mengubah satuan jarak kg ke g
		g = kg_g (x);
		printf("\nHasil Konversi : \nJarak %.2f kg = %.2f g\n", x,g);
	} else if (awal==1 && akhir==5){ //mengubah satuan jarak kg ke dg
		dg = kg_dg (x);
		printf("\nHasil Konversi : \nJarak %.2f kg = %.2f dg\n", x,dg);
	} else if (awal==1 && akhir==6){ //mengubah satuan jarak kg ke cg
		cg = kg_cg (x);
		printf("\nHasil Konversi : \nJarak %.2f kg = %.2f cg\n", x,cg);
	} else if (awal==1 && akhir==7){ //mengubah satuan jarak kg ke mg
		mg = kg_mg (x);
		printf("\nHasil Konversi : \nJarak %.2f kg = %.2f mg\n", x,mg);
	} else if (awal==2 && akhir==1){ //mengubah satuan jarak hg ke kg
		kg = hg_kg (x);
		printf("\nHasil Konversi : \nJarak %.2f hg = %.2f kg\n", x,kg);
	} else if (awal==2 && akhir==2){ //mengubah satuan jarak hg ke dag
		dag = hg_dag (x);
		printf("\nHasil Konversi : \nJarak %.2f hg = %.2f dag\n", x,dag);
	} else if (awal==2 && akhir==3){ //mengubah satuan jarak hg ke g
		g = hg_g (x);
		printf("\nHasil Konversi : \nJarak %.2f hg = %.2f g\n", x,g);
	} else if (awal==2 && akhir==4){ //mengubah satuan jarak hg ke dg
		dg = hg_dg (x);
		printf("\nHasil Konversi : \nJarak %.2f hg = %.2f dg\n", x,dg);
	} else if (awal==2 && akhir==5){ //mengubah satuan jarak hg ke cg
		cg = hg_cg (x);
		printf("\nHasil Konversi : \nJarak %.2f hg = %.2f cg\n", x,cg);
	} else if (awal==2 && akhir==6){ //mengubah satuan jarak hg ke cg
		cg = hg_cg (x);
		printf("\nHasil Konversi : \nJarak %.2f hg = %.2f cg\n", x,cg);
	} else if (awal==2 && akhir==7){ //mengubah satuan jarak hg ke mg
		mg = hg_mg (x);
		printf("\nHasil Konversi : \nJarak %.2f hg = %.2f mg\n", x,mg);
	} else if (awal==3 && akhir==1){ //mengubah satuan jarak dag ke kg
		kg = dag_kg (x);
		printf("\nHasil Konversi : \nJarak %.2f dag = %.2f kg\n", x,kg);
	} else if (awal==3 && akhir==2){ //mengubah satuan jarak dag ke hg
		hg = dag_hg (x);
		printf("\nHasil Konversi : \nJarak %.2f dag = %.2f hg\n", x,hg);
	} else if (awal==3 && akhir==4){ //mengubah satuan jarak dag ke g
		g = dag_g (x);
		printf("\nHasil Konversi : \nJarak %.2f dag = %.2f g\n", x,g);
	} else if (awal==3 && akhir==5){ //mengubah satuan jarak dag ke dg
		dg = dag_dg (x);
		printf("\nHasil Konversi : \nJarak %.2f dag = %.2f dg\n", x,dg);
	} else if (awal==3 && akhir==6){ //mengubah satuan jarak dag ke cg
		cg = dag_cg (x);
		printf("\nHasil Konversi : \nJarak %.2f dag = %.2f cg\n", x,cg);
	} else if (awal==3 && akhir==7){ //mengubah satuan jarak dag ke mg
		mg = dag_mg (x);
		printf("\nHasil Konversi : \nJarak %.2f dag = %.2f mg\n", x,mg);
	} else if (awal==4 && akhir==1){ //mengubah satuan jarak g ke kg
		kg = g_kg (x);
		printf("\nHasil Konversi : \nJarak %.2f g = %.2f kg\n", x,kg);
	} else if (awal==4 && akhir==2){ //mengubah satuan jarak g ke hg
		hg = g_hg (x);
		printf("\nHasil Konversi : \nJarak %.2f g = %.2f hg\n", x,hg);
	} else if (awal==4 && akhir==3){ //mengubah satuan jarak g ke dag
		dag = g_dag (x);
		printf("\nHasil Konversi : \nJarak %.2f g = %.2f dag\n", x,dag);
	} else if (awal==4 && akhir==5){ //mengubah satuan jarak g ke dg
		dg = g_dg (x);
		printf("\nHasil Konversi : \nJarak %.2f g = %.2f dg\n", x,dg);
	} else if (awal==4 && akhir==6){ //mengubah satuan jarak g ke cg
		cg = g_cg (x);
		printf("\nHasil Konversi : \nJarak %.2f g = %.2f cg\n", x,cg);
	} else if (awal==4 && akhir==7){ //mengubah satuan jarak g ke mg
		mg = g_mg (x);
		printf("\nHasil Konversi : \nJarak %.2f m = %.2f mg\n", x,mg);
	} else if (awal==5 && akhir==1){ //mengubah satuan jarak dg ke kg
		kg = dg_kg (x);
		printf("\nHasil Konversi : \nJarak %.2f dg = %.2f kg\n", x,kg);
	} else if (awal==5 && akhir==2){ //mengubah satuan jarak dg ke hg
		hg = dg_hg (x);
		printf("\nHasil Konversi : \nJarak %.2f dg = %.2f hg\n", x,hg);
	} else if (awal==5 && akhir==3){ //mengubah satuan jarak dg ke dag
		dag = dg_dag (x);
		printf("\nHasil Konversi : \nJarak %.2f dg = %.2f dag\n", x,dag);
	} else if (awal==5 && akhir==4){ //mengubah satuan jarak dg ke g
		g = dg_g (x);
		printf("\nHasil Konversi : \nJarak %.2f dg = %.2f g\n", x,g);
	} else if (awal==5 && akhir==6){ //mengubah satuan jarak dg ke cg
		cg = dg_cg (x);
		printf("\nHasil Konversi : \nJarak %.2f dg = %.2f cg\n", x,cg);
	} else if (awal==5 && akhir==7){ //mengubah satuan jarak dg ke mg
		mg = dg_mg (x);
		printf("\nHasil Konversi : \nJarak %.2f dg = %.2f mg\n", x,mg);
	} else if (awal==6 && akhir==1){ //mengubah satuan jarak cg ke kg
		kg = cg_kg (x);
		printf("\nHasil Konversi : \nJarak %.2f cg = %.2f kg\n", x,kg);
	} else if (awal==6 && akhir==2){ //mengubah satuan jarak cg ke hg
		hg = cg_hg (x);
		printf("\nHasil Konversi : \nJarak %.2f cg = %.2f hg\n", x,hg);
	} else if (awal==6 && akhir==3){ //mengubah satuan jarak cg ke dag
		dag = cg_kg (x);
		printf("\nHasil Konversi : \nJarak %.2f cg = %.2f dag\n", x,dag);
	} else if (awal==6 && akhir==4){ //mengubah satuan jarak cg ke g
		g = cg_g (x);
		printf("\nHasil Konversi : \nJarak %.2f cg = %.2f g\n", x,g);
	} else if (awal==6 && akhir==5){ //mengubah satuan jarak cg ke dg
		dg = cg_dg (x);
		printf("\nHasil Konversi : \nJarak %.2f cg = %.2f dg\n", x,dg);
	} else if (awal==6 && akhir==7){ //mengubah satuan jarak cg ke mg
		mg = cg_mg (x);
		printf("\nHasil Konversi : \nJarak %.2f cg = %.2f mg\n", x,mg);
	} else if (awal==7 && akhir==1){ //mengubah satuan jarak mg ke kg
		kg = mg_kg (x);
		printf("\nHasil Konversi : \nJarak %.2f mg = %.2f kg\n", x,kg);
	} else if (awal==7 && akhir==2){ //mengubah satuan jarak mg ke hg
		hg = mg_hg (x);
		printf("\nHasil Konversi : \nJarak %.2f mg = %.2f hg\n", x,hg);
	} else if (awal==7 && akhir==3){ //mengubah satuan jarak mg ke dag
		dag = mg_dag (x);
		printf("\nHasil Konversi : \nJarak %.2f mg = %.2f dag\n", x,dag);
	} else if (awal==7 && akhir==4){ //mengubah satuan jarak mg ke g
		g = mg_g (x);
		printf("\nHasil Konversi : \nJarak %.2f mg = %.2f g\n", x,g);
	} else if (awal==7 && akhir==5){ //mengubah satuan jarak mg ke dg
		dg = mg_dg (x);
		printf("\nHasil Konversi : \nJarak %.2f mg = %.2f dg\n", x,dg);
	} else if (awal==7 && akhir==6){ //mengubah satuan jarak mg ke cg
		cg = mg_cg (x);
		printf("\nHasil Konversi : \nJarak %.2f mg = %.2f cg\n", x,cg);
	}
	system ("pause");
	 
}

/*ALGORITMA*/


void konversi(){
	int pilih;
    system("cls");
    printf("\n\t1. Konversi Satuan Suhu\n\t2. Konversi Satuan Jarak\n\t3. Konversi Satuan Massa\n\t4. Menu utama");
    printf("\n\tMasukkan pilihan : ");
    scanf("%d", &pilih);
    switch(pilih){
    	case 1 :
    		system("cls");
    		input_suhu();
    		konversi();
    		break;
    	case 2 :
    		input_jarak();
    		konversi();
    		break;
    	case 3 :
    		input_massa();
    		konversi();
    		break;
//    	case 4 :
//    		//mainMenu();
//    		break;
		default :
    		exit(1);
	}
}
#endif
