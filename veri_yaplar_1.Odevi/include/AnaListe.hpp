/**
* @file AnaListe.hpp
* @description Ana listede bulunan düğümlerin yapısını ve temel işlevlerin tanımını içerir.
* @course Bilgisayar Mühendisliği - ikinci Öğretim
* @assignment 1. Ödev
* @date 18.11.2024
* @author 
* Belal Alhamid - G221210592 - belal.alhamid@ogr.sakarya.edu.tr
*/

#ifndef ANALISTE_HPP
#define ANALISTE_HPP

#include "AnaListeDugum.hpp"

class AnaListe {
private:
    AnaListeDugum* bas;
    AnaListeDugum* son;

public:
    AnaListe();
    ~AnaListe();

    bool bosMu() const;

    AnaListeDugum* ilk() const { return bas; }
    AnaListeDugum* sonDugum() const { return son; }

    // Yeni düğüm ekler, eklenen düğümün adresini döner
    AnaListeDugum* dugumEkle(int listeNo);

    // Verilen düğümü listeden siler
    void dugumSil(AnaListeDugum* hedef);

    int dugumSayisi() const;
};

#endif
