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
    char garanti; // 'e' veya 'h' olacak þekilde
    float ucret;
    Kisi gonderici;
    Kisi alici;
};

struct Kurye {
    string adi_soyadi;
    string telefon_no;
};

void gonderiBilgisiYazdir(const Gonderi& gonderi) {
    cout << "Gönderi No: " << gonderi.gonderi_no << endl;
    cout << "Aðýrlýk: " << gonderi.agirlik << " kg" << endl;
    cout << "Hacim: " << gonderi.hacim << " m^3" << endl;
    cout << "Garanti: " << (gonderi.garanti == 'e' ? "Evet" : "Hayýr") << endl;
    cout << "Ücret: " << gonderi.ucret << " TL" << endl;
    cout << "Gönderici: " << gonderi.gonderici.adi_soyadi << ", Adres: " << gonderi.gonderici.adres << ", Telefon: " << gonderi.gonderici.telefon_no << endl;
    cout << "Alýcý: " << gonderi.alici.adi_soyadi << ", Adres: " << gonderi.alici.adres << ", Telefon: " << gonderi.alici.telefon_no << endl;
    cout << "----------------------------" << endl;
}

int main() {
    vector<Gonderi> gonderiler(5);
    Kurye kurye = {"Mehmet Yýlmaz", "555-1234"};

    // Gönderi bilgilerini doldur
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

    // Kurucu tanýmlýyoruz
    Kisi(string ad = "", string adr = "", string tel = "")
        : adiSoyadi(ad), adres(adr), telefonNo(tel) {}
};

       
        gonderiler[i].alici = {"Alýcý Adý " + to_string(i+1), "Alýcý Adresi " + to_string(i+1), "555-100" + to_string(i+1)};
    }

    cout << "Kurye: " << kurye.adi_soyadi << ", Telefon: " << kurye.telefon_no << endl;
    cout << "----------------------------" << endl;

    // Gönderi bilgilerini yazdýr
    for (const auto& gonderi : gonderiler) {
        gonderiBilgisiYazdir(gonderi);
    }

    return 0;
}


