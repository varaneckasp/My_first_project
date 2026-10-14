#pragma once
#include "studentas.h"
bool palygintiVardus(const studentas &a, const studentas &b);
bool palygintiPavardes(const studentas &a, const studentas &b);
bool palygintiGalutinius(const studentas &a, const studentas &b);
void atsitiktinis_sarasas(const std::string &failo_pavadinimas, int studentu_skaicius);
void skaiciuotiGalutini(studentas& A);
void skaitytiFaila (const std::string &failo_pavadinimas, std::vector<studentas> &grupe);
void skirstytiStudentus(std::vector<studentas> &grupe, std::vector<studentas> &vargsiukai, std::vector<studentas> &kietiakai, int vertinimo_pasirinkimas);
void rusiuotiStudentus(std::vector<studentas> &grupe, int rusiuoti_pasirinkimas);
void rasytiFailus(std::vector<studentas> &vargsiukai, std::vector<studentas> &kietiakai, int vertinimo_pasirinkimas);
