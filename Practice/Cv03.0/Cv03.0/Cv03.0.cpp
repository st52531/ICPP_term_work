// Cv03.0.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;


	struct Zvire(string typ, string rad) {

	};

	struct Medved : Zvire {
		Medved() : Zvire(("obratlovec", "medvedovity")) {

		}
	};
	int main()
	{
		Medved medved{};
		Zvire* zvirePtr = new Medved{};
		Zvire& zvireRef = *(new Medved{});



		return 0;
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
