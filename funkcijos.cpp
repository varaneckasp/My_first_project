#include "funkcijos.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iomanip>
#include <cstdlib>

bool palygintiVardus(const studentas &a, const studentas &b) {
    return a.vardas < b.vardas;
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
        fd << std::setw(10) << egzaminas << std::endl;
    }

}