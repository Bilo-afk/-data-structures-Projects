/**
* @file AnaListeDugum.cpp
* @description Ana listedeki düğüm yapısının oluşturulması ve başlangıç değerlerinin atanması.
* @course Bilgisayar Mühendisliği - ikinci Öğretim
* @assignment 1. Ödev
* @date 18.11.2024
* @authоr 
* Belal Alhamid - G221210592 - belal.alhamid@ogr.sakarya.edu.tr
*/

#include "AnaListeDugum.hpp"

AnaListeDugum::AnaListeDugum(int no) {
    listeNo = no;
    onceki = nullptr;
    sonraki = nullptr;
}
