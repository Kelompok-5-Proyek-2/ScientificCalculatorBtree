#ifndef Konversi_Suhu_H
#define Konversi_Suhu_H
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


/*************************************************** SIN, COS, TAN ***************************************************/


//void trigonometri (){
//	int pilih;
//	double derajat;
//    system("cls");
//    printf("\n\t1. Hitung Sin\n\t2. Hitung Cos\n\t3. Hitung Tan\n\t4. Menu utama");
//    printf("\n\tMasukkan pilihan : ");
//    scanf("%d", &pilih);
//    switch(pilih){
//    	case 1 :
//    		system("cls");
//    		printf("Masukan nilai Sin :");
//    		scanf("%lf", &derajat);
//    		printf("Sin %lf = %.2lf\n", derajat, sinus(derajat));
//    		break;
//    	case 2 :
//    		system("cls");
//    		printf("Masukan nilai Cos :");
//    		scanf("%lf", &derajat);
//    		printf("Cos %lf = %.2lf\n", derajat, cosinus(derajat));
//    		break;
//    	case 3 :
//    		system("cls");
//    		printf("Masukan nilai Tan :");
//    		scanf("%lf", &derajat);
//    		printf("Tan %lf = %.2lf\n", derajat, tangen(derajat));
//    		break;
//    	case 4 :
//    		//CalArit();
//    		break;
//		default :
//			exit(1);
//		
//		
//	}
//	system("pause");
//}


/*************************************************** NILAI MUTLAK ***************************************************/

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

/*************************************************** LOGARITMA ***************************************************/

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


/*************************************************** TAMPILAN ***************************************************/

// Prosedur dari referensi internet untuk menentukan posisi 
void gotoxy(int x, int y){
	HANDLE hConsoleOutput;  
	COORD dwCursorPosition;  
	dwCursorPosition.X = x;  
	dwCursorPosition.Y = y;  
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);  
	SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);   
}

// Menampilkan judul kalkulator
void tampilan(){
int i;
system("cls");
i=1;
gotoxy(5,1);printf("##====================================[ K  E  L  O  M  P  O  K    5]=====================================##");
while (i<=10){
	gotoxy(5,2);	printf("||");																	gotoxy(110,2);	printf("||");
	gotoxy(5,3);	printf("||");																	gotoxy(110,3);	printf("||");
	gotoxy(5,4);	printf("||");																	gotoxy(110,4);	printf("||");
	gotoxy(5,5);	printf("||");																	gotoxy(110,5);	printf("||");
	gotoxy(5,6);	printf("||");																	gotoxy(110,6);	printf("||");
	gotoxy(5,7);	printf("||");																	gotoxy(110,7);	printf("||");
	gotoxy(5,8);	printf("||");																	gotoxy(110,8);	printf("||");
	gotoxy(5,9);	printf("||");																	gotoxy(110,9);	printf("||");
	gotoxy(i,4);	printf("       *####*    *####*  *####*  *#####  #*    #  *######*  *####*  *#####  *####*  *####*      \n");
	gotoxy(19-i,5);	printf("        #        #          ##    #       # #   #     ##       ##    #         ##    #          \n");
	gotoxy(i-1,6);	printf("        *####*  #           ##    #####   #  #  #     ##       ##    *####     ##   #           \n");
	gotoxy(19-i,7);	printf("             #   #          ##    #       #   # #     ##       ##    #         ##    #          \n");
	gotoxy(i-1,8);	printf("        *####*   *####*   *####*  *#####  #    *#     ##     *####*  #       *####*  *####*     \n");
	Sleep(300);
	i++;
	}
gotoxy(5,10);printf("##======================================C  A  L  C  U  L  A  T O  R======================================##");
}

#endif
