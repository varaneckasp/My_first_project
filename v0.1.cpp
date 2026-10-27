#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <chrono>
#include "studentas.h"
#include "funkcijos.h"
using std::string;
using std::vector;
template <typename T>
double matuotiStrategija(const T& pradineGrupe, int strategija, int vertinimo_pasirinkimas) {

    double laikuSuma = 0;
    volatile double patikra = 0;

    for (int i = 0; i < 5; i++) {
        T grupe = pradineGrupe;
        T vargsiukai;
        T kietiakai;

        auto pradzia = std::chrono::steady_clock::now();

        if (strategija == 1) {
            skirstytiStudentus(grupe, vargsiukai, kietiakai,
                              vertinimo_pasirinkimas);
        }
        else if (strategija == 2) {
            skirstytiStudentus2(grupe, vargsiukai,
                               vertinimo_pasirinkimas);
        }
        else if (strategija == 3) {
            skirstytiStudentus3(grupe, vargsiukai,
                               vertinimo_pasirinkimas);
        }

        auto pabaiga = std::chrono::steady_clock::now();

        std::chrono::duration<double> laikas = pabaiga - pradzia;
        laikuSuma += laikas.count();
        for (const studentas& A : vargsiukai) {
            patikra += A.galutinis;
        }
    }

    return laikuSuma / 5;
}
template <typename T> void vykdytiPrograma(){
    T grupe;
    T vargsiukai;
    T kietiakai;
    srand(time(0));
    std::chrono::duration<double> skirtumas;
    studentas A;
    size_t studentu_skaicius = 0;
    std::cout << "Kaip norite ivesti studentu duomenis? rankiniu budu/generuoti(1)? Ar nuskaityti is failo(2)?" << std::endl;
    std::cout << "Ar norite sugeneruoti atsitiktinius failus?(3) " << std::endl;
    int failo_pasirinkimas;
    std::cin >> failo_pasirinkimas;
    if (failo_pasirinkimas == 1 ) {
        std::cout << "Iveskite studentu skaiciu: ";
        int n;
        std::cin >> n;
        std::cin.ignore();

        for (int i = 0; i < n; i++) {
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
                std::string ivestis;
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

            std::cout << "Ar norite ivesti ranka (1) ar atsitiktini egzamino rezultata (2)? ";
            int pasirinkimas_egz;
            std::cin >> pasirinkimas_egz;
            if (pasirinkimas_egz == 2) {
                A.exam = rand() % 10 + 1;
            } else {
                std::cout << "Iveskite studento egzamino rezultata: ";
                std::cin >> A.exam;
            }
            skaiciuotiGalutini(A);
            grupe.push_back(A);
            std::cout << "Studento adresas atmintyje: " << &grupe.back() << '\n';
        }
    } else if (failo_pasirinkimas == 2) {
        std::cout<< "Kuri faila norite nuskaityti?"<< std::endl;
        std::cout<< "1 - studentai1000.txt" << std::endl;
        std::cout<< "2 - studentai10000.txt" << std::endl;
        std::cout<< "3 - studentai100000.txt" << std::endl;
        std::cout<< "4 - studentai1000000.txt" << std::endl;
        std::cout<< "5 - studentai10000000.txt" << std::endl;
        std::cout<< "6 - ivesti savo failo pavadinimas:" << std::endl;
        int failo_pav_pasirinkimas;
        string failo_pavadinimas;
        std::cin >> failo_pav_pasirinkimas;
        if (failo_pav_pasirinkimas == 1) {
            failo_pavadinimas = "studentai1000.txt";
            studentu_skaicius = 1000;
        } else if (failo_pav_pasirinkimas == 2) {
            failo_pavadinimas = "studentai10000.txt";
            studentu_skaicius = 10000;
        } else if (failo_pav_pasirinkimas == 3) {
            failo_pavadinimas = "studentai100000.txt";
            studentu_skaicius = 100000;
        } else if (failo_pav_pasirinkimas == 4) {
            failo_pavadinimas = "studentai1000000.txt";
            studentu_skaicius = 1000000;
        } else if (failo_pav_pasirinkimas == 5) {
            failo_pavadinimas = "studentai10000000.txt";
            studentu_skaicius = 10000000;
        } else if (failo_pav_pasirinkimas == 6) {
            std::cout << "Iveskite savo failo pavadinima: ";
            std::cin >> failo_pavadinimas;
        }
        else {
            std::cout << "Neteisingas pasirinkimas!" << std::endl;
            return;
        }
        rezervuotiVieta(grupe, studentu_skaicius);
        auto laikas_pradzia = std::chrono::high_resolution_clock::now();
        if(!skaitytiFaila(failo_pavadinimas, grupe)) {
        return;
        }
        auto laikas_pabaiga = std::chrono::high_resolution_clock::now();
        skirtumas = laikas_pabaiga - laikas_pradzia;
        std::cout << "Failas " << failo_pavadinimas << " nuskaitytas per " << skirtumas.count() << " sekundziu." << std::endl;
    }
    else {
        std::cout << "Kiek studentu norite sugeneruoti?" << std::endl;
        std::cout << "1 - 1000 studentu" << std::endl;
        std::cout << "2 - 10000 studentu" << std::endl;
        std::cout << "3 - 100000 studentu" << std::endl;
        std::cout << "4 - 1000000 studentu" << std::endl;
        std::cout << "5 - 10000000 studentu" << std::endl;
        int studentu_skaicius;
        std::cin >> studentu_skaicius;
        if (studentu_skaicius ==1) {
            auto laikas_pradzia = std::chrono::high_resolution_clock::now();
            atsitiktinis_sarasas("studentai1000.txt", 1000);
            auto laikas_pabaiga = std::chrono::high_resolution_clock::now();
            skirtumas = laikas_pabaiga - laikas_pradzia;
            std::cout << "Sugeneruotas failas studentai1000.txt per " << skirtumas.count() << " sekundziu." << std::endl;
        } else if (studentu_skaicius == 2) {
            auto laikas_pradzia = std::chrono::high_resolution_clock::now();
            atsitiktinis_sarasas("studentai10000.txt", 10000);
            auto laikas_pabaiga = std::chrono::high_resolution_clock::now();
            skirtumas = laikas_pabaiga - laikas_pradzia;
            std::cout << "Sugeneruotas failas studentai10000.txt per " << skirtumas.count() << " sekundziu." << std::endl;
        } else if (studentu_skaicius == 3) {
            auto laikas_pradzia = std::chrono::high_resolution_clock::now();
            atsitiktinis_sarasas("studentai100000.txt", 100000);
            auto laikas_pabaiga = std::chrono::high_resolution_clock::now();
            skirtumas = laikas_pabaiga - laikas_pradzia;
            std::cout << "Sugeneruotas failas studentai100000.txt per " << skirtumas.count() << " sekundziu." << std::endl;
        } else if (studentu_skaicius == 4) {
            auto laikas_pradzia = std::chrono::high_resolution_clock::now();
            atsitiktinis_sarasas("studentai1000000.txt", 1000000);
            auto laikas_pabaiga = std::chrono::high_resolution_clock::now();
            skirtumas = laikas_pabaiga - laikas_pradzia;
            std::cout << "Sugeneruotas failas studentai1000000.txt per " << skirtumas.count() << " sekundziu." << std::endl;
        } else if (studentu_skaicius == 5) {
            auto laikas_pradzia = std::chrono::high_resolution_clock::now();
            atsitiktinis_sarasas("studentai10000000.txt", 10000000);
            auto laikas_pabaiga = std::chrono::high_resolution_clock::now();
            skirtumas = laikas_pabaiga - laikas_pradzia;
            std::cout << "Sugeneruotas failas studentai10000000.txt per " << skirtumas.count() << " sekundziu." << std::endl;
        }
    }
    if (failo_pasirinkimas == 1 || failo_pasirinkimas == 2) {
        int vertinimo_pasirinkimas;
        std::cout << "Pagal ka norite rusiuoti studentus? (1 - mediana, 2 - vidurki)" << std::endl;
        std::cin >> vertinimo_pasirinkimas;
        int testavimo_pasirinkimas;

std::cout << "Ar norite atlikti automatini testavima? (1 - taip, 2 - ne): ";
std::cin >> testavimo_pasirinkimas;
if (testavimo_pasirinkimas == 1) {
    for (int i = 1; i <= 3; i++) {
        double vidurkis = matuotiStrategija(grupe, i, vertinimo_pasirinkimas);
        std::cout << i << " strategijos vidutinis laikas: " << vidurkis << " sekundziu." << std::endl;
    }
    return;
}
else if (testavimo_pasirinkimas != 2) {
    std::cout << "Neteisingas pasirinkimas!" << std::endl;
    return;
}
        int strategija;
        std::cout<<"Pasirinkite strategija: 1 - skirstyti studentus i dvi grupes, 2 - skirstyti studentus i viena grupe ir is jos istrinti vargsiukus, 3 - naudoti std::partition"<<std::endl;
        std::cin>>strategija;
        auto laikas_pradzia = std::chrono::high_resolution_clock::now();
        if(strategija == 1){
            skirstytiStudentus(grupe, vargsiukai, kietiakai, vertinimo_pasirinkimas);
        } else if(strategija == 2){
            skirstytiStudentus2(grupe, vargsiukai, vertinimo_pasirinkimas);
        } else if(strategija == 3){
            skirstytiStudentus3(grupe, vargsiukai, vertinimo_pasirinkimas);
        } else {
            std::cout << "Neteisingas pasirinkimas!" << std::endl;
            return;
        }
        auto laikas_pabaiga = std::chrono::high_resolution_clock::now();
        skirtumas = laikas_pabaiga - laikas_pradzia;
        std::cout << "Studentai suskirstyti i dvi grupes per " << skirtumas.count() << " sekundziu." << std::endl;
        std::cout << "Pagal ka norite rusiuoti studentus? (1 - vardas, 2 - pavarde, 3 - galutinis)" << std::endl;
        int rusiuoti_pasirinkimas;
        std::cin >> rusiuoti_pasirinkimas;
        auto laikas_pradzia2 = std::chrono::high_resolution_clock::now();
        rusiuotiStudentus(vargsiukai, rusiuoti_pasirinkimas);
        if (strategija == 1) {
            rusiuotiStudentus(kietiakai, rusiuoti_pasirinkimas);
        } else {
            rusiuotiStudentus(grupe, rusiuoti_pasirinkimas);
        }
        auto laikas_pabaiga2 = std::chrono::high_resolution_clock::now();
        skirtumas = laikas_pabaiga2 - laikas_pradzia2;
        std::cout << "Studentai surusiuoti pagal pasirinkta kriteriju per " << skirtumas.count() << " sekundziu." << std::endl;
        auto laikas_pradzia3 = std::chrono::high_resolution_clock::now();
        bool arRezultataiSurasyti;
        if (strategija == 1) {
            arRezultataiSurasyti = rasytiFailus(vargsiukai, kietiakai, vertinimo_pasirinkimas);
        } else if (strategija == 2 || strategija == 3) {
            arRezultataiSurasyti = rasytiFailus(vargsiukai, grupe, vertinimo_pasirinkimas);
        } else {
            std::cout<< "Nepavyko surasyti rezultatu!"<< '\n';
            return;
        }
        auto laikas_pabaiga3 = std::chrono::high_resolution_clock::now();
        skirtumas = laikas_pabaiga3 - laikas_pradzia3;
        std::cout << "Failu rasymas uztruko " << skirtumas.count() << " sekundziu." << std::endl;
    }
}
int main() 
{
    int pasirinkimas;
    std::cout << "Pasirinkite konteinerio tipa: (1 - vector, 2 - list)" << std::endl;
    std::cin >> pasirinkimas;
    if (pasirinkimas == 1) {
        vykdytiPrograma<std::vector<studentas>>();
    } else if (pasirinkimas == 2) {
        vykdytiPrograma<std::list<studentas>>();
    } else {
        std::cout << "Neteisingas pasirinkimas!" << std::endl;
        return 1;
    }
}
