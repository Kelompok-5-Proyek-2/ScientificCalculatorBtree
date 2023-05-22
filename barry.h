#ifndef barry_h
#define barry_h
#include <stdio.h>
#include <stdlib.h>

// modulnya disimpan di main
double perform_trig_operation(double sudut, char op[]);

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

#endif
