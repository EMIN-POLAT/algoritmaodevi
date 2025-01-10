#include <iostream>
#include <string>
using namespace std;


struct Kumas {
    string iplikTipi;
    double dm2Agirlik;
    string dokumaTipi;
    string renk;
    int miktar;
};


struct Iskelet {
    string malzeme;
    string birlestirme;
    string tarz;
    string boyut;
    int miktar;
};


struct Mobilya {
    Kumas kaplama; 
    Iskelet malzeme; 
    int fiyat;
    int adet;
};


void listele(const Mobilya& mobilya, int index) {
    cout << "Mobilya #" << index + 1 << ":\n";
    cout << "Kaplama Bilgileri:\n";
    cout << "  Iplik Tipi: " << mobilya.kaplama.iplikTipi << "\n";
    cout << "  DM2 Agirlik: " << mobilya.kaplama.dm2Agirlik << "\n";
    cout << "  Dokuma Tipi: " << mobilya.kaplama.dokumaTipi << "\n";
    cout << "  Renk: " << mobilya.kaplama.renk << "\n";
    cout << "  Miktar: " << mobilya.kaplama.miktar << "\n";
    cout << "Malzeme Bilgileri:\n";
    cout << "  Malzeme: " << mobilya.malzeme.malzeme << "\n";
    cout << "  Birleþtirme: " << mobilya.malzeme.birlestirme << "\n";
    cout << "  Tarz: " << mobilya.malzeme.tarz << "\n";
    cout << "  Boyut: " << mobilya.malzeme.boyut << "\n";
    cout << "  Miktar: " << mobilya.malzeme.miktar << "\n";
    cout << "Fiyat: " << mobilya.fiyat << " TL\n";
    cout << "Adet: " << mobilya.adet << "\n";
    cout << "----------------------\n";
}

int main() {
    Mobilya mobilyalar[10];
    int toplamFiyat = 0;

    
    for (int i = 0; i < 10; ++i) {
        cout << "Mobilya #" << i + 1 << " bilgilerini girin:\n";

        cout << "Kaplama Bilgileri:\n";
        cout << "  Iplik Tipi: ";
        cin >> mobilyalar[i].kaplama.iplikTipi;
        cout << "  DM2 Agirlik: ";
        cin >> mobilyalar[i].kaplama.dm2Agirlik;
        cout << "  Dokuma Tipi: ";
        cin >> mobilyalar[i].kaplama.dokumaTipi;
        cout << "  Renk: ";
        cin >> mobilyalar[i].kaplama.renk;
        cout << "  Miktar: ";
        cin >> mobilyalar[i].kaplama.miktar;

        cout << "Malzeme Bilgileri:\n";
        cout << "  Malzeme: ";
        cin >> mobilyalar[i].malzeme.malzeme;
        cout << "  Birleþtirme: ";
        cin >> mobilyalar[i].malzeme.birlestirme;
        cout << "  Tarz: ";
        cin >> mobilyalar[i].malzeme.tarz;
        cout << "  Boyut: ";
        cin >> mobilyalar[i].malzeme.boyut;
        cout << "  Miktar: ";
        cin >> mobilyalar[i].malzeme.miktar;

        cout << "Fiyat: ";
        cin >> mobilyalar[i].fiyat;
        cout << "Adet: ";
        cin >> mobilyalar[i].adet;

        toplamFiyat += mobilyalar[i].fiyat * mobilyalar[i].adet; 
        cout << "----------------------\n";
    }

    
    cout << "\nTüm Mobilya Bilgileri:\n";
    for (int i = 0; i < 10; ++i) {
        listele(mobilyalar[i], i);
    }

  
    cout << "10 ürünün toplam fiyatý: " << toplamFiyat << " TL\n";

    return 0;
}


