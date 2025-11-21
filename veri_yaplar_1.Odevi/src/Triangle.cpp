/**
* @file Triangle.cpp
* @description Üçgen şeklinin ekrana çizilmesi, hareket ettirilmesi ve ilgili fonksiyonların gerçekleştirilmesi.
* @course Bilgisayar Mühendisliği - ikinci Öğretim
* @assignment 1. Ödev
* @date 18.11.2024
* @authоr 
* Belal Alhamid - G221210592 - belal.alhamid@ogr.sakarya.edu.tr
*/

#include "Triangle.hpp"

void Triangle::draw(char ekran[][EKRAN_SUTUN]) {
    int merkez = x + genislik / 2;

    for (int sat = 0; sat < yukseklik; sat++) {
        int yaricap = sat; // üçgenin genişlemesi

        int sol = merkez - yaricap;
        int sag = merkez + yaricap;

        for (int sut = sol; sut <= sag; sut++) {

            int gercekSatir = y + sat;
            int gercekSutun = sut;

            if (gercekSatir < 0 || gercekSatir >= EKRAN_SATIR) continue;
            if (gercekSutun < 0 || gercekSutun >= EKRAN_SUTUN) continue;

            ekran[gercekSatir][gercekSutun] = karakter;
        }
    }
}
