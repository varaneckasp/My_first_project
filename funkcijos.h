#pragma once
#include "studentas.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <iomanip>
#include <cstddef>
bool palygintiVardus(const studentas &a, const studentas &b);
bool palygintiPavardes(const studentas &a, const studentas &b);
bool palygintiGalutinius(const studentas &a, const studentas &b);
void atsitiktinis_sarasas(const std::string &failo_pavadinimas, int studentu_skaicius);
void skaiciuotiGalutini(studentas& A);
template <typename T>
bool skaitytiFaila (const std::string &failo_pavadinimas, T &grupe) {
    std::ifstream fd(failo_pavadinimas);
        if (!fd.is_open()) {
            std::cout << "Nepavyko atidaryti failo!" << std::endl;
            return false;
        }
        std::string eilute;
        std::getline(fd, eilute);
        std::stringstream ss;
        while(std::getline(fd,eilute)) {
            //std::stringstream ss(eilute);
            ss.clear();
            ss.str(eilute);
            studentas A;
            ss >> A.vardas >> A.pavarde;
            int pazymys;
            while (ss >> pazymys) {
                A.pazymiai.push_back(pazymys);
            }
                if(A.pazymiai.size() < 2){
                    continue;
                }
                A.exam = A.pazymiai.back();
                A.pazymiai.pop_back();
                skaiciuotiGalutini(A);
                grupe.push_back(A);
               
        }
         return true;
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
bool rasytiFailus(const T& vargsiukai, const T& kietiakai, int vertinimo_pasirinkimas) {
        std::ofstream failas_vargsiukai("vargsiukai.txt");
        std::ofstream failas_kietiakai("kietiakai.txt");
        if (!failas_vargsiukai.is_open() || !failas_kietiakai.is_open()) {
            std::cout << "Nepavyko sukurti failo!" << std::endl;
            return false;
        }

        failas_vargsiukai << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20);
        failas_kietiakai << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20);

        if (vertinimo_pasirinkimas == 1) {
            failas_vargsiukai << std::setw(20) << "Galutinis (med.)"<< '\n';
            failas_kietiakai << std::setw(20) << "Galutinis (med.)"<< '\n';
        } else {
            failas_vargsiukai << std::setw(20) << "Galutinis (vid.)"<< '\n';
            failas_kietiakai << std::setw(20) << "Galutinis (vid.)"<< '\n';
        }

        for (const studentas& A : vargsiukai) {
            failas_vargsiukai << std::left << std::setw(20) << A.vardas << std::setw(20) << A.pavarde;
            if (vertinimo_pasirinkimas == 1) {
                failas_vargsiukai << std::setw(20) <<std::fixed << std::setprecision(2) << A.galutinis_mediana << '\n';
            } else {
                failas_vargsiukai << std::setw(20) << std::fixed << std::setprecision(2) << A.galutinis << '\n';
            }
        }

        for (const studentas& A : kietiakai) {
            failas_kietiakai << std::left << std::setw(20) << A.vardas << std::setw(20) << A.pavarde;
            if (vertinimo_pasirinkimas == 1) {
                failas_kietiakai << std::setw(20) <<std::fixed << std::setprecision(2) << A.galutinis_mediana << '\n';
            } else {
                failas_kietiakai << std::setw(20) << std::fixed << std::setprecision(2) << A.galutinis << '\n';
            }
        }
        failas_vargsiukai.flush();
        failas_kietiakai.flush();
        return failas_vargsiukai.good() && failas_kietiakai.good();
    }
    void rezervuotiVieta(std::vector<studentas>& grupe, size_t kiekis);
    void rezervuotiVieta(std::list<studentas>& grupe, size_t kiekis);
