// Cv08.1.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include "pch.h"
#include <iostream>
#include"Osoba.h"
#include<fstream>
#include"Adresa.h"
#include"Datum.h"
#include<string>

using namespace std;

void ulozText(string file) {
	int pocet = 3;
	Osoba* h = new Osoba[pocet];
	Osoba h1{ "Petr","Novak",Adresa { "Nova","Praha",45652 },Datum { 6,5,1995 } };
	Osoba h2{ "Kamil","Nový",Adresa { "Stara","Hodonín",47862 },Datum { 6,1,1985 } };
	Osoba h3{ "Jiri","Stehlik",Adresa { "Mlada","Ostrava",12520 },Datum { 9,10,1965 } };
	h[0] = h1;
	h[1] = h2;
	h[2] = h3;
	ofstream out{};
	out.open("output_text.txt");

	if (out.is_open())
	{
		for (int i = 0; i < pocet; i++) {
			out << h[i]._jmeno << " " << h[i]._prijmeni << " adr. "
				<< h[i]._trvaleBydliste._ulice << " " << h[i]._trvaleBydliste._mesto << " " << h[i]._trvaleBydliste._psc << " nar. "
				<< h[i]._datumNarozeni._den << " " << h[i]._datumNarozeni._mesic << " " << h[i]._datumNarozeni._rok << endl;
		}

		out.close();
	}
	else {
		cerr << "Soubor se nepodařilo otevřít. ";
	}
}

void nactiText(string file) {

	ifstream in{};
	in.open(file);
	string s{};
	int count = 0;

	if (in.is_open()) {
		while (!in.eof()) {
			getline(in, s);
			count++; // it will count one empty line as well
		}
		in.clear();
		in.seekg(0, ios_base::beg);
		Osoba* h = new Osoba[count];
		for (int i = 0; i < count - 1; i++)
		{
			in >> h[i]._jmeno >> h[i]._prijmeni >> s >> h[i]._trvaleBydliste._ulice
				>> h[i]._trvaleBydliste._mesto >> h[i]._trvaleBydliste._psc
				>> s >> h[i]._datumNarozeni._den >> h[i]._datumNarozeni._mesic >> h[i]._datumNarozeni._rok;

			cout << h[i]._jmeno << " " << h[i]._prijmeni << " adr. "
				<< h[i]._trvaleBydliste._ulice << " " << h[i]._trvaleBydliste._mesto << " " << h[i]._trvaleBydliste._psc << " nar. "
				<< h[i]._datumNarozeni._den << ". " << h[i]._datumNarozeni._mesic << ". " << h[i]._datumNarozeni._rok << endl;

		}
		delete[] h;
		in.close();
	}
}

void ulozBinarne(string file) {
	int pocet = 3;
	Osoba* h = new Osoba[pocet];
	Osoba h1{ "Petr","Novak",Adresa { "Nova","Praha",45652 },Datum { 6,5,1995 } };
	Osoba h2{ "Kamil","Novy",Adresa { "Stara","Hodonin",47862 },Datum { 6,1,1985 } };
	Osoba h3{ "Jiri","Stehlik",Adresa { "Mlada","Ostrava",12520 },Datum { 9,10,1965 } };
	h[0] = h1;
	h[1] = h2;
	h[2] = h3;
	ofstream out{};
	out.open(file, ios_base::binary);

	if (out.is_open()) {
		for (int i = 0; i < pocet; i++)
		{
			out.write((char*)&h[i], sizeof(Osoba));
		}
	}
}

void nactiBinarne(string file) {
	ifstream in{};
	in.open(file, ios_base::binary);
	string s{};
	//int count = 0;
	Osoba* h = new Osoba[3];
	if (in.is_open()) {
		/*while (!in.eof()) {
			getline(in,s);
			count++;
		}*/
		for (int i = 0; i < 3; i++)
		{
			in.read((char*)&h[i], sizeof(Osoba));
		}
		in.close();
	}
	for (int i = 0; i < 3; i++)
	{
		cout << h[i]._jmeno << " " << h[i]._prijmeni << " adr. "
			<< h[i]._trvaleBydliste._ulice << " " << h[i]._trvaleBydliste._mesto << " " << h[i]._trvaleBydliste._psc << " nar. "
			<< h[i]._datumNarozeni._den << ". " << h[i]._datumNarozeni._mesic << ". " << h[i]._datumNarozeni._rok << endl;
	}
	delete[] h;
}

int main()
{
	/*ulozText("output_text.txt");
	nactiText("output_text.txt");*/
	ulozBinarne("output_binary.dat");
	nactiBinarne("output_binary.dat");
	return 0;
}
