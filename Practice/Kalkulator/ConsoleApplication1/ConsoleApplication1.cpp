#include "stdafx.h"
#include <iostream>
#include "PrvekVyrazu.h"
#include "Hodnota.h"
#include "Operator.h"
#include "Kalkulator.h"

using namespace std;

int main()
{
	Kalkulator<double, 2> k{};
	k.pridejHodnotu(-2);
	k.pridejOperator('+');
	k.pridejHodnotu(200);
	k.pridejOperator('*');
	k.pridejHodnotu(3.142562);
	k.pridejOperator('-');
	k.pridejHodnotu(5.20569);

	try {
		cout << k.vypocitej() << endl;
	}
	catch (const VyjimkaKalkulatoru& vk) {
		cout << "Vyjimka!" << endl;
	}
    return 0;
}

