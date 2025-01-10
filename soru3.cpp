#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Kisi {
    string adi_soyadi;
    string adres;
    string telefon_no;
};

struct Gonderi {
    int gonderi_no;
    float agirlik;
    float hacim;
    char garanti; // 'e' veya 'h' olacak �ekilde
    float ucret;
    Kisi gonderici;
    Kisi alici;
};

struct Kurye {
    string adi_soyadi;
    string telefon_no;
};

void gonderiBilgisiYazdir(const Gonderi& gonderi) {
    cout << "G�nderi No: " << gonderi.gonderi_no << endl;
    cout << "A��rl�k: " << gonderi.agirlik << " kg" << endl;
    cout << "Hacim: " << gonderi.hacim << " m^3" << endl;
    cout << "Garanti: " << (gonderi.garanti == 'e' ? "Evet" : "Hay�r") << endl;
    cout << "�cret: " << gonderi.ucret << " TL" << endl;
    cout << "G�nderici: " << gonderi.gonderici.adi_soyadi << ", Adres: " << gonderi.gonderici.adres << ", Telefon: " << gonderi.gonderici.telefon_no << endl;
    cout << "Al�c�: " << gonderi.alici.adi_soyadi << ", Adres: " << gonderi.alici.adres << ", Telefon: " << gonderi.alici.telefon_no << endl;
    cout << "----------------------------" << endl;
}

int main() {
    vector<Gonderi> gonderiler(5);
    Kurye kurye = {"Mehmet Y�lmaz", "555-1234"};

    // G�nderi bilgilerini doldur
    for (int i = 0; i < 5; i++) {
        gonderiler[i].gonderi_no = i + 1;
        gonderiler[i].agirlik = (i + 1) * 1.5;
        gonderiler[i].hacim = (i + 1) * 0.2;
        gonderiler[i].garanti = (i % 2 == 0) ? 'e' : 'h';
        gonderiler[i].ucret = (i + 1) * 10.0;

class Kisi {
public:
    string adiSoyadi;
    string adres;
    string telefonNo;

    // Kurucu tan�ml�yoruz
    Kisi(string ad = "", string adr = "", string tel = "")
        : adiSoyadi(ad), adres(adr), telefonNo(tel) {}
};

       
        gonderiler[i].alici = {"Al�c� Ad� " + to_string(i+1), "Al�c� Adresi " + to_string(i+1), "555-100" + to_string(i+1)};
    }

    cout << "Kurye: " << kurye.adi_soyadi << ", Telefon: " << kurye.telefon_no << endl;
    cout << "----------------------------" << endl;

    // G�nderi bilgilerini yazd�r
    for (const auto& gonderi : gonderiler) {
        gonderiBilgisiYazdir(gonderi);
    }

    return 0;
}


