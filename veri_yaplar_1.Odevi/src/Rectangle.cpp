/**
* @file Rectangle.cpp
* @description Dikdörtgen şeklinin ekrana çizilmesi, hareket ettirilmesi ve ilgili işlevlerin gerçekleştirilmesi.
* @course Bilgisayar Mühendisliği - ikinci Öğretim
* @assignment 1. Ödev
* @date 18.11.2024
* @authоr 
* Belal Alhamid - G221210592 - belal.alhamid@ogr.sakarya.edu.tr
*/

#include "Rectangle.hpp"

void Rectangle::draw(char ekran[][EKRAN_SUTUN]) {
    for (int i = 0; i < yukseklik; i++) {
        for (int j = 0; j < genislik; j++) {
            int satir = y + i;
            int sutun = x + j;

            if (satir < 0 || satir >= EKRAN_SATIR) continue;
            if (sutun < 0 || sutun >= EKRAN_SUTUN) continue;

            ekran[satir][sutun] = karakter;
        }
    }
}
