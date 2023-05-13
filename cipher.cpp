#include <iostream>
#include <string>
#include <algorithm>

// Uçtan uca şifreleme sınıfı
class UcTanUcaSifreleme {
private:
    std::string anahtar;

public:
    UcTanUcaSifreleme(const std::string& anahtar) : anahtar(anahtar) {}

    std::string Sifrele(const std::string& metin) {
        std::string sifreliMetin = metin;

        for (char& c : sifreliMetin) {
            c += anahtar.length();
        }

        return sifreliMetin;
    }

    std::string Coz(const std::string& sifreliMetin) {
        std::string orijinalMetin = sifreliMetin;

        for (char& c : orijinalMetin) {
            c -= anahtar.length();
        }

        return orijinalMetin;
    }
};

int main() {
    std::string anahtar;
    std::string metin;

    std::cout << "Uctan Uca Sifreleme Uygulamasi" << std::endl;

    // Anahtarın alınması
    std::cout << "Sifreleme icin bir anahtar girin: ";
    std::getline(std::cin, anahtar);

    // Uçtan uca şifreleme sınıfının oluşturulması
    UcTanUcaSifreleme sifreleme(anahtar);

    // Kullanıcı menüsü
    int secim = 0;
    while (secim != 3) {
        std::cout << std::endl;
        std::cout << "1. Metni Sifrele" << std::endl;
        std::cout << "2. Sifreli Metni Coz" << std::endl;
        std::cout << "3. Cikis" << std::endl;
        std::cout << "Seciminizi yapin (1-3): ";
        std::cin >> secim;
        std::cin.ignore();

        switch (secim) {
            case 1: {
                std::cout << "Sifrelenecek metni girin: ";
                std::getline(std::cin, metin);
                std::string sifreliMetin = sifreleme.Sifrele(metin);
                std::cout << "Sifreli metin: " << sifreliMetin << std::endl;
                break;
            }
            case 2: {
                std::cout << "Cozulecek sifreli metni girin: ";
                std::getline(std::cin, metin);
                std::string orijinalMetin = sifreleme.Coz(metin);
                std::cout << "Orijinal metin: " << orijinalMetin << std::endl;
                break;
            }
            case 3: {
                std::cout << "Programdan cikiliyor..." << std::endl;
                break;
            }
            default: {
                std::cout << "Gecersiz secim! Tekrar deneyin." << std::endl;
                break;
            }
        }
    }

    return 0;
}
