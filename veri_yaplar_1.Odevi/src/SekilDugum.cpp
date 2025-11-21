/**
* @file SekilDugum.cpp
* @description Şekil düğümünün oluşturulması ve bağlı listedeki temel yapı taşının gerçekleştirilmesi.
* @course Bilgisayar Mühendisliği - ikinci Öğretim
* @assignment 1. Ödev
* @date 18.11.2024
* @authоr 
* Belal Alhamid - G221210592 - belal.alhamid@ogr.sakarya.edu.tr
*/

#include "SekilDugum.hpp"

SekilDugum::SekilDugum(Shape* v) {
    veri = v;
    sonraki = nullptr;
}
