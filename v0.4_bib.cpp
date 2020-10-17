#include "v04_bib.h";

void failuKurimas(int, int);
void skaitymas(string, vector <studentas>&, string);
void skirstymas(vector <studentas>, vector <studentas>&, vector <studentas>&);
void surasymas(vector <studentas>, vector <studentas>, string, string);


void failuKurimas(int ndkiekis, int studkiekis) {
    auto start = std::chrono::high_resolution_clock::now();
        string tempVardas;
        string tempPavarde;

        string failopav = to_string(studkiekis);
        failopav += ".txt";

        ofstream failas(failopav);
        failas << setw(20) << "Vardas" << setw(20) << "Pavarde" << "\t";

        for (int i = 1; i <= ndkiekis; i++) {
            failas << "ND" << i << "\t";
        }

        failas << "Egz." << endl;

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
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    cout << "Failo sukurimas uztruko: " << diff.count() << "s" << endl;
}



void skaitymas(string failoPav, vector <studentas> &grupele, string pasirinkimas) {
    auto start = std::chrono::high_resolution_clock::now();
        ifstream failas;
        string sVardai, sPavardes, sTemp, egzaminas;
        vector <string> ndMasyv;
        int m;  //namu darbu kiekis

        ndMasyv.reserve(1);

        grupele.reserve(1);

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

            while (!failas.eof()) { //skaito iki kol atsimusa i failo pabaiga
                studentas laik;
                failas >> laik.vardas >> laik.pavard;

                double laikPaz;

                for (int i = 0; i < m; i++) {
                    failas >> laikPaz;
                    laik.nd.push_back(laikPaz);
                }

                failas >> laik.egz;

                grupele.push_back(laik);
            }
            failas.close();
        }
        catch (string pav) {
            cout << pav << " failas neegzistuoja arba jo nepavyko atidaryti\n";
        }


        //skaiciavimas pagal vidurki:
        if (pasirinkimas == "vid") {
            double suma;
            double vid = 0;
            for (auto& studenciokas : grupele) {
                suma = 0;
                int a = 0;
                for (auto& a : studenciokas.nd) {
                    suma = suma + a;
                }
                vid = suma / m;
                studenciokas.galut = 0.6 * studenciokas.egz + 0.4 * vid;
            }
        }
    
        //skaiciavimas pagal mediana:
        else {
            double mediana;
            for (auto& studenciokas : grupele) {
                std::sort(studenciokas.nd.begin(), studenciokas.nd.end());
                if (m % 2 == 0) {
                    mediana = (studenciokas.nd.at((m * 1.0) / 2 - 1) + studenciokas.nd.at(m / 2)) / 2;
                }
                else {
                    int index = (m * 1.0 - 1) / 2 + 0.5;
                    mediana = studenciokas.nd.at(index);
                }
                studenciokas.galut = 0.6 * studenciokas.egz + 0.4 * mediana;
            }
        }
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    cout << "Skaitymas nuo failo uztruko: " << diff.count() << "s" << endl;
}


void skirstymas(vector <studentas> grupele, vector <studentas>& dundukai, vector <studentas>& sukciukai) {
    auto start = std::chrono::high_resolution_clock::now();
        for (auto& studenciokas : grupele) {
            if (studenciokas.galut < 5) {
                dundukai.push_back(studenciokas);
            }
            else {
                sukciukai.push_back(studenciokas);
            }
        }
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    cout << "Skirstymas i 2 vektorius ir  pradinio vektoriaus panaikinimas uztruko: " << diff.count() << "s" << endl;
}


void surasymas(vector <studentas> dundukai, vector <studentas> sukciukai, string pavDundukai, string pavSukciukai) {
    auto start = std::chrono::high_resolution_clock::now();
        ofstream failD(pavDundukai); // kuriame dunduku faila
        double ndKiekis = dundukai.at(1).nd.size();    //paimame belenkoki vektoriaus elementa (studenta) ir patikriname kiek jis turi nd

        failD << setw(20) << "Vardas" << setw(20) << "Pavarde" << "\t";

        for (int i = 1; i <= ndKiekis; i++) {
            failD << "ND" << i << "\t";
        }

        failD << "Egz." << "\t" << "Galut.";

        for (auto& dundukas : dundukai) {
            failD << endl;
            failD << setw(20) << dundukas.vardas << setw(20) << dundukas.pavard << "\t";
            for (auto& pazymys : dundukas.nd) failD << pazymys << "\t";
            failD << dundukas.egz << "\t" << dundukas.galut;
        }
        failD.close();

        ofstream failS(pavSukciukai); // kuriame sukciuku faila

        failS << setw(20) << "Vardas" << setw(20) << "Pavarde" << "\t";

        for (int i = 1; i <= ndKiekis; i++) {
            failS << "ND" << i << "\t";
        }

        failS << "Egz." << "\t" << "Galut.";

        for (auto& sukciukas : sukciukai) {
            failS << endl;
            failS << setw(20) << sukciukas.vardas << setw(20) <<sukciukas.pavard << "\t";
            for (auto& pazymys : sukciukas.nd) failS << pazymys << "\t";
            failS << sukciukas.egz << "\t" << sukciukas.galut;
        }
        failS.close();
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    cout << "2 vektoriu surasymas i 2 failus uztruko: " << diff.count() << "s" << endl;
}
