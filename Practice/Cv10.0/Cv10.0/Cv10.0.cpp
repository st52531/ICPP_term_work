// Cv10.0.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include "pch.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
int main()
{
	ostringstream oss{}; 
	oss << 2 << '\n';
	oss << " 0" << '\n';
	oss << "OTO" << '\n';
	oss << " 0 " << '\n';


	istringstream iss{
		oss.str()
	};

	int rozmer;
	iss >> rozmer;

	/*if (iss.peak()) {

	}*/

	for (int i = 0; i < rozmer; i++) {
		string str{};
		getline(iss, str);
		for (int j = 0; j < rozmer; j++) {
			cout << str[j] << ';';
		}
		cout << endl;
	}
}

// Spuštění programu: Ctrl+F5 nebo nabídka Ladit > Spustit bez ladění
// Ladění programu: F5 nebo nabídka Ladit > Spustit ladění

// Tipy pro zahájení práce:
//   1. K přidání nebo správě souborů použijte okno Průzkumník řešení.
//   2. Pro připojení ke správě zdrojového kódu použijte okno Team Explorer.
//   3. K zobrazení výstupu sestavení a dalších zpráv použijte okno Výstup.
//   4. K zobrazení chyb použijte okno Seznam chyb.
//   5. Pokud chcete vytvořit nové soubory kódu, přejděte na Projekt > Přidat novou položku. Pokud chcete přidat do projektu existující soubory kódu, přejděte na Projekt > Přidat existující položku.
//   6. Pokud budete chtít v budoucnu znovu otevřít tento projekt, přejděte na Soubor > Otevřít > Projekt a vyberte příslušný soubor .sln.
