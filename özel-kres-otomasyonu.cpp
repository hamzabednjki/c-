#include <iostream>
#include <string>
#include <vector>
#include <fstream> 
using namespace std;

// Ögrenci yapisi
struct Ogrenci {
    int id;
    string isim;
    string soyisim;
    float notOrtalamasi;
};

// Fonksiyon prototipleri
void menuGoster();
void ogrenciEkle(vector<Ogrenci>&);
void ogrenciListele(const vector<Ogrenci>&);
void ogrenciGuncelle(vector<Ogrenci>&);
void ogrenciSil(vector<Ogrenci>&);
void raporOlustur(const vector<Ogrenci>&);

int main() {
    vector<Ogrenci> ogrenciler; // Ögrenci listesi
    int secim;

    do {
        menuGoster();
        cout << "Seçiminizi yapin: ";
        cin >> secim;

        switch (secim) {
            case 1:
                ogrenciEkle(ogrenciler);
                break;
            case 2:
                ogrenciListele(ogrenciler);
                break;
            case 3:
                ogrenciGuncelle(ogrenciler);
                break;
            case 4:
                ogrenciSil(ogrenciler);
                break;
            case 5:
                raporOlustur(ogrenciler);
                break;
            case 6:
                cout << "Programdan cikiliyor..." << endl;
                break;
            default:
                cout << "Gecersiz secim. Tekrar deneyin." << endl;
        }
    } while (secim != 6);

    return 0;
}

// Menü fonksiyonu
void menuGoster() {
    cout << "\n===== Ogrenci Yonetim Sistemi =====" << endl;
    cout << "1. Ogrenci Ekle" << endl;
    cout << "2. Ogrencileri Listele" << endl;
    cout << "3. Ogrenci Guncelle" << endl;
    cout << "4. Ogrenci Sil" << endl;
    cout << "5. Rapor Olustur" << endl;
    cout << "6. Cikis" << endl;
}

// Ögrenci ekleme fonksiyonu
void ogrenciEkle(vector<Ogrenci>& ogrenciler) {
    Ogrenci yeniOgrenci;
    cout << "Ogrenci ID: ";
    cin >> yeniOgrenci.id;
    cin.ignore();
    cout << "isim: ";
    getline(cin, yeniOgrenci.isim);
    cout << "Soyisim: ";
    getline(cin, yeniOgrenci.soyisim);
    cout << "Not Ortalamasi: ";
    cin >> yeniOgrenci.notOrtalamasi;

    ogrenciler.push_back(yeniOgrenci);
    cout << "Ogrenci basariyla eklendi!" << endl;
}

// Ögrencileri listeleme fonksiyonu
void ogrenciListele(const vector<Ogrenci>& ogrenciler) {
    if (ogrenciler.empty()) {
        cout << "Henuz eklenmis bir ögrenci yok." << endl;
        return;
    }

    cout << "\n===== Ögrenci Listesi =====" << endl;
    for (size_t i = 0; i < ogrenciler.size(); ++i) {
        cout << "ID: " << ogrenciler[i].id
             << ", isim: " << ogrenciler[i].isim
             << ", Soyisim: " << ogrenciler[i].soyisim
             << ", Not Ortalamasi: " << ogrenciler[i].notOrtalamasi << endl;
    }
}

// Öðrenci güncelleme fonksiyonu
void ogrenciGuncelle(vector<Ogrenci>& ogrenciler) {
    int id;
    cout << "Guncellenecek Ogrencinin ID'sini girin: ";
    cin >> id;

    for (size_t i = 0; i < ogrenciler.size(); ++i) {
        if (ogrenciler[i].id == id) {
            cout << "Yeni isim: ";
            cin.ignore();
            getline(cin, ogrenciler[i].isim);
            cout << "Yeni Soyisim: ";
            getline(cin, ogrenciler[i].soyisim);
            cout << "Yeni Not Ortalamasi: ";
            cin >> ogrenciler[i].notOrtalamasi;

            cout << "Ogrenci bilgileri guncellendi!" << endl;
            return;
        }
    }
    cout << "ID bulunamadi." << endl;
}

// Öðrenci silme fonksiyonu
void ogrenciSil(vector<Ogrenci>& ogrenciler) {
    int id;
    cout << "Silinecek Ogrencinin ID'sini girin: ";
    cin >> id;

    for (size_t i = 0; i < ogrenciler.size(); ++i) {
        if (ogrenciler[i].id == id) {
            ogrenciler.erase(ogrenciler.begin() + i);
            cout << "Ogrenci silindi!" << endl;
            return;
        }
    }
    cout << "ID bulunamadi." << endl;
}

// Rapor oluþturma fonksiyonu
void raporOlustur(const vector<Ogrenci>& ogrenciler) {
    ofstream dosya("ogrenci_raporu.txt");

    if (!dosya) {
        cout << "Rapor dosyasi olusturulamadi!" << endl;
        return;
    }

    dosya << "===== Ogrenci Raporu =====" << endl;
    for (size_t i = 0; i < ogrenciler.size(); ++i) {
        dosya << "ID: " << ogrenciler[i].id
              << ", isim: " << ogrenciler[i].isim
              << ", Soyisim: " << ogrenciler[i].soyisim
              << ", Not Ortalamasi: " << ogrenciler[i].notOrtalamasi << endl;
    }

    dosya.close();
    cout << "Rapor basariyla olusturuldu: ogrenci_raporu.txt" << endl;
}


