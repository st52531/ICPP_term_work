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

	string potrubi{ oss.str() };

	istringstream iss{
		iss.str(potrubi);
	};

	int rozmer;
	iss >> rozmer;

	for (int i = 0; i < rozmer; i++) {
		string radek{};
		getline(iss, radek);

		for (int j = 0; j < rozmer; j++) {
			cout << radek[j] << ",";
		}
	}

	if (iss.peek()) {

	}

	for (int i = 0; i < rozmer; i++) {
		string str{};
		getline(iss, str);
		for (int j = 0; j < rozmer; j++) {
			cout << str[j] << ';';
		}
		cout << endl;
	}
}

