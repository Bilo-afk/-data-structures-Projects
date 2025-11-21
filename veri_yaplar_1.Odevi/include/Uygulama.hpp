/**
* @file Uygulama.hpp
* @description Uygulamanın genel işleyişini yöneten sınıfın tanımı.
* @course Bilgisayar Mühendisliği - ikinci Öğretim
* @assignment 1. Ödev
* @date 18.11.2024
* @author 
* Belal Alhamid - G221210592 - belal.alhamid@ogr.sakarya.edu.tr
*/
#ifndef UYGULAMA_HPP
#define UYGULAMA_HPP

#include "Ekran.hpp"
#include "AnaListe.hpp"
#include "Triangle.hpp"
#include "Rectangle.hpp"
#include "Star.hpp"
#include <string> 

using namespace std;


class Uygulama {
private:
    AnaListe anaListe;
    AnaListeDugum* aktifDugum;
    SekilDugum* aktifSekil;
    Ekran ekran;

    bool sekilModu; // false -> liste modu, true -> sekil modu

    
    // ⭐ liste 10 için ekstra sahneleri saymak
    int ekstraSahne10;
    bool bosMod;   // ⭐ yeni eklendi

     std::string veriDosyaAdi;  // ⭐  txt


public:
    Uygulama();

    void baslat();
    void anaDongu();
 


private:
    void listeModuIsle(char tus);
    void sekilModuIsle(char tus);

    void ekranTemizVeCiz();
    void ekranGuncelle();

    void rastgeleOlustur();

    // Yeni: liste kutularını ve komut satırını çizer
    void listeKutulariniCiz();
    void komutSatiriniCiz();

    // ⭐ liste 10'da S basınca yeni sahne üret
    void sonrakiSahneListe10();

     // ⭐  txt
    bool dosyadanOku(const std::string& dosyaAdi);
    void dosyayaYaz(const std::string& dosyaAdi);
};

#endif
