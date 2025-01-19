#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <conio.h>
#include <windows.h>

using namespace std;

struct Cicek {
    char isim[50];
    int stok;
    float fiyat;
};

void CicekEkle();
void CicekListele();
void CicekAra();
void CicekSil();
void SatisYap();

Cicek cicek;

int main() {
setlocale(LC_ALL, "Turkish"); 
    
    char secim;
    do {
        system("cls");
        cout << "|------ Çiçekçi Otomasyonu ------|" << endl;
        cout << "| 1 - Çiçek Ekle                 |" << endl;
        cout << "| 2 - Çiçekleri Listele          |" << endl;
        cout << "| 3 - Çiçek Ara                  |" << endl;
        cout << "| 4 - Çiçek Sil                  |" << endl;
        cout << "| 5 - Satýþ Yap                  |" << endl;
        cout << "| 0 - Çýkýþ                      |" << endl;
        cout << "|--------------------------------|" << endl;
        cout << "Seçiminiz: ";
        cin >> secim;

        switch (secim) {
            case '1':
                CicekEkle();
                break;
            case '2':
                CicekListele();
                break;
            case '3':
                CicekAra();
                break;
            case '4':
                CicekSil();
                break;
            case '5':
                SatisYap();
                break;
        }

    } while (secim != '0');

    return 0;
}

void CicekEkle() {
    ofstream yaz("cicekler.dat", ios::binary | ios::app);
    char devam;
    do {
        cout << "Çiçek ismi: ";
        cin.ignore();
        cin.getline(cicek.isim, 50);
        cout << "Stok miktarý: ";
        cin >> cicek.stok;
        cout << "Fiyat (?): ";
        cin >> cicek.fiyat;

        yaz.write((char*)&cicek, sizeof(cicek));

        cout << "Baþka çiçek eklemek ister misiniz? (E/H): ";
        cin >> devam;

    } while (devam == 'E' || devam == 'e');

    yaz.close();
    cout << "Çiçek(ler) baþarýyla eklendi!" << endl;
    system("pause");
}

void CicekListele() {
    ifstream oku("cicekler.dat", ios::binary);
    if (!oku) {
        cout << "Çiçek listesi boþ. Önce çiçek ekleyin." << endl;
        system("pause");
        return;
    }

    int sayac = 0;
    while (oku.read((char*)&cicek, sizeof(cicek))) {
        sayac++;
        cout << "\n" << sayac << ". Çiçek:" << endl;
        cout << "Ýsim: " << cicek.isim << endl;
        cout << "Stok: " << cicek.stok << endl;
        cout << "Fiyat: " << fixed << setprecision(2) << cicek.fiyat << " ?" << endl;
    }

    oku.close();
    system("pause");
}

void CicekAra() {
    ifstream oku("cicekler.dat", ios::binary);
    if (!oku) {
        cout << "Kayýtlý çiçek yok!" << endl;
        system("pause");
        return;
    }

    char isim[50];
    cout << "Aranacak çiçek ismini giriniz: ";
    cin.ignore();
    cin.getline(isim, 50);

    bool bulundu = false;
    while (oku.read((char*)&cicek, sizeof(cicek))) {
        if (strcmp(cicek.isim, isim) == 0) {
            bulundu = true;
            cout << "\nÇiçek Bulundu:" << endl;
            cout << "Ýsim: " << cicek.isim << endl;
            cout << "Stok: " << cicek.stok << endl;
            cout << "Fiyat: " << fixed << setprecision(2) << cicek.fiyat << " ?" << endl;
        }
    }

    if (!bulundu) {
        cout << "Çiçek bulunamadý!" << endl;
    }

    oku.close();
    system("pause");
}

void CicekSil() {
    ifstream oku("cicekler.dat", ios::binary);
    if (!oku) {
        cout << "Kayýtlý çiçek yok!" << endl;
        system("pause");
        return;
    }

    char isim[50];
    cout << "Silinecek çiçek ismini giriniz: ";
    cin.ignore();
    cin.getline(isim, 50);

    ofstream yaz("temp.dat", ios::binary);
    bool bulundu = false;

    while (oku.read((char*)&cicek, sizeof(cicek))) {
        if (strcmp(cicek.isim, isim) == 0) {
            bulundu = true;
            cout << "Çiçek silindi: " << cicek.isim << endl;
        } else {
            yaz.write((char*)&cicek, sizeof(cicek));
        }
    }

    oku.close();
    yaz.close();

    remove("cicekler.dat");
    rename("temp.dat", "cicekler.dat");

    if (!bulundu) {
        cout << "Çiçek bulunamadý!" << endl;
    }

    system("pause");
}

void SatisYap() {
    fstream dosya("cicekler.dat", ios::binary | ios::in | ios::out);
    if (!dosya) {
        cout << "Kayýtlý çiçek yok!" << endl;
        system("pause");
        return;
    }

    char isim[50];
    cout << "Satýlacak çiçek ismini giriniz: ";
    cin.ignore();
    cin.getline(isim, 50);

    int adet;
    cout << "Satýþ miktarý: ";
    cin >> adet;

    bool bulundu = false;
    int pozisyon;
    while (!bulundu && dosya.read((char*)&cicek, sizeof(cicek))) {
        if (strcmp(cicek.isim, isim) == 0) {
            bulundu = true;
            pozisyon = dosya.tellg();
            if (cicek.stok >= adet) {
                cicek.stok -= adet;
                cout << "Satýþ baþarýlý! Kalan stok: " << cicek.stok << endl;
                dosya.seekp(pozisyon - sizeof(cicek));
                dosya.write((char*)&cicek, sizeof(cicek));
            } else {
                cout << "Yetersiz stok!" << endl;
            }
        }
    }

    if (!bulundu) {
        cout << "Çiçek bulunamadý!" << endl;
    }

    dosya.close();
    system("pause");
}

