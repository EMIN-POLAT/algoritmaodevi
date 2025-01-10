#include <iostream>
#include <string>

using namespace std;


struct Otomobil {
    string marka;
    string model;
    int yil;
    char yakit; 
    int km;
    double fiyat;
};


void listele(const Otomobil& arac, const string& tip) {
    cout << tip << " Arac:\n";
    cout << "Marka: " << arac.marka << "\n";
    cout << "Model: " << arac.model << "\n";
    cout << "Yil: " << arac.yil << "\n";
    cout << "Yakit: " << arac.yakit << "\n";
    cout << "KM: " << arac.km << "\n";
    cout << "Fiyat: " << arac.fiyat << " TL\n";
    cout << "----------------------\n";
}

int main() {
    
    Otomobil binek, suv, ticari;

    
    binek.marka = "Toyota";
    binek.model = "Corolla";
    binek.yil = 2020;
    binek.yakit = 'B'; // Benzin
    binek.km = 45000;
    binek.fiyat = 450000.50;

    
    suv.marka = "Nissan";
    suv.model = "X-Trail";
    suv.yil = 2021;
    suv.yakit = 'D'; 
    suv.km = 30000;
    suv.fiyat = 700000.75;

    
    ticari.marka = "Ford";
    ticari.model = "Transit";
    ticari.yil = 2019;
    ticari.yakit = 'D'; 
    ticari.km = 120000;
    ticari.fiyat = 550000.00;

    
    listele(binek, "Binek");
    listele(suv, "SUV");
    listele(ticari, "Ticari");

    return 0;
}

