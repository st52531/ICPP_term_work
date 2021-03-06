// Cv05.1.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include "pch.h"
#include <iostream>
#include "TelefonniSeznam.h"
#include "Osoba.h"
#include "MyException.h"

using namespace Model;
using namespace Entity;
using namespace std;
int main()
{
	try {

		TelefonniSeznam seznam{};

		Osoba o1 = Osoba{ "John", "789546212",0 };
		Osoba o2 = Osoba{ "Pete", "7465465462",1 };
		Osoba o3 = Osoba{ "Dumbass", "765442112",2 };
		Osoba o4 = Osoba{ "Michael", "2214542",3 };
		Osoba o5 = Osoba{ "Steve", "785678612",4 };

		seznam.pridejOsobu(o1);
		seznam.pridejOsobu(o2);
		seznam.pridejOsobu(o3);
		seznam.pridejOsobu(o4);
		seznam.pridejOsobu(o5);

		cout << "Telefon osoby s id 3 je: " << seznam.najdiTelefon(3) << endl;
		cout << "Telefon osoby s se Jmenem Steve je: " << seznam.najdiTelefon("Steve") << endl;

		seznam.najdiTelefon(6);

		seznam.smazSeznam();
	}
	catch (WrongInputException & ex) {
		cout << ex.getMessage() << endl;
	}
	catch (NoSuchElementException & ex) {
		cout << ex.getMessage() << endl;
	}
}

