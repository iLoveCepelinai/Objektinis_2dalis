#include "v1.1_bib.h"

void failuKurimas(int, int);
void skaitymas(int, vector <Studentas>&, string);
void skirstymas(vector <Studentas>&, vector <Studentas>&);
void surasymas(vector <Studentas>, vector <Studentas>);
bool arSkola(Studentas);


void failuKurimas(int ndkiekis, int studkiekis) {
    string tempVardas;
    string tempPavarde;

    string failopav = to_string(studkiekis);
    failopav += ".txt";

    ofstream failas(failopav);
    failas << setw(20) << "Vardas" << setw(20) << "Pavarde" << "\t";

    for (int i = 1; i <= ndkiekis; i++) {
        failas << "ND" << i << "\t";
    }

    failas << "Egz.";

    //pradedame irasineti duomenis
    for (int j = 1; j <= studkiekis; j++) {
        failas << endl;

        tempVardas = "Vardas" + to_string(j);
        failas << setw(20) << tempVardas;

        tempPavarde = "Pavarde" + to_string(j);
        failas << setw(20) << tempPavarde << "\t";

        for (int i = 1; i <= ndkiekis; i++) {
            failas << std::rand() % 10 + 1 << "\t";
        }

        failas << std::rand() % 10 + 1;
    }
    failas.close();
}


void skaitymas(int studkiekis, vector <Studentas>& grupele, string pasirinkimas) {
    ifstream failas;
    string sVardai, sPavardes, sTemp, egzaminas;
    vector <string> ndMasyv;
    int m;  //namu darbu kiekis

    string failoPav = to_string(studkiekis);
    failoPav += ".txt";

    try {
        failas.open(failoPav);
    }
    catch (std::exception& e) {
        cout << "Failas " << failoPav << " nebuvo rastas" << endl;
    }

    try {
        if (!failas.good()) {
            throw failoPav;
        }
        failas >> sVardai >> sPavardes >> sTemp;
        while (sTemp != "Egz.") {
            ndMasyv.push_back(sTemp);
            failas >> sTemp;
        }
        egzaminas = sTemp;  //sie nuskaitymai pades tureti stulpeliu vardus, bet svarbiausia: bus zinomas namu darbu kiekis

        m = ndMasyv.size();
        ndMasyv.clear();

        string vardas, pavarde;
        int egz = 0;
        vector <int> pazymiai;

        grupele.reserve(studkiekis);

        while (!failas.eof()) { //skaito iki kol atsimusa i failo pabaiga
            failas >> vardas >> pavarde;

            int laikPaz;

            for (int i = 0; i < m; i++) {
                failas >> laikPaz;
                pazymiai.push_back(laikPaz);
            }

            failas >> egz;

            Studentas temp(vardas, pavarde, pazymiai, egz);
            grupele.push_back(temp);
        }
        failas.close();
    }
    catch (string pav) {
        cout << pav << " failas neegzistuoja arba jo nepavyko atidaryti\n";
    }
    cout << "duomenys jau faile. Liko tik skiaicuoti galutinius:" << endl;
    if (pasirinkimas == "vid") {
        for (auto& studentas : grupele) {
            studentas.galutinisVid();
        }
    }
    else {
        for (auto& studentas : grupele) {
            studentas.galutinisMed();
        }
    }
    cout << "Baigesi skaitymas" << endl;
}


void skirstymas(vector <Studentas> &grupele, vector <Studentas>& dundukai) {
    auto start = std::chrono::high_resolution_clock::now();

    int grupeDydis = size(grupele);
    dundukai.reserve(grupeDydis * 0.5);

    vector<Studentas>::iterator it = std::partition(grupele.begin(), grupele.end(), arSkola);
    std::move(grupele.begin(), it, back_inserter(dundukai));
    grupele.erase(grupele.begin(), it);
    
    /*
    while (it != grupele.end()) {
        if ((*it).gavoSkola()) {
            dundukai.push_back(*it); // dereference *it kad gauti elementà
            it = grupele.erase(it); // perduodame it, gauname it
        }
        else
            ++it; // pereiti prie kito studento
    }*/
    
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    cout << "Rusiavimas ir skirstymas i 2 vektorius uztruko: " << diff.count() << "s" << endl;
}


void surasymas(vector <Studentas> dundukai, vector <Studentas> sukciukai) {
    ofstream failD("testdundukai.txt"); // kuriame dunduku faila
    for (auto& dundukas : dundukai) {
        failD << setw(20) << dundukas.getVardas() << setw(20) << dundukas.getPavard() << "\t" << dundukas.getEgz() << endl;
    }
    failD.close();

    ofstream failS("testSukciukai.txt"); // kuriame sukckiuku faila
    for (auto& sukciukas : sukciukai) {
        failS << setw(20) << sukciukas.getVardas() << setw(20) << sukciukas.getPavard() << "\t" << sukciukas.getEgz() << endl;
    }
    failS.close();
}

bool arSkola(Studentas stud) {
    return stud.gavoSkola();
}
