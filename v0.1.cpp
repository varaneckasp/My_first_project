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
    int k;
    std::cout << "Iveskite pazymiu skaiciu: ";
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
     double mediana;
    if (A.pazymiai.size() % 2 == 0) {
        int mid = A.pazymiai.size() / 2;
        mediana = (A.pazymiai[mid - 1] + A.pazymiai[mid]) / 2.0;
    } else {
        int mid = A.pazymiai.size() / 2;
        mediana = A.pazymiai[mid];
    }
    double galutinis = 0.4 * vidurkis + 0.6 * A.exam;
    double galutinis_mediana = 0.4 * mediana + 0.6 * A.exam;
    std::cout << "Studento galutinis rezultatas: " << std::fixed << std::setprecision(2) << galutinis << std::endl;
    std::cout << "Studento galutinis rezultatas (naudojant mediana): " << std::fixed << std::setprecision(2) << galutinis_mediana << std::endl;

}
 