/**
* @file SekilListesi.hpp
* @description Bir listede bulunan tüm şekilleri tutan ve yöneten yapı; ekleme, silme ve temizleme fonksiyonlarının tanımı.
* @course Bilgisayar Mühendisliği - ikinci Öğretim
* @assignment 1. Ödev
* @date 18.11.2024
* @authоr 
* Belal Alhamid - G221210592 - belal.alhamid@ogr.sakarya.edu.tr
*/

#ifndef SEKIL_LISTESI_HPP
#define SEKIL_LISTESI_HPP

#include "SekilDugum.hpp"

class SekilListesi {
private:
    SekilDugum* bas;

public:
    SekilListesi();
    ~SekilListesi();

    void sekilEkle(Shape* yeni);
    void sekilSil(Shape* hedef);

    bool bosMu() const;
    SekilDugum* ilk() const { return bas; }

    // ⭐ tüm şekilleri silmek için
    void hepsiniTemizle();
};

#endif
