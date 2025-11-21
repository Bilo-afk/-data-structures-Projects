/**
* @file Rectangle.hpp
* @description Dikdörtgen şeklinin tanımı; boyut, konum ve ekrana çizim fonksiyonlarını içerir.
* @course Bilgisayar Mühendisliği - ikinci Öğretim
* @assignment 1. Ödev
* @date 18.11.2024
* @authоr 
* Belal Alhamid - G221210592 - belal.alhamid@ogr.sakarya.edu.tr
*/

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Shape.hpp"

class Rectangle : public Shape {
private:
    int genislik;
    int yukseklik;

public:
    Rectangle(int x, int y, int gen, int yuk, char kar, int z)
        : Shape(x, y, kar, z)
    {
        this->genislik = gen;
        this->yukseklik = yuk;
    }

    // 🔹 إضافة getters لاستخدامها عند kaydetme (dosyaya yaz)
    int getGenislik() const { return genislik; }
    int getYukseklik() const { return yukseklik; }

    void draw(char ekran[][EKRAN_SUTUN]) override;
};

#endif
