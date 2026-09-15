#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using std::string;
using std::vector;


struct studentas{
    string vardas, pavarde;
    vector<int> pazymiai;
    int exam;
    };
int main() 
{
    studentas A;
    std::cout << "Iveskite varda ir pavarde per tarpa: ";
    std::cin >> A.vardas >> A.pavarde;
    std::cout << "Kiek namu darbu pazymiu norite ivesti? ";
    int k;
    std::cin >> k;
    for (int i = 0; i < k; i++) {
        int pazymys;
        std::cout << "Iveskite " << i + 1 << " pazymi: ";
        std::cin >> pazymys;
        A.pazymiai.push_back(pazymys);
    }
    std::cout << "Iveskite studento egzamino rezultata: ";
    std::cin >> A.exam;
    double suma = 0;
    for (int i = 0; i < A.pazymiai.size(); i++) {
        suma += A.pazymiai[i];
    }
    double vidurkis = suma / A.pazymiai.size();
    double galutinis = 0.4 * vidurkis + 0.6 * A.exam;
    std::cout << "Studento galutinis rezultatas: " << std::fixed << std::setprecision(2) << galutinis << std::endl;

}
 