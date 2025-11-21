/**
* @file AnaListe.cpp
* @description Ana listedeki düğümlerin oluşturulması, silinmesi ve yönetilmesi işlemlerinin gerçekleştirilmesi.
* @course Bilgisayar Mühendisliği - ikinci Öğretim
* @assignment 1. Ödev
* @date 18.11.2024
* @authoр 
* Belal Alhamid - G221210592 - belal.alhamid@ogr.sakarya.edu.tr
*/

#include "AnaListe.hpp"
#include <iostream>

AnaListe::AnaListe()
    : bas(nullptr), son(nullptr) {}

AnaListe::~AnaListe() {
    AnaListeDugum* simdiki = bas;
    while (simdiki != nullptr) {
        AnaListeDugum* silinecek = simdiki;
        simdiki = simdiki->sonraki;

        // Önce bu düğümün şekil listesini yok eden destructor çalışır
        // (SekilListesi içinde zaten tüm Shape* ve düğümleri siliniyor)
        delete silinecek;
    }
}

bool AnaListe::bosMu() const {
    return bas == nullptr;
}

AnaListeDugum* AnaListe::dugumEkle(int listeNo) {
    AnaListeDugum* yeni = new AnaListeDugum(listeNo);

    if (bosMu()) {
        bas = son = yeni;
    } else {
        son->sonraki = yeni;
        yeni->onceki = son;
        son = yeni;
    }

    return yeni;
}

void AnaListe::dugumSil(AnaListeDugum* hedef) {
    if (hedef == nullptr || bosMu()) return;

    // Baştaki düğüm mü?
    if (hedef == bas) {
        bas = hedef->sonraki;
        if (bas != nullptr) {
            bas->onceki = nullptr;
        } else {
            // Liste tamamen boşaldıysa son da nullptr olmalı
            son = nullptr;
        }
    }
    // Sondaki düğüm mü?
    else if (hedef == son) {
        son = hedef->onceki;
        if (son != nullptr) {
            son->sonraki = nullptr;
        } else {
            bas = nullptr;
        }
    }
    // Ortadaki düğüm
    else {
        AnaListeDugum* onceki = hedef->onceki;
        AnaListeDugum* sonraki = hedef->sonraki;

        if (onceki != nullptr) onceki->sonraki = sonraki;
        if (sonraki != nullptr) sonraki->onceki = onceki;
    }

    delete hedef;
}

int AnaListe::dugumSayisi() const {
    int sayac = 0;
    AnaListeDugum* simdiki = bas;
    while (simdiki != nullptr) {
        sayac++;
        simdiki = simdiki->sonraki;
    }
    return sayac;
}
