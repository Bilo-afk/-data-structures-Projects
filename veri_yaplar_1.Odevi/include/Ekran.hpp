/**
* @file Ekran.hpp
* @description Ekran yapısını, piksel matrisini ve ekrana çizim yapma fonksiyonlarını tanımlar.
* @course Bilgisayar Mühendisliği - ikinci Öğretim
* @assignment 1. Ödev
* @date 18.11.2024
* @authoг 
* Belal Alhamid - G221210592 - belal.alhamid@ogr.sakarya.edu.tr
*/

#ifndef EKRAN_HPP
#define EKRAN_HPP

#include <iostream>
#include "Sabitler.hpp"

class Ekran {
private:
    char piksel[EKRAN_SATIR][EKRAN_SUTUN];

public:
    Ekran();

    void temizle();
    void karakterYaz(int satir, int sutun, char ch);
    void goster() const;

    // ★ ekran matrisi pointer olarak döner
    char (*getPiksel())[EKRAN_SUTUN] {
        return piksel;
    }
};

#endif
