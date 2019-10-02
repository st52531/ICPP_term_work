// Cv08.1.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include "pch.h"
#include <iostream>
#include"Osoba.h"
#include<fstream>
#include"Adresa.h"
#include"Datum.h"

using namespace std;

void uloz() {

	Osoba* h = new Osoba[3];
	Osoba h1{ "Petr","Novak",Adresa { "Nova","Praha",45652 },Datum { 6,5,1995 } };
	Osoba h2{ "Kamil","Nový",Adresa { "Stara","Hodonín",47862 },Datum { 6,1,1985 } };
	Osoba h3{ "Jiří","Stehlik",Adresa { "Mlada","Ostrava",12520 },Datum { 9,10,1965 } };
	h[0] = h1;
	h[1] = h2;
	h[2] = h3;
	ofstream out{};
	out.open("cv_08.txt");

	if (out.is_open())
	{
		for (int i = 0; i < 3; i++) {
			out << h[i]._jmeno << " " << h[i]._prijmeni << " adr. " 
				<< h[i]._trvaleBydliste._ulice << " " << h[i]._trvaleBydliste._mesto << " " << h[i]._trvaleBydliste._psc << " nar. "
				<< h[i]._datumNarozeni._den << ". " << h[i]._datumNarozeni._mesic << ". " << h[i]._datumNarozeni._rok << endl;
		}

		out.close();
	}
	else {
		cerr << "Soubor se nepodařilo otevřít. ";
	}
}

void nacti() {

	ifstream in{};
	in.open("cv_08.txt");

	int count = 0;

	if (in.is_open()) {
		while (in) {
			count++;
		}

		cout << count;
	}
}

int main()
{
	uloz();
	nacti();
	return 0;
}
