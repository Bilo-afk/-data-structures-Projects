/**
* @file Triangle.hpp
* @description Üçgen şeklini temsil eden sınıfın tanımı; ekrana çizim ve hareket fonksiyonları.
* @course Bilgisayar Mühendisliği - ikinci Öğretim
* @assignment 1. Ödev
* @date 18.11.2024
* @authоr 
* Belal Alhamid - G221210592 - belal.alhamid@ogr.sakarya.edu.tr
*/

#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "Shape.hpp"

class Triangle : public Shape {
private:
    int genislik;
    int yukseklik;

public:
    Triangle(int x, int y, int gen, int yuk, char kar, int z)
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
