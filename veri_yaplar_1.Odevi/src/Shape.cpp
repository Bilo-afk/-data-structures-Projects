/**
* @file Shape.cpp
* @description Shape sınıfının temel özelliklerinin (konum, hareket) gerçekleştirilmesi.
* @course Bilgisayar Mühendisliği - ikinci Öğretim
* @assignment 1. Ödev
* @date 18.11.2024
* @authоr 
* Belal Alhamid - G221210592 - belal.alhamid@ogr.sakarya.edu.tr
*/

#include "Shape.hpp"

Shape::Shape(int x, int y, char karakter, int oncelik)
    : x(x), y(y), karakter(karakter), oncelik(oncelik)
{
}

void Shape::hareketYap(int dx, int dy) {
    x += dx;
    y += dy;

    // güvenlik: ekran dışına çıkmasın
    if (x < 0) x = 0;
    if (y < 0) y = 0;
    if (x >= EKRAN_SUTUN) x = EKRAN_SUTUN - 1;
    if (y >= EKRAN_SATIR - 1) y = EKRAN_SATIR - 2;  
}
