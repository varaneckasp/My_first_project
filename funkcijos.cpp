#pragma once
#include "funkcijos.h"
#include <iostream>
#include <iomanip>
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
