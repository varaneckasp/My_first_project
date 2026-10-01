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

int main() 
{
    srand(time(0));
    std::chrono::duration<double> skirtumas;

    vector<studentas> vargsiukai;
    vector<studentas> kietiakai;
    vector<studentas> grupe;
    studentas A;
    std::cout << "Kaip norite ivesti studentu duomenis? rankiniu budu/generuoti(1)? Ar nuskaityti is failo(2)?" << std::endl;
    std::cout << "Ar norite sugeneruoti atsitiktinius failus?(3) " << std::endl;
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
    else if (failo_pasirinkimas == 2) {
        std::cout<< "Kuri faila norite nuskaityti?"<< std::endl;
        std::cout<< "1 - studentai1000.txt" << std::endl;
        std::cout<< "2 - studentai10000.txt" << std::endl;
        std::cout<< "3 - studentai100000.txt" << std::endl;
        std::cout<< "4 - studentai1000000.txt" << std::endl;
        std::cout<< "5 - studentai10000000.txt" << std::endl;
        int failo_pav_pasirinkimas;
        string failo_pavadinimas;
        std::cin >> failo_pav_pasirinkimas;
        if (failo_pav_pasirinkimas == 1) {
            failo_pavadinimas = "studentai1000.txt";
        } else if (failo_pav_pasirinkimas == 2) {
            failo_pavadinimas = "studentai10000.txt";
        } else if (failo_pav_pasirinkimas == 3) {
            failo_pavadinimas = "studentai100000.txt";
        } else if (failo_pav_pasirinkimas == 4) {
            failo_pavadinimas = "studentai1000000.txt";
        } else if (failo_pav_pasirinkimas == 5) {
            failo_pavadinimas = "studentai10000000.txt";
        }
        else {
            std::cout << "Neteisingas pasirinkimas!" << std::endl;
            return 1;
        }
        auto laikas_pradzia = std::chrono::high_resolution_clock::now();
        std::ifstream fd(failo_pavadinimas);
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
        auto laikas_pabaiga = std::chrono::high_resolution_clock::now();
        skirtumas = laikas_pabaiga - laikas_pradzia;
        std::cout << "Failas " << failo_pavadinimas << " nuskaitytas per " << skirtumas.count() << " sekundziu." << std::endl;
    }
    else {
        auto laikas_pradzia = std::chrono::high_resolution_clock::now();
        atsitiktinis_sarasas("studentai1000.txt", 1000);
        auto laikas_pabaiga = std::chrono::high_resolution_clock::now();
        skirtumas = laikas_pabaiga - laikas_pradzia;
        std::cout << "Sugeneruotas failas studentai1000.txt per " << skirtumas.count() << " sekundziu." << std::endl;
    
        auto laikas_pradzia2 = std::chrono::high_resolution_clock::now();
        atsitiktinis_sarasas("studentai10000.txt", 10000);
        auto laikas_pabaiga2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> skirtumas2 = laikas_pabaiga2 - laikas_pradzia2;
        std::cout << "Sugeneruotas failas studentai10000.txt per " << skirtumas2.count() << " sekundziu." << std::endl;
    
        auto laikas_pradzia3 = std::chrono::high_resolution_clock::now();
        atsitiktinis_sarasas("studentai100000.txt", 100000);
        auto laikas_pabaiga3 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> skirtumas3 = laikas_pabaiga3 - laikas_pradzia3;
        std::cout << "Sugeneruotas failas studentai100000.txt per " << skirtumas3.count() << " sekundziu." << std::endl;
    

        /*auto laikas_pradzia4 = std::chrono::high_resolution_clock::now();
        atsitiktinis_sarasas("studentai1000000.txt", 1000000);
        auto laikas_pabaiga4 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> skirtumas4 = laikas_pabaiga4 - laikas_pradzia4;
        std::cout << "Sugeneruotas failas studentai1000000.txt per " << skirtumas4.count() << " sekundziu." << std::endl;
    
        auto laikas_pradzia5 = std::chrono::high_resolution_clock::now();
        atsitiktinis_sarasas("studentai10000000.txt", 10000000);
        auto laikas_pabaiga5 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> skirtumas5 = laikas_pabaiga5 - laikas_pradzia5;
        std::cout << "Sugeneruotas failas studentai10000000.txt per " << skirtumas5.count() << " sekundziu." << std::endl;
        */
    }
    if (failo_pasirinkimas == 1 || failo_pasirinkimas == 2) {
        int vertinimo_pasirinkimas;
        std::cout << "Pagal ka norite rusiuoti studentus? (1 - mediana, 2 - vidurki)" << std::endl;
        std::cin >> vertinimo_pasirinkimas;
        auto laikas_pradzia = std::chrono::high_resolution_clock::now();
        for (studentas A : grupe) {
            if (vertinimo_pasirinkimas == 1) {
                if (A.galutinis_mediana < 5) {
                    vargsiukai.push_back(A);
                } else {
                    kietiakai.push_back(A);
                }
            } else if (vertinimo_pasirinkimas == 2) {
                if (A.galutinis < 5) {
                    vargsiukai.push_back(A);
                } else {
                    kietiakai.push_back(A);
                }
            } else {
                std::cout << "Neteisingas pasirinkimas!" << std::endl;
                return 1;
            }
        }
        auto laikas_pabaiga = std::chrono::high_resolution_clock::now();
        skirtumas = laikas_pabaiga - laikas_pradzia;
        std::cout << "Studentai suskirstyti i dvi grupes per " << skirtumas.count() << " sekundziu." << std::endl;
        auto laikas_pradzia2 = std::chrono::high_resolution_clock::now();
        std::cout << "Pagal ka norite rusiuoti studentus? (1 - vardas, 2 - pavarde, 3 - galutinis)" << std::endl;
        int rusiuoti_pasirinkimas;
        std::cin >> rusiuoti_pasirinkimas;
        if (rusiuoti_pasirinkimas == 1) {
            std::sort(vargsiukai.begin(), vargsiukai.end(), palygintiVardus);
            std::sort(kietiakai.begin(), kietiakai.end(), palygintiVardus);
        } else if (rusiuoti_pasirinkimas == 2) {
            std::sort(vargsiukai.begin(), vargsiukai.end(), palygintiPavardes);
            std::sort(kietiakai.begin(), kietiakai.end(), palygintiPavardes);
        } else if (rusiuoti_pasirinkimas == 3) {
            std::sort(vargsiukai.begin(), vargsiukai.end(), palygintiGalutinius);
            std::sort(kietiakai.begin(), kietiakai.end(), palygintiGalutinius);
        } else {
            std::cout << "Neteisingas pasirinkimas!" << std::endl;
            return 1;
        }
        std::ofstream failas_vargsiukai("vargsiukai.txt");
        std::ofstream failas_kietiakai("kietiakai.txt");
        if (!failas_vargsiukai.is_open() || !failas_kietiakai.is_open()) {
            std::cout << "Nepavyko sukurti failo!" << std::endl;
            return 1;
        }

        failas_vargsiukai << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20);
        failas_kietiakai << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20);

        if (vertinimo_pasirinkimas == 1) {
            failas_vargsiukai << std::setw(20) << "Galutinis (med.)" << std::endl;
            failas_kietiakai << std::setw(20) << "Galutinis (med.)" << std::endl;
        } else {
            failas_vargsiukai << std::setw(20) << "Galutinis (vid.)" << std::endl;
            failas_kietiakai << std::setw(20) << "Galutinis (vid.)" << std::endl;
        }

        for (studentas A : vargsiukai) {
            failas_vargsiukai << std::left << std::setw(20) << A.vardas << std::setw(20) << A.pavarde;
            if (vertinimo_pasirinkimas == 1) {
                failas_vargsiukai << std::setw(20) <<std::fixed << std::setprecision(2) << A.galutinis_mediana << std::endl;
            } else {
                failas_vargsiukai << std::setw(20) << std::fixed << std::setprecision(2) << A.galutinis << std::endl;
            }
        }

        for (studentas A : kietiakai) {
            failas_kietiakai << std::left << std::setw(20) << A.vardas << std::setw(20) << A.pavarde;
            if (vertinimo_pasirinkimas == 1) {
                failas_kietiakai << std::setw(20) <<std::fixed << std::setprecision(2) << A.galutinis_mediana << std::endl;
            } else {
                failas_kietiakai << std::setw(20) << std::fixed << std::setprecision(2) << A.galutinis << std::endl;
            }
        }

        std::sort(vargsiukai.begin(), vargsiukai.end(), palygintiVardus);
        std::sort(kietiakai.begin(), kietiakai.end(), palygintiVardus);
        auto laikas_pabaiga2 = std::chrono::high_resolution_clock::now();
        skirtumas = laikas_pabaiga2 - laikas_pradzia2;
        std::cout << "Failu rasymas uztruko " << skirtumas.count() << " sekundziu." << std::endl;
    }

    return 0;
}
