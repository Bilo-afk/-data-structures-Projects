/**
* @file SekilListesi.cpp
* @description Şekil listesinin tüm fonksiyonlarının (ekleme, silme, tümünü temizleme) gerçekleştirilmesi.
* @course Bilgisayar Mühendisliği - ikinci Öğretim
* @assignment 1. Ödev
* @date 18.11.2024
* @authоr 
* Belal Alhamid - G221210592 - belal.alhamid@ogr.sakarya.edu.tr
*/

#include "SekilListesi.hpp"
#include <iostream>

using namespace std;

SekilListesi::SekilListesi()
    : bas(nullptr)
{
}

SekilListesi::~SekilListesi() {
    hepsiniTemizle();
}

// ==========================================
//  TÜM ŞEKİLLERİ SİL (ekstra sahneler için)
// ==========================================
void SekilListesi::hepsiniTemizle() {
    SekilDugum* simdiki = bas;

    while (simdiki != nullptr) {
        SekilDugum* silinecek = simdiki;
        simdiki = simdiki->sonraki;

        delete silinecek->veri;   // Shape*
        delete silinecek;         // Düğüm
    }

    bas = nullptr;
}

// ==========================================
//  YENİ ŞEKİL EKLE
// ==========================================
void SekilListesi::sekilEkle(Shape* yeni) {
    SekilDugum* yeniDugum = new SekilDugum(yeni);

    if (bas == nullptr) {
        bas = yeniDugum;
        return;
    }

    SekilDugum* simdiki = bas;
    while (simdiki->sonraki != nullptr) {
        simdiki = simdiki->sonraki;
    }

    simdiki->sonraki = yeniDugum;
}

// ==========================================
//  BELİRLİ BİR ŞEKLİ SİL
// ==========================================
void SekilListesi::sekilSil(Shape* hedef) {
    if (bas == nullptr) return;

    // ilk düğüm siliniyorsa
    if (bas->veri == hedef) {
        SekilDugum* silinecek = bas;
        bas = bas->sonraki;

        delete silinecek->veri;
        delete silinecek;
        return;
    }

    // ortadaki/sondaki düğümler
    SekilDugum* simdiki = bas;
    SekilDugum* onceki = nullptr;

    while (simdiki != nullptr && simdiki->veri != hedef) {
        onceki = simdiki;
        simdiki = simdiki->sonraki;
    }

    if (simdiki == nullptr) return; // bulunamadı

    onceki->sonraki = simdiki->sonraki;

    delete simdiki->veri;
    delete simdiki;
}

// ==========================================
//  LİSTE BOŞ MU?
// ==========================================
bool SekilListesi::bosMu() const {
    return bas == nullptr;
}
