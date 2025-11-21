/**
* @file Star.cpp
* @description Yıldız şeklinin ekrana çizilmesi, hareket ettirilmesi ve ilgili işlevlerin gerçekleştirilmesi.
* @course Bilgisayar Mühendisliği - ikinci Öğretim
* @assignment 1. Ödev
* @date 18.11.2024
* @authоr 
* Belal Alhamid - G221210592 - belal.alhamid@ogr.sakarya.edu.tr
*/

#include "Star.hpp"

void Star::draw(char ekran[][EKRAN_SUTUN]) {
    int cx = x;
    int cy = y;

    // Merkez
    if (cy >= 0 && cy < EKRAN_SATIR && cx >= 0 && cx < EKRAN_SUTUN)
        ekran[cy][cx] = karakter;

    // Yukarı
    if (cy - 1 >= 0)
        ekran[cy - 1][cx] = karakter;

    // Aşağı
    if (cy + 1 < EKRAN_SATIR)
        ekran[cy + 1][cx] = karakter;

    // Sağ
    if (cx + 1 < EKRAN_SUTUN)
        ekran[cy][cx + 1] = karakter;

    // Sol
    if (cx - 1 >= 0)
        ekran[cy][cx - 1] = karakter;
}
