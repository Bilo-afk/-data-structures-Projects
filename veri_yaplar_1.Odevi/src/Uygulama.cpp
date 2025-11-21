/**
* @file Uygulama.cpp
* @description Uygulama sınıfının tüm işlevlerinin gerçekleştirilmesi.
* @course Bilgisayar Mühendisliği - ikinci Öğretim
* @assignment 1. Ödev
* @date 18.11.2024
* @author 
* Belal Alhamid - G221210592 - belal.alhamid@ogr.sakarya.edu.tr
*/

#include "Uygulama.hpp"
#include <iostream>
#include <cstdio>    // sprintf için
#include <fstream>   // dosya işlemleri için
#include <cstdlib>   // rand, srand
#include <ctime>     // time


using namespace std;

Uygulama::Uygulama()
    : aktifDugum(nullptr),
      aktifSekil(nullptr),
      sekilModu(false),
      ekstraSahne10(0),
      bosMod(false),
      veriDosyaAdi("veri.txt")
{
    // Rastgele üretim için seed
    std::srand((unsigned int)std::time(nullptr));
}




void Uygulama::baslat() {
    cout << "Baslatma modu (1: Rastgele  /  2: Dosyadan): ";
    int sec;
    cin >> sec;

    if (sec == 2) {
        bool ok = dosyadanOku(veriDosyaAdi);
        if (!ok) {
            cout << "Dosya okunamadi veya bos. Rastgele olusturulacak.\n";
            rastgeleOlustur();
        }
    }
    else {
        // 1 veya diger degerler -> rastgele
        rastgeleOlustur();
    }

    anaDongu();

    // Programdan cikmadan once mevcut durumu dosyaya yaz
    dosyayaYaz(veriDosyaAdi);
}



void Uygulama::anaDongu() {
    while (true) {
        ekranTemizVeCiz();

        cout << "\nKomut: ";
        char tus;
        cin >> tus;

        if (tus == TUS_CIKIS) {
            // döngüden çık -> dosyaya yazılacak
            break;
        }

        if (!sekilModu)
            listeModuIsle(tus);
        else
            sekilModuIsle(tus);
    }
}


// --------------------------------------------------
// LISTE MODU KONTROLLER
// --------------------------------------------------
void Uygulama::listeModuIsle(char tus) {

    // Yukarı hareket (w)
    if (tus == TUS_YUKARI) {
        if (aktifDugum && aktifDugum->onceki)
            aktifDugum = aktifDugum->onceki;
    }

    // Aşağı hareket (s)
    else if (tus == TUS_ASAGI) {

        // Normalde bir sonraki düğüme geç
        if (aktifDugum && aktifDugum->sonraki) {
            aktifDugum = aktifDugum->sonraki;
        }
        // Eğer sonraki düğüm yok ve listedeyiz = 10 → ekstra sahne
        else if (aktifDugum && !aktifDugum->sonraki && aktifDugum->listeNo == 10) {
            sonrakiSahneListe10();   // ⭐ yeni sahne üret
        }
    }

    // Liste içindeki şekilleri kontrol moduna giriş (f)
    else if (tus == TUS_LISTE_SEC) {
        if (aktifDugum && !aktifDugum->sekiller.bosMu()) {
            aktifSekil = aktifDugum->sekiller.ilk();
            sekilModu = true;  // sekil moduna gir
        }
    }

    // Listeyi silme (c)
    else if (tus == TUS_SIL) {

        if (aktifDugum) {
            AnaListeDugum* silinecek = aktifDugum;

            // Silinecek düğümden sonra gelen varsa → ona geç
            if (aktifDugum->sonraki)
                aktifDugum = aktifDugum->sonraki;

            // Yoksa yukarıdakine dön
            else
                aktifDugum = aktifDugum->onceki;

            anaListe.dugumSil(silinecek);

            // Eğer hiç düğüm kalmadıysa yeni bir tane oluştur
            if (aktifDugum == nullptr)
                aktifDugum = anaListe.dugumEkle(1);
        }
    }
}


// --------------------------------------------------
// SEKIL MODU KONTROLLER
// --------------------------------------------------
void Uygulama::sekilModuIsle(char tus) {
    // Güvenlik
    if (!aktifDugum || !aktifSekil) {
        sekilModu = false;
        return;
    }

    // (awsd) hareket
    if (tus == TUS_SOL) {          // a
        aktifSekil->veri->hareketYap(-1, 0);
    }
    else if (tus == TUS_SAGA) {    // d
        aktifSekil->veri->hareketYap(1, 0);
    }
    else if (tus == TUS_YUKARI) {  // w
        aktifSekil->veri->hareketYap(0, -1);
    }
    else if (tus == TUS_ASAGI) {   // s
        aktifSekil->veri->hareketYap(0, 1);
    }

    // (q) onceki sekil
    else if (tus == TUS_ONCEKI) {
        SekilDugum* ilk = aktifDugum->sekiller.ilk();
        if (!ilk) return;

        // Eğer aktif ilk degilse, bir önceki düğümü bul
        if (aktifSekil != ilk) {
            SekilDugum* simdiki = ilk;
            while (simdiki->sonraki && simdiki->sonraki != aktifSekil) {
                simdiki = simdiki->sonraki;
            }
            if (simdiki->sonraki == aktifSekil) {
                aktifSekil = simdiki;
            }
        }
        else {
            // aktif zaten ilk ise -> listenin sonuna sar
            SekilDugum* son = ilk;
            while (son->sonraki) son = son->sonraki;
            aktifSekil = son;
        }
    }

    // (e) sonraki sekil
    else if (tus == TUS_SONRAKI) {
        if (aktifSekil->sonraki) {
            aktifSekil = aktifSekil->sonraki;
        }
        else {
            // son sekildeysek -> başa dön
            SekilDugum* ilk = aktifDugum->sekiller.ilk();
            if (ilk) aktifSekil = ilk;
        }
    }

    // (c) sekil sil
    else if (tus == TUS_SIL) {
        if (aktifSekil) {
            SekilDugum* sonraki = aktifSekil->sonraki;
            Shape* hedef = aktifSekil->veri;

            aktifDugum->sekiller.sekilSil(hedef);

            if (aktifDugum->sekiller.bosMu()) {
                aktifSekil = nullptr;
                sekilModu = false;
            }
            else {
                if (sonraki)
                    aktifSekil = sonraki;
                else
                    aktifSekil = aktifDugum->sekiller.ilk();
            }
        }
    }

    // (g) listeye don
    else if (tus == TUS_GERI) {
        sekilModu = false;
        aktifSekil = nullptr;
    }
}



// --------------------------------------------------
// EKRAN GÜNCELLEME VE ÇİZİM
// --------------------------------------------------
void Uygulama::ekranTemizVeCiz() {
    ekranGuncelle();
    ekran.goster();
}

void Uygulama::ekranGuncelle() {
    ekran.temizle();

    // ⭐ Sadece aktif listenin şekillerini çiz
    if (aktifDugum != nullptr) {
        SekilDugum* s = aktifDugum->sekiller.ilk();
        while (s != nullptr) {
            s->veri->draw( ekran.getPiksel() );
            s = s->sonraki;
        }
    }

    // ⭐ Sekil modundayken aktif sekili '@' ile isaretle
    if (sekilModu && aktifSekil != nullptr && aktifSekil->veri != nullptr) {
        char (*p)[EKRAN_SUTUN] = ekran.getPiksel();

        int ax = aktifSekil->veri->getX();
        int ay = aktifSekil->veri->getY();

        if (ay >= 0 && ay < EKRAN_SATIR && ax >= 0 && ax < EKRAN_SUTUN) {
            p[ay][ax] = '@';   // aktif şeklin sol-üst noktasına '@' koy
        }
    }

    // Soldaki liste kutularını çiz
    listeKutulariniCiz();

    // En alttaki komut satırını çiz
    komutSatiriniCiz();
}


// --------------------------------------------------

// Solda numaralı kutular: 2, 8, 1, 9, 6, 10 ...
void Uygulama::listeKutulariniCiz() {
    char (*p)[EKRAN_SUTUN] = ekran.getPiksel();

    const int kutuGenislik  = 11; // 0..10
    const int kutuYukseklik = 3;  // 3 satır
    const int aralik        = 1;  // kutular arası boşluk

    AnaListeDugum* d = anaListe.ilk();
    int index = 0;

    while (d != nullptr) {
        int ustSatir = index * (kutuYukseklik + aralik);

        if (ustSatir + kutuYukseklik >= EKRAN_SATIR - 1) break; // son satır komut için

        // kutu çerçevesi
        for (int i = 0; i < kutuYukseklik; i++) {
            int sat = ustSatir + i;
            for (int j = 0; j < kutuGenislik && j < EKRAN_SUTUN; j++) {
                bool kenar = (i == 0 || i == kutuYukseklik - 1 ||
                              j == 0 || j == kutuGenislik - 1);
                p[sat][j] = kenar ? '*' : ' ';
            }
        }

        // ortadaki satıra liste numarasını yaz
        char buf[8];
        std::sprintf(buf, "%d", d->listeNo);
        int len = 0;
        while (buf[len] != '\0') len++;

        int sat = ustSatir + 1;
        int basCol = (kutuGenislik - len) / 2;

        for (int k = 0; k < len; k++) {
            int sut = basCol + k;
            if (sut >= 1 && sut < kutuGenislik - 1)
                p[sat][sut] = buf[k];
        }

        // aktif liste için OK işareti "<--"
        if (d == aktifDugum) {
            int okCol = kutuGenislik; // hemen sağ taraf
            if (sat >= 0 && sat < EKRAN_SATIR - 1 && okCol + 2 < EKRAN_SUTUN) {
                p[sat][okCol]     = '<';
                p[sat][okCol + 1] = '-';
                p[sat][okCol + 2] = '-';
            }
        }

        d = d->sonraki;
        index++;
    }
}

// En alttaki komut satırı
void Uygulama::komutSatiriniCiz() {
    char (*p)[EKRAN_SUTUN] = ekran.getPiksel();
    int sat = EKRAN_SATIR - 1;

   const char* yaziListe =
    "(ws) hareket  (f) listeyi sec  (c) sil  (x) cikis : ";

    const char* yaziSekil =
    "(awsd) hareket  (q) onceki sekil  (e) sonraki sekil  (c) sekil sil  (g) listeye don  (x) cikis : ";

    const char* metin = sekilModu ? yaziSekil : yaziListe;

    int sut = 0;
    while (metin[sut] != '\0' && sut < EKRAN_SUTUN) {
        p[sat][sut] = metin[sut];
        sut++;
    }
    while (sut < EKRAN_SUTUN) {
        p[sat][sut] = ' ';
        sut++;
    }
}

// --------------------------------------------------
// RASTGELE / ORNEK VERI OLUSTURMA
// --------------------------------------------------
void Uygulama::sonrakiSahneListe10() {
    // listeNo = 10 olan dugumu bul
    AnaListeDugum* d = anaListe.ilk();
    while (d != nullptr && d->listeNo != 10) {
        d = d->sonraki;
    }
    if (d == nullptr) return;

    // Eski şekilleri sil
    d->sekiller.hepsiniTemizle();

    // ekstraSahne10 değerine göre farklı sahneler
    if (ekstraSahne10 == 0) {
        // Sahne 1: geniş + blok ve altında o'lar
        d->sekiller.sekilEkle(new Triangle(50, 4, 15, 6, '+', 1));
        d->sekiller.sekilEkle(new Rectangle(45, 11, 22, 3, 'o', 2));
    }
    else if (ekstraSahne10 == 1) {
        // Sahne 2: uzun # şeritleri ve sağda üçgen
        d->sekiller.sekilEkle(new Rectangle(40, 5, 25, 2, '#', 1));
        d->sekiller.sekilEkle(new Rectangle(42, 8, 20, 2, '#', 2));
        d->sekiller.sekilEkle(new Triangle(60, 11, 9, 5, '+', 3));
    }
    else {
        // Sahne 3: sağda büyük o bloğu ve solda * üçgen
        d->sekiller.sekilEkle(new Rectangle(55, 6, 12, 4, 'o', 1));
        d->sekiller.sekilEkle(new Triangle(43, 12, 11, 5, '*', 2));
    }

    // Sonraki sefer için sahne index değişsin (0 -> 1 -> 2 -> 0 ...)
    ekstraSahne10 = (ekstraSahne10 + 1) % 3;
}
bool Uygulama::dosyadanOku(const std::string& dosyaAdi) {
    std::ifstream dosya(dosyaAdi);
    if (!dosya.is_open())
        return false;

    // Ana listeyi sifirla
    anaListe = AnaListe();
    aktifDugum = nullptr;
    aktifSekil = nullptr;
    sekilModu = false;

    int listeSayisi = 0;
    if (!(dosya >> listeSayisi))
        return false;

    for (int i = 0; i < listeSayisi; i++) {
        int listeNo, sekilAdet;
        dosya >> listeNo >> sekilAdet;

        AnaListeDugum* d = anaListe.dugumEkle(listeNo);

        for (int j = 0; j < sekilAdet; j++) {
            char tip;
            int x, y, gen, yuk, z;
            char kar;

            dosya >> tip >> x >> y >> gen >> yuk >> kar >> z;

            Shape* sekil = nullptr;

            if (tip == 'T')
                sekil = new Triangle(x, y, gen, yuk, kar, z);
            else if (tip == 'R')
                sekil = new Rectangle(x, y, gen, yuk, kar, z);
            else if (tip == 'S')
                sekil = new Star(x, y, gen, yuk, kar, z);

            if (sekil != nullptr) {
                d->sekiller.sekilEkle(sekil);
            }
        }
    }

    aktifDugum = anaListe.ilk();
    aktifSekil = nullptr;
    sekilModu = false;

    return true;
}
void Uygulama::dosyayaYaz(const std::string& dosyaAdi) {
    std::ofstream dosya(dosyaAdi);
    if (!dosya.is_open())
        return;

    // Liste sayisini say
    int listeSayisi = 0;
    AnaListeDugum* d = anaListe.ilk();
    while (d != nullptr) {
        listeSayisi++;
        d = d->sonraki;
    }

    dosya << listeSayisi << "\n";

    d = anaListe.ilk();
    while (d != nullptr) {
        // ilgili listede kaç şekil var?
        int sekilAdet = 0;
        SekilDugum* s = d->sekiller.ilk();
        while (s != nullptr) {
            sekilAdet++;
            s = s->sonraki;
        }

        dosya << d->listeNo << " " << sekilAdet << "\n";

        s = d->sekiller.ilk();
        while (s != nullptr) {
            Shape* sek = s->veri;

            int x = sek->getX();
            int y = sek->getY();
            char kar = sek->getKarakter();
            int z = sek->getOncelik();

            int gen = 0, yuk = 0;
            char tip = 'R';

            if (auto t = dynamic_cast<Triangle*>(sek)) {
                tip = 'T';
                gen = t->getGenislik();
                yuk = t->getYukseklik();
            }
            else if (auto r = dynamic_cast<Rectangle*>(sek)) {
                tip = 'R';
                gen = r->getGenislik();
                yuk = r->getYukseklik();
            }
            else if (auto st = dynamic_cast<Star*>(sek)) {
                tip = 'S';
                gen = st->getGenislik();
                yuk = st->getYukseklik();
            }

            dosya << tip << " "
                  << x << " " << y << " "
                  << gen << " " << yuk << " "
                  << kar << " " << z << "\n";

            s = s->sonraki;
        }

        d = d->sonraki;
    }
}


void Uygulama::rastgeleOlustur() {
    // Örnekteki gibi 6 liste: 2, 8, 1, 9, 6, 10
    AnaListeDugum* d1 = anaListe.dugumEkle(2);
    AnaListeDugum* d2 = anaListe.dugumEkle(8);
    AnaListeDugum* d3 = anaListe.dugumEkle(1);
    AnaListeDugum* d4 = anaListe.dugumEkle(9);
    AnaListeDugum* d5 = anaListe.dugumEkle(6);
    AnaListeDugum* d6 = anaListe.dugumEkle(10);

    // ilk aktif olan liste: 2
    aktifDugum = d1;

    // ================== LİSTE 2 ==================
    // Sağ tarafta büyük "o" üçgeni, içinde # tabakası
    d1->sekiller.sekilEkle(new Triangle(50, 5, 17, 7, 'o', 1));   // büyük o üçgeni
    d1->sekiller.sekilEkle(new Rectangle(48, 9, 9, 2, '#', 2));   // içte # satiri
    d1->sekiller.sekilEkle(new Rectangle(48, 11, 11, 1, 'o', 3)); // altta o tabakası

    // ================== LİSTE 8 ==================
    // Üst tarafta yatay bloklar ve küçük üçgen
    d2->sekiller.sekilEkle(new Rectangle(40, 2, 25, 2, '#', 1));  // uzun # blok
    d2->sekiller.sekilEkle(new Rectangle(42, 5, 20, 2, '#', 2));  // biraz aşağısında
    d2->sekiller.sekilEkle(new Triangle(50, 9, 7, 3, '*', 3));    // küçük * üçgeni

    // ================== LİSTE 1 ==================
    // Ortalarda üst üste küçük şekiller
    d3->sekiller.sekilEkle(new Triangle(35, 7, 5, 3, '*', 1));    // küçük üçgen
    d3->sekiller.sekilEkle(new Triangle(37, 11, 5, 3, '*', 2));   // biraz aşağıda
    d3->sekiller.sekilEkle(new Star(36, 10, 1, 1, '+', 3));       // ortasında yıldız

    // ================== LİSTE 9 ==================
    // Aşağıya yakın kare blok ve dalga satırı
    d4->sekiller.sekilEkle(new Rectangle(42, 13, 10, 4, '#', 1)); // kare blok
    d4->sekiller.sekilEkle(new Rectangle(42, 18, 14, 1, '~', 2)); // dalga çizgisi ~

    // ================== LİSTE 6 ==================
    // Burada sahne daha dolu: büyük # blok + + üçgen + küçük * şekilleri
    d5->sekiller.sekilEkle(new Rectangle(43, 11, 11, 5, '#', 1)); // büyük # kare bloğu
    d5->sekiller.sekilEkle(new Triangle(60, 12, 11, 6, '+', 2));  // sağ altta büyük + üçgen
    d5->sekiller.sekilEkle(new Triangle(35, 7, 7, 4, '*', 3));    // solda * üçgen
    d5->sekiller.sekilEkle(new Star(37, 13, 1, 1, '*', 4));       // etrafa serpiştirilmiş *

    // ================== LİSTE 10 ==================
    // Üstte küçük * üçgen, ortada + şeritleri, altta ooooo bloğu
    d6->sekiller.sekilEkle(new Triangle(50, 4, 7, 4, '*', 1));    // üstte * üçgen
    d6->sekiller.sekilEkle(new Rectangle(45, 9, 20, 3, '+', 2));  // ortada uzun + blok
    d6->sekiller.sekilEkle(new Rectangle(55, 14, 15, 3, 'o', 3)); // sağ altta oooooo blok
    d6->sekiller.sekilEkle(new Rectangle(58, 18, 10, 1, '~', 4)); // en altta ~ çizgisi
}
