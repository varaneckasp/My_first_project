#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using std::string;
using std::vector;


struct studentas{
    string vardas, pavarde;
    vector<int> pazymiai;
    int exam;
    double galutinis;
    double galutinis_mediana;
    };
    void printas(studentas A, int isvedimo_tipas);
int main() 
{
    vector<studentas> grupe;
    std::cout << "Iveskite studentu skaiciu: ";
    int n;
    std::cin >> n;
    std::cin.ignore();
    studentas A;
    for(int i = 0; i < n; i++) {
        std::cout << "Iveskite varda ir pavarde per tarpa: ";
        std::cin >> A.vardas >> A.pavarde;
        std::cout << "Iveskite studento namu darbu pazymius po viena spausdami enter, kai baigsite paspauskite enter nieko neivedus: ";
        std::cin.ignore();
    string ivestis;
    while (true) {
        std::getline(std::cin, ivestis);
        if (ivestis.empty()) {
            break;
        }
        try {
            int pazimys = std::stoi(ivestis);
            if (pazimys < 1 || pazimys > 10) {
                std::cout << "Ivestas netinkamas pazymys. Iveskite pazymi nuo 1 iki 10: ";
            } else {
                A.pazymiai.push_back(pazimys);
            }
        }
        catch (...) {
            std::cout << "Ivestas netinkamas pazymys. Iveskite pazymi nuo 1 iki 10: ";
        }
    }
    std::cout << "Iveskite studento egzamino rezultata: ";
    std::cin >> A.exam;
    double suma = 0;
    for (int i = 0; i < A.pazymiai.size(); i++) {
        suma += A.pazymiai[i];
    }
    double vidurkis = suma / A.pazymiai.size();
     double mediana;
    if (A.pazymiai.size() % 2 == 0) {
        int mid = A.pazymiai.size() / 2;
        mediana = (A.pazymiai[mid - 1] + A.pazymiai[mid]) / 2.0;
    } else {
        int mid = A.pazymiai.size() / 2;
        mediana = A.pazymiai[mid];
    }
    A.galutinis = 0.4 * vidurkis + 0.6 * A.exam;
    A.galutinis_mediana = 0.4 * mediana + 0.6 * A.exam;
    grupe.push_back(A);
    }
    
    std::cout << "Kokio isvedimo tipa norite matyti? (1 - vidurkis, 2 - mediana, 3 - abu): ";
    int isvedimo_tipas;
    std::cin >> isvedimo_tipas;
    std::cout << std::left << std::setw(15) << "Vardas " << std::setw(15) << "Pavarde " << std::setw(10) << "Galutinis (vidurkis) " << std::setw(10) << "Galutinis (mediana)" << std::endl;
    std::cout << "---------------------------------------------------------------------\n";
    for (studentas B: grupe) {
        printas(B, isvedimo_tipas);
    }
    return 0;
}
void printas(studentas A, int isvedimo_tipas) {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << std::left << std::setw(15) << A.vardas << std::setw(15) << A.pavarde;
    if (isvedimo_tipas == 1 || isvedimo_tipas == 3) {
        std::cout << std::setw(10) << A.galutinis;
    }
    if (isvedimo_tipas == 2 || isvedimo_tipas == 3) {
        std::cout << std::setw(10) << A.galutinis_mediana;
    }
    std::cout << std::endl; 

}