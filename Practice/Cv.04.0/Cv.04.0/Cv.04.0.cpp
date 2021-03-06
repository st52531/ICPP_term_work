// Cv.04.0.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include "pch.h"
#include <iostream>

using namespace std;
struct Zvire {
	virtual ~Zvire() {  // když se volá destruktor potomka, tak se nejdříve zavolá destruktor předka, aby se zničil jako první.
		cout << "~Zvire" << endl;
	}
	virtual void vydejZvuk() {   // píše se virtual u předka aby se uplatnil polymorfismus
		cout << "(obecny zvuk)" << endl;
	}
};

struct Manba: Zvire {
	virtual ~Manba() {
		cout << "~Manba" << endl;
	}
	virtual void vydejZvuk() override {  // virtual a override nemusí být. Virtual pro přehlednost a override pro kontrolu dat. typu.
		cout << "Ssssssssss" << endl;
	}
};
struct Pes : Zvire {
	virtual ~Pes() {
		cout << "~Pes" << endl;
	}
	virtual void vydejZvuk() override{
		cout << "Haf haf" << endl;
	}
};

int main()
{
	Zvire** zvirata = new Zvire*[3];
	zvirata[0] = new Zvire{};
	zvirata[1] = new Manba{};
	zvirata[2] = new Pes{};

	for (int i = 0; i < 3; i++) {
		zvirata[i]->vydejZvuk();
	}

	for (int i = 0; i < 3; i++) {
		delete zvirata[i];
	}
	/*Zvire zvire{};
	zvire.vydejZvuk();

	Manba manba{};
	manba.vydejZvuk();

	Pes pes{};
	pes.vydejZvuk();*/
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
