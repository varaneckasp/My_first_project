#include "funkcijos.h"
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iomanip>
#include <cstdlib>

bool palygintiVardus(const studentas &a, const studentas &b) {
    return a.vardas < b.vardas;
}
bool palygintiPavardes(const studentas &a, const studentas &b) {
    return a.pavarde < b.pavarde;
}
bool palygintiGalutinius(const studentas &a, const studentas &b) {
    return a.galutinis < b.galutinis;
}
void atsitiktinis_sarasas(const std::string &failo_pavadinimas, int studentu_skaicius) {
    std::ofstream fd(failo_pavadinimas);
    if (!fd.is_open()) {
        std::cout << "Nepavyko sukurti failo!" << std::endl;
        return;
    }
    fd<< std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde";
    for (int i = 1; i <= 15; i++) {
        fd << std::setw(10) << ("ND" + std::to_string(i));
    }
    fd << std::setw(10) << "Egz." << std::endl;
    for (int i = 0; i < studentu_skaicius; i++) {
        std::string vardas = "Vardas" + std::to_string(i + 1);
        std::string pavarde = "Pavarde" + std::to_string(i + 1);
        fd << std::left << std::setw(20) << vardas << std::setw(20) << pavarde;
        for (int j = 0; j < 15; j++) {
            int pazymys = rand() % 10 + 1;
            fd << std::setw(10) << pazymys;
        }
        int egzaminas = rand() % 10 + 1;
        fd << std::setw(10) << egzaminas << '\n';
    }
    fd.close();
}

void skaiciuotiGalutini(studentas& A) {
    double suma = 0;
    for (int i = 0; i < A.pazymiai.size(); i++) {
        suma += A.pazymiai[i];
    }
    if (A.pazymiai.empty()) {
        A.galutinis = 0;
        A.galutinis_mediana = 0;
        return;
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
}
void skaitytiFaila (const std::string &failo_pavadinimas, std::vector<studentas> &grupe) {
    std::ifstream fd(failo_pavadinimas);
        if (!fd.is_open()) {
            std::cout << "Nepavyko atidaryti failo!" << std::endl;
            return;
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
                skaiciuotiGalutini(A);
                grupe.push_back(A);
        }
    }
void rusiuotiStudentus(std::vector<studentas> &grupe, int rusiuoti_pasirinkimas) {
    if (rusiuoti_pasirinkimas == 1) {
        std::sort(grupe.begin(), grupe.end(), palygintiVardus);
    } else if (rusiuoti_pasirinkimas == 2) {
        std::sort(grupe.begin(), grupe.end(), palygintiPavardes);
    } else if (rusiuoti_pasirinkimas == 3) {
        std::sort(grupe.begin(), grupe.end(), palygintiGalutinius);
    } else {
        std::cout << "Neteisingas pasirinkimas!" << std::endl;
        return;
    }
}
void rusiuotiStudentus(std::list<studentas> &grupe, int rusiuoti_pasirinkimas) {
    if (rusiuoti_pasirinkimas == 1) {
        grupe.sort(palygintiVardus);
    } else if (rusiuoti_pasirinkimas == 2) {
        grupe.sort(palygintiPavardes);
    } else if (rusiuoti_pasirinkimas == 3) {
        grupe.sort(palygintiGalutinius);
    } else {
        std::cout << "Neteisingas pasirinkimas!" << std::endl;
        return;
    }
}
