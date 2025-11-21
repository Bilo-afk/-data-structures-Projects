/**
* @file Shape.hpp
* @description Tüm şekiller için ortak temel sınıfın tanımı; konum, karakter ve hareket fonksiyonlarını içerir.
* @course Bilgisayar Mühendisliği - ikinci Öğretim
* @assignment 1. Ödev
* @date 18.11.2024
* @authоr 
* Belal Alhamid - G221210592 - belal.alhamid@ogr.sakarya.edu.tr
*/

#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "Sabitler.hpp"

class Shape {
protected:
    int x;          // ekran sutun
    int y;          // ekran satir
    char karakter;  // çizimde kullanılacak karakter
    int oncelik;    // çizim sırası (z-index gibi)

public:
    Shape(int x, int y, char karakter, int oncelik);

    virtual ~Shape() {}

    // tüm şekillerin ekrana çizmesi gereken fonksiyon
    virtual void draw(char ekran[][EKRAN_SUTUN]) = 0;

    // şekli hareket ettirmek için
    void hareketYap(int dx, int dy);

    // erişim fonksiyonları
    int getX() const { return x; }
    int getY() const { return y; }
    char getKarakter() const { return karakter; }
    int getOncelik() const { return oncelik; }
};

#endif
