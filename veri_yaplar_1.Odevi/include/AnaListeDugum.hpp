/**
* @file AnaListeDugum.hpp
* @description Ana listedeki her bir düğümün yapısı; liste numarası, şekil listesi ve bağlı liste bağlantıları.
* @course Bilgisayar Mühendisliği - ikinci Öğretim
* @assignment 1. Ödev
* @date 18.11.2024
* @authоr 
* Belal Alhamid - G221210592 - belal.alhamid@ogr.sakarya.edu.tr
*/

#ifndef ANALISTEDUGUM_HPP
#define ANALISTEDUGUM_HPP

#include "SekilListesi.hpp"

class AnaListeDugum {
public:
    int listeNo;
    SekilListesi sekiller;

    AnaListeDugum* onceki;
    AnaListeDugum* sonraki;

    AnaListeDugum(int no);  // sadece tanımı burada
};

#endif
