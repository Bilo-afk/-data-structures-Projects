/**
* @file SekilDugum.hpp
* @description Bir şekle ait düğüm yapısının tanımı; listedeki tek yönlü bağlı yapının temel birimini içerir.
* @course Bilgisayar Mühendisliği - ikinci Öğretim
* @assignment 1. Ödev
* @date 18.11.2024
* @authоr 
* Belal Alhamid - G221210592 - belal.alhamid@ogr.sakarya.edu.tr
*/

#ifndef SEKILDUGUM_HPP
#define SEKILDUGUM_HPP

#include "Shape.hpp"

class SekilDugum {
public:
    Shape* veri;
    SekilDugum* sonraki;

    SekilDugum(Shape* v);  // sadece tanım burada
};

#endif
