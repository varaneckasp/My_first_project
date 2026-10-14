#pragma once
#include "studentas.h"
#include <iostream>
#include <fstream>
#include <sstream>
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
void rasytiFailus(std::vector<studentas> &vargsiukai, std::vector<studentas> &kietiakai, int vertinimo_pasirinkimas);
