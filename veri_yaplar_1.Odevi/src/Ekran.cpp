/**
* @file Ekran.cpp
* @description Ekran sınıfının piksel matrisini yönetmesi, temizlemesi ve ekrana yazdırma işlemlerinin gerçekleştirilmesi.
* @course Bilgisayar Mühendisliği - ikinci Öğretim
* @assignment 1. Ödev
* @date 18.11.2024
* @authоr 
* Belal Alhamid - G221210592 - belal.alhamid@ogr.sakarya.edu.tr
*/

#include "Ekran.hpp"

Ekran::Ekran() {
    temizle();
}

void Ekran::temizle() {
    for (int i = 0; i < EKRAN_SATIR; i++) {
        for (int j = 0; j < EKRAN_SUTUN; j++) {
            piksel[i][j] = ' ';
        }
    }
}

void Ekran::karakterYaz(int satir, int sutun, char ch) {
    if (satir < 0 || satir >= EKRAN_SATIR) return;
    if (sutun < 0 || sutun >= EKRAN_SUTUN) return;
    piksel[satir][sutun] = ch;
}

void Ekran::goster() const {
    // Windows için ekran temizleme (isteğe bağlı)
    // system("cls");

    for (int i = 0; i < EKRAN_SATIR; i++) {
        for (int j = 0; j < EKRAN_SUTUN; j++) {
            std::cout << piksel[i][j];
        }
        std::cout << '\n';
    }
}
