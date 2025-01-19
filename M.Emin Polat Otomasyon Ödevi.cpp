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
        cout << "|------ �i�ek�i Otomasyonu ------|" << endl;
        cout << "| 1 - �i�ek Ekle                 |" << endl;
        cout << "| 2 - �i�ekleri Listele          |" << endl;
        cout << "| 3 - �i�ek Ara                  |" << endl;
        cout << "| 4 - �i�ek Sil                  |" << endl;
        cout << "| 5 - Sat�� Yap                  |" << endl;
        cout << "| 0 - ��k��                      |" << endl;
        cout << "|--------------------------------|" << endl;
        cout << "Se�iminiz: ";
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
        cout << "�i�ek ismi: ";
        cin.ignore();
        cin.getline(cicek.isim, 50);
        cout << "Stok miktar�: ";
        cin >> cicek.stok;
        cout << "Fiyat (?): ";
        cin >> cicek.fiyat;

        yaz.write((char*)&cicek, sizeof(cicek));

        cout << "Ba�ka �i�ek eklemek ister misiniz? (E/H): ";
        cin >> devam;

    } while (devam == 'E' || devam == 'e');

    yaz.close();
    cout << "�i�ek(ler) ba�ar�yla eklendi!" << endl;
    system("pause");
}

void CicekListele() {
    ifstream oku("cicekler.dat", ios::binary);
    if (!oku) {
        cout << "�i�ek listesi bo�. �nce �i�ek ekleyin." << endl;
        system("pause");
        return;
    }

    int sayac = 0;
    while (oku.read((char*)&cicek, sizeof(cicek))) {
        sayac++;
        cout << "\n" << sayac << ". �i�ek:" << endl;
        cout << "�sim: " << cicek.isim << endl;
        cout << "Stok: " << cicek.stok << endl;
        cout << "Fiyat: " << fixed << setprecision(2) << cicek.fiyat << " ?" << endl;
    }

    oku.close();
    system("pause");
}

void CicekAra() {
    ifstream oku("cicekler.dat", ios::binary);
    if (!oku) {
        cout << "Kay�tl� �i�ek yok!" << endl;
        system("pause");
        return;
    }

    char isim[50];
    cout << "Aranacak �i�ek ismini giriniz: ";
    cin.ignore();
    cin.getline(isim, 50);

    bool bulundu = false;
    while (oku.read((char*)&cicek, sizeof(cicek))) {
        if (strcmp(cicek.isim, isim) == 0) {
            bulundu = true;
            cout << "\n�i�ek Bulundu:" << endl;
            cout << "�sim: " << cicek.isim << endl;
            cout << "Stok: " << cicek.stok << endl;
            cout << "Fiyat: " << fixed << setprecision(2) << cicek.fiyat << " ?" << endl;
        }
    }

    if (!bulundu) {
        cout << "�i�ek bulunamad�!" << endl;
    }

    oku.close();
    system("pause");
}

void CicekSil() {
    ifstream oku("cicekler.dat", ios::binary);
    if (!oku) {
        cout << "Kay�tl� �i�ek yok!" << endl;
        system("pause");
        return;
    }

    char isim[50];
    cout << "Silinecek �i�ek ismini giriniz: ";
    cin.ignore();
    cin.getline(isim, 50);

    ofstream yaz("temp.dat", ios::binary);
    bool bulundu = false;

    while (oku.read((char*)&cicek, sizeof(cicek))) {
        if (strcmp(cicek.isim, isim) == 0) {
            bulundu = true;
            cout << "�i�ek silindi: " << cicek.isim << endl;
        } else {
            yaz.write((char*)&cicek, sizeof(cicek));
        }
    }

    oku.close();
    yaz.close();

    remove("cicekler.dat");
    rename("temp.dat", "cicekler.dat");

    if (!bulundu) {
        cout << "�i�ek bulunamad�!" << endl;
    }

    system("pause");
}

void SatisYap() {
    fstream dosya("cicekler.dat", ios::binary | ios::in | ios::out);
    if (!dosya) {
        cout << "Kay�tl� �i�ek yok!" << endl;
        system("pause");
        return;
    }

    char isim[50];
    cout << "Sat�lacak �i�ek ismini giriniz: ";
    cin.ignore();
    cin.getline(isim, 50);

    int adet;
    cout << "Sat�� miktar�: ";
    cin >> adet;

    bool bulundu = false;
    int pozisyon;
    while (!bulundu && dosya.read((char*)&cicek, sizeof(cicek))) {
        if (strcmp(cicek.isim, isim) == 0) {
            bulundu = true;
            pozisyon = dosya.tellg();
            if (cicek.stok >= adet) {
                cicek.stok -= adet;
                cout << "Sat�� ba�ar�l�! Kalan stok: " << cicek.stok << endl;
                dosya.seekp(pozisyon - sizeof(cicek));
                dosya.write((char*)&cicek, sizeof(cicek));
            } else {
                cout << "Yetersiz stok!" << endl;
            }
        }
    }

    if (!bulundu) {
        cout << "�i�ek bulunamad�!" << endl;
    }

    dosya.close();
    system("pause");
}

