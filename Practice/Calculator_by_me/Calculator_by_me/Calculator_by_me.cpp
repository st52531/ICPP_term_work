#include "pch.h"
#include <iostream>
#include "kalkulator.h"

int main()
{
	Kalkulator<double, 2> k{};
	k.pridejHodnotu(5);
	k.pridejOperator('*');
	k.pridejHodnotu(6);
	k.pridejOperator('+');
	k.pridejHodnotu(3.3333333);

	cout<<k.vypocitej()<<endl;
}
