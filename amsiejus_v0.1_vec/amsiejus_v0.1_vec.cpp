/*
    Matas Amsiejus
    VU, DM 2, 2 kursas
    Objektinis programavimas C++
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setw;
using std::vector;
using std::size;


struct studentas {
    string vardas, pavard;
    vector <double> nd;
    double egz, galut;
};

int main()
{
    int n = 0;
    int m = 0;
    cout << "Iveskite studentu skaiciu: ";
    cin >> n;
    while (!cin) {
        cout << "Jus ivedete klaidingus duomenis" << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Iveskite studentu skaiciu: ";
        cin >> n;
    }

    vector <studentas> grupe;
    grupe.reserve(n);

    //pirma ciklas, kuris skaiciuoja jau sugalvotus studentus (nuo 1 ir daugiau)
    int i;
    for (i = 0; i < n; i++) {
        studentas laik;
        cout << "Iveskite " << i + 1 << "-ojo studento varda: "; cin >> laik.vardas;

        cout << "Iveskite " << i + 1 << "-ojo studento pavarde: "; cin >> laik.pavard;

        string randEgz;
        cout << "Iveskite ar norite atsitiktinai generuoto egzamino pazymio? (taip / ne): " << endl; cin >> randEgz;
        while (!cin || randEgz != "taip" && randEgz != "ne") {
            cout << "Jus ivedete klaidingus duomenis" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Iveskite ar norite atsitiktinai generuoto egzamino pazymio? (taip / ne): "; cin >> randEgz;
        }
        if (randEgz == "ne") {
            cout << "Iveskite studento egzamino pazimi: "; cin >> laik.egz;
            while (!cin || laik.egz < 1 || laik.egz>10) {
                cout << "Jus ivedete klaidingus duomenis" << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Iveskite studento egzamino pazimi: "; cin >> laik.egz;
            }
        }
        else if (randEgz == "taip") {
            laik.egz = std::rand() % 10 + 1;
            cout << laik.egz << endl;
        }


        string randNd;
        cout << "Iveskite ar norite atsitiktinai generuoti nd pazymius? (taip / ne): " << endl; cin >> randNd;
        while (!cin || randEgz != "taip" && randEgz != "ne") {
            cout << "Jus ivedete klaidingus duomenis" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Iveskite ar norite atsitiktinai generuoti nd pazymius? (taip / ne): "; cin >> randNd;
        }

        if (randNd == "ne") {
            string klausimasNd = "taip";
            int laikinasNd;
            while (klausimasNd == "taip") {
                cout << "Iveskite namu darbu pazimi: "; cin >> laikinasNd;
                while (!cin || laikinasNd < 1 || laikinasNd > 10) {
                    cout << "Jus ivedete klaidingus duomenis" << endl;
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Iveskite namu darbu pazimi: "; cin >> laikinasNd;
                }

                laik.nd.push_back(laikinasNd);

                cout << "Ar dar bus namu darbu pazymiu?(taip/ne) "; cin >> klausimasNd;
                while (!cin || klausimasNd != "taip" && klausimasNd != "ne") {
                    cout << "Jus ivedete klaidingus duomenis" << endl;
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Ar dar bus namu darbu pazymiu? (taip/ne)"; cin >> klausimasNd;
                }
            }
        }
        else if (randNd == "taip") {
            cout << "Iveskite  studento namu darbu skaiciu: "; cin >> m;
            while (!cin || m <= 0) {
                cout << "Jus ivedete klaidingus duomenis" << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Iveskite  studento namu darbu skaiciu: ";
                cin >> m;
            }
            int tempNd;
            for (int j = 0; j < m; j++) {
                tempNd = std::rand() % 10 + 1;
                laik.nd.push_back(tempNd);
                cout << laik.nd.at(j) << " ";
            }
        }
        grupe.push_back(laik);
    }



    //antras ciklas skaiciuoja jau is karto galvojamus studentus (kai vartotojas nezino is karto kiek bus)

    string klausimasStud;
    cout << "Ar dar bus studentu? (taip/ne)" << endl; cin >> klausimasStud;
    while (klausimasStud != "ne" && klausimasStud != "taip") {
        cout << "Jus ivedete klaidingus duomenis" << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Ar dar bus studentu? (taip/ne) "; cin >> klausimasStud;
    }

    while (klausimasStud == "taip") {
        studentas laik;
        cout << "Iveskite " << i + 1 << "-ojo studento varda: "; cin >> laik.vardas;

        cout << "Iveskite " << i + 1 << "-ojo studento pavarde: "; cin >> laik.pavard;

        string randEgz;
        cout << "Iveskite ar norite atsitiktinai generuoto egzamino pazymio? (taip / ne): " << endl; cin >> randEgz;
        while (!cin || randEgz != "taip" && randEgz != "ne") {
            cout << "Jus ivedete klaidingus duomenis" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Iveskite ar norite atsitiktinai generuoto egzamino pazymio? (taip / ne): "; cin >> randEgz;
        }
        if (randEgz == "ne") {
            cout << "Iveskite studento egzamino pazimi: "; cin >> laik.egz;
            while (!cin || laik.egz < 1 || laik.egz>10) {
                cout << "Jus ivedete klaidingus duomenis" << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Iveskite studento egzamino pazimi: "; cin >> laik.egz;
            }
        }
        else if (randEgz == "taip") {
            laik.egz = std::rand() % 10 + 1;
            cout << laik.egz << endl;
        }


        string randNd;
        cout << "Iveskite ar norite atsitiktinai generuoti nd pazymius? (taip / ne): " << endl; cin >> randNd;
        while (!cin || randEgz != "taip" && randEgz != "ne") {
            cout << "Jus ivedete klaidingus duomenis" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Iveskite ar norite atsitiktinai generuoti nd pazymius? (taip / ne): "; cin >> randNd;
        }

        if (randNd == "ne") {
            string klausimasNd = "taip";
            int laikinasNd;
            while (klausimasNd == "taip") {
                cout << "Iveskite namu darbu pazimi: "; cin >> laikinasNd;
                while (!cin || laikinasNd < 1 || laikinasNd > 10) {
                    cout << "Jus ivedete klaidingus duomenis" << endl;
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Iveskite namu darbu pazimi: "; cin >> laikinasNd;
                }

                laik.nd.push_back(laikinasNd);

                cout << "Ar dar bus namu darbu pazymiu?(taip/ne) "; cin >> klausimasNd;
                while (!cin || klausimasNd != "taip" && klausimasNd != "ne") {
                    cout << "Jus ivedete klaidingus duomenis" << endl;
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Ar dar bus namu darbu pazymiu? (taip/ne)"; cin >> klausimasNd;
                }
            }
        }
        else if (randNd == "taip") {
            cout << "Iveskite  studento namu darbu skaiciu: "; cin >> m;
            while (!cin || m <= 0) {
                cout << "Jus ivedete klaidingus duomenis" << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Iveskite  studento namu darbu skaiciu: ";
                cin >> m;
            }
            int tempNd;
            for (int j = 0; j < m; j++) {
                tempNd = std::rand() % 10 + 1;
                laik.nd.push_back(tempNd);
                cout << laik.nd.at(j) << " ";
            }
        }
        i++;
        grupe.push_back(laik);
        cout << "Ar dar bus studentu? (taip/ne)" << endl; cin >> klausimasStud;
        while (klausimasStud != "ne" && klausimasStud != "taip") {
            cout << "Jus ivedete klaidingus duomenis" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Ar dar bus studentu? (taip/ne) "; cin >> klausimasStud;
        }
    }


    string klausimas;
    cout << "Pagal ka skaiciuoti galutini pazimi (vid - vidurki, med - mediana)" << endl;
    cin >> klausimas;
    while (klausimas != "med" && klausimas != "vid") {
        cout << "Jus ivedete klaidingus duomenis" << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Pagal ka skaiciuoti galutini pazimi (vid - vidurki, med - mediana): "; cin >> klausimas;
    }

    if (klausimas == "vid") {
        //skaiciavimas pagal vidurki
        double suma;
        double vid = 0;
        for (auto& studenciokas : grupe) {
            suma = 0;
            int a = 0;
            for (auto& a : studenciokas.nd) {
                suma = suma + a;
            }
            vid = suma / ((studenciokas.nd.size()) * 1.0);
            studenciokas.galut = 0.6 * studenciokas.egz + 0.4 * vid;
        }

        cout << "\tPavarde\t" << "\tVardas\t" << "\tGalutinis (vid.)" << endl;
        cout << "_____________________________________________" << endl;

        for (auto& studentelis : grupe) {
            cout << std::fixed;
            cout << std::setprecision(2);
            cout << setw(15) << studentelis.pavard << "\t" << setw(15) << studentelis.vardas << "\t\t" << studentelis.galut << endl;
        }
    }

    else if (klausimas == "med") {
        //skaiciavimas pagal mediana
        double mediana;
        int ndIlgis;
        for (auto& studenciokas : grupe) {
            std::sort(studenciokas.nd.begin(), studenciokas.nd.end());
            ndIlgis = studenciokas.nd.size();
            if (ndIlgis % 2 == 0) {
                mediana = (studenciokas.nd.at((ndIlgis * 1.0) / 2 - 1) + studenciokas.nd.at(ndIlgis / 2)) / 2;
            }
            else {
                int index = (ndIlgis * 1.0 - 1) / 2 + 0.5;
                mediana = studenciokas.nd.at(index);
            }
            studenciokas.galut = 0.6 * studenciokas.egz + 0.4 * mediana;
        }
        cout << "\tPavarde\t" << "\tVardas\t" << "\tGalutinis (med.)" << endl;
        cout << "_____________________________________________" << endl;

        for (auto& studentelis : grupe) {
            cout << std::fixed;
            cout << std::setprecision(2);
            cout << setw(15) << studentelis.pavard << "\t" << setw(15) << studentelis.vardas << "\t\t" << studentelis.galut << endl;
        }
    }

    grupe.clear();
}