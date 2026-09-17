#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <algorithm>
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
    bool palygintiVardus(const studentas &a, const studentas &b) {
        return a.vardas < b.vardas;
    }
int main() 
{
    srand(time(0));
    vector<studentas> grupe;
    studentas A;
    std::cout << "Kaip norite ivesti studentu duomenis? rankiniu budu/generuoti(1)? Ar nuskaityti is failo(2)? ";
    int failo_pasirinkimas;
    std::cin >> failo_pasirinkimas;
    if (failo_pasirinkimas == 1 ) {

    std::cout << "Iveskite studentu skaiciu: ";
    int n;
    std::cin >> n;
    std::cin.ignore();
    for(int i = 0; i < n; i++) {
        std::cout << "Iveskite varda ir pavarde per tarpa: ";
        std::cin >> A.vardas >> A.pavarde;
        std::cout << "Ar pazymius ivesite ranka (1) ar generuosite atsitiktinius pazymius (2)? ";
        int pasirinkimas;
        std::cin >> pasirinkimas;
        if (pasirinkimas == 2) {
            int kiek_pazymiu = rand() % 10 + 1;
            A.pazymiai.clear();
            for (int j = 0; j < kiek_pazymiu; j++) {
                int pazimys = rand() % 10 + 1;
                A.pazymiai.push_back(pazimys);
            }
        } else {
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
    }
    std::cout <<"Ar norite ivesti ranka (1) ar atsitiktini egzamino rezultata (2)? ";
    int pasirinkimas_egz;
    std::cin >> pasirinkimas_egz;
    if (pasirinkimas_egz == 2) {
        A.exam = rand() % 10 + 1;
    } else {
        std::cout << "Iveskite studento egzamino rezultata: ";
        std::cin >> A.exam;
    }
    
    double suma = 0;
    for (int i = 0; i < A.pazymiai.size(); i++) {
        suma += A.pazymiai[i];
    }
    double vidurkis = suma / A.pazymiai.size();
     double mediana;
     std::sort(A.pazymiai.begin(), A.pazymiai.end());
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
    }
    else {
        std::ifstream fd("studentai10000.txt");
        if (!fd.is_open()) {
            std::cout << "Nepavyko atidaryti failo!" << std::endl;
            return 1;
        }
        std::string eilute;
        std::getline(fd, eilute);
        while(std::getline(fd,eilute)) {
            std::stringstream ss(eilute);
            studentas A;
            ss >> A.vardas >> A.pavarde;
            int pazymys;
            while (ss >> pazymys) {
                A.pazymiai.push_back(pazymys);
            }
                A.exam = A.pazymiai.back();
                A.pazymiai.pop_back();
                double suma=0;
                for (int i = 0; i < A.pazymiai.size(); i++) {
                    suma += A.pazymiai[i];
                }
                double vidurkis = suma / A.pazymiai.size();
                std::sort(A.pazymiai.begin(), A.pazymiai.end());
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
    }
    std::cout << "Kokio isvedimo tipa norite matyti? (1 - vidurkis, 2 - mediana, 3 - abu): ";
    int isvedimo_tipas;
    std::cin >> isvedimo_tipas;
    std::cout << std::left << std::setw(15) << "Vardas " << std::setw(15) << "Pavarde " ;
    if (isvedimo_tipas == 1 || isvedimo_tipas == 3) {
        std::cout << std::setw(20) << "Galutinis(Vid.) ";
    }
    if (isvedimo_tipas == 2 || isvedimo_tipas == 3) {
        std::cout << std::setw(20) << "Galutinis(Med.)";
    }
    std::cout << std::endl;
    std::cout << "---------------------------------------------------------------------\n";
    std::sort(grupe.begin(), grupe.end(), palygintiVardus);
    for (studentas B: grupe) {
        printas(B, isvedimo_tipas);
    }
    return 0;
}
void printas(studentas A, int isvedimo_tipas) {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << std::left << std::setw(15) << A.vardas << std::setw(15) << A.pavarde;
    if (isvedimo_tipas == 1 || isvedimo_tipas == 3) {
        std::cout <<std::left << std::setw(20) << A.galutinis;
    }
    if (isvedimo_tipas == 2 || isvedimo_tipas == 3) {
        std::cout <<std::left << std::setw(20) << A.galutinis_mediana;
    }
    std::cout << std::endl; 

}