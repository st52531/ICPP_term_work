
#include "pch.h"
#include <iostream>
#include "Hodnota.h"
#include "Operator.h"
#include "Kalkulator.h"

using namespace std;

int main()
{
	Hodnota hodnota;
	Kalkulator<Hodnota, 2> kalk;
	kalk.pridejHodnotu(2);
	kalk.pridejOperator("+");
}