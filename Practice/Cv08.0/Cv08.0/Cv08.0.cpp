// Cv08.0.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include "pch.h"
#include <iostream>
#include<fstream>
#include<string>

using namespace std;
struct KomplexniCislo {
	double re;
	double im;

	KomplexniCislo() : re(0), im(0) {

	}
	KomplexniCislo(double r, double i) : re(r), im(i) {}
};

ostream& operator<<(ostream& os, const KomplexniCislo& kc) {
	os << kc.re << " "<< (kc.im > 0 ? "+" : "-") << " "<< abs(kc.im) << "i";
	return os;
}

istream& operator>>(istream& is, KomplexniCislo& kc) {
	is >> kc.re ;

	char oper;
	is >> oper;
	
	is >> kc.im;

	if (oper == '-')
		kc.im = -kc.im;
	char imagJednotka;
	is >> imagJednotka;
	if (imagJednotka != 'i')
		throw "Neplatne komplexni cislo";
		return is;
}

int main()
{
	KomplexniCislo k{ 1,5 };
	KomplexniCislo k2{ -1, -3 };
	ofstream f{ "komplexni-cisla.txt" };
	for (int i = 0; i < 100; i++) {
		KomplexniCislo k{ rand() % 100 - 50,rand() % 100 - 50 };
		f << k << endl;
	}

	f.close;


	ifstream fi{ "komplexni-cisla.txt" };
	while (true) {
		KomplexniCislo k{};
		fi >> k;
		if (fi.eof())
			break;
		cout << "Nacteno: " << k << endl;
	}

	string str{};
	return 0;
}
