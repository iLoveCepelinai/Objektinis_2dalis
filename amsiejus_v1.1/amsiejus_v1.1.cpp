#include "v1.1_bib.h"

int main (){
	vector <Studentas> grupe, dundukai;
	vector <int> pazymiai;

	string pasirinkimas;
	
	do {
		cout << "Iveskite pagal ka skaiciuosite vidurki (vid/med)" << endl;
		cin >> pasirinkimas;
		try {
			if (pasirinkimas != "vid" && pasirinkimas != "med") {
				throw pasirinkimas;
			}
		}
		catch (string pas) {
			cout << "Jusu ivestas pasirinkimas " << pas << " neatitinka reikalavimu. Kartokite:\n";
		}
	} while (pasirinkimas != "vid" && pasirinkimas != "med");


	cout << "-------------100 000-------------" << endl;
	failuKurimas(5, 10000);
	skaitymas(10000, grupe, pasirinkimas);
	skirstymas(grupe, dundukai);
	surasymas(dundukai, grupe);

	grupe.clear(), dundukai.clear();
}