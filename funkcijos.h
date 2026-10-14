#pragma once
#include "studentas.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <fstream>
#include <iomanip>
bool palygintiVardus(const studentas &a, const studentas &b);
bool palygintiPavardes(const studentas &a, const studentas &b);
bool palygintiGalutinius(const studentas &a, const studentas &b);
void atsitiktinis_sarasas(const std::string &failo_pavadinimas, int studentu_skaicius);
void skaiciuotiGalutini(studentas& A);
void skaitytiFaila (const std::string &failo_pavadinimas, std::vector<studentas> &grupe);
template <typename T>
void skaitytiFaila (const std::string &failo_pavadinimas, T &grupe) {
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
template <typename T>
void skirstytiStudentus(const T&grupe, T&vargsiukai, T&kietiakai, int vertinimo_pasirinkimas){
        for (const studentas& A : grupe) {
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
                std::cout << "Neteisingas pasirinkimas!\n";
                return;
            }
        }
    }
void rusiuotiStudentus(std::vector<studentas> &grupe, int rusiuoti_pasirinkimas);
void rusiuotiStudentus(std::list<studentas> &grupe, int rusiuoti_pasirinkimas);
template <typename T>
void rasytiFailus(const T& vargsiukai, const T& kietiakai, int vertinimo_pasirinkimas) {
        std::ofstream failas_vargsiukai("vargsiukai.txt");
        std::ofstream failas_kietiakai("kietiakai.txt");
        if (!failas_vargsiukai.is_open() || !failas_kietiakai.is_open()) {
            std::cout << "Nepavyko sukurti failo!" << std::endl;
            return;
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

        for (const studentas& A : vargsiukai) {
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
    }
