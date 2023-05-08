#ifndef barry_h
#define barry_h
#include <stdio.h>
#include <math.h>	// math.h masih digunakan disini karena dalam modul logaritma masih menggunakan pow
#include <stdlib.h>

// modulnya disimpan di main
double perform_trig_operation(double sudut, char op[]);

// logaritma natural
double lognat(double angka)
{
    double result = 0.0;
    double i;
    int iterasi = 30000;
    
    //looping sebanyak iterasi, semakin banyak iterasi maka semakin akurat jawabannya
    for (i = 1.0; i <= iterasi; i = i + 1.0) {
        result += (1.0 / i) * pow(((angka - 1.0) / angka), i);
    }
    return result;
}

//logaritma
double logaritma(double angka, double basis)
{
	return lognat(angka) / lognat(basis);
}


#endif
