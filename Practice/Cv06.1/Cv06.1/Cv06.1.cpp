#include "RostouciKontejner.h"
#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	RostouciKontejner<int> rk{};
	for (int i = 0; i < 100; i++)
		rk.pridej(10*i);
	cout << rk[54] << " " << rk[22] << endl;

	RostouciKontejner<int>*ptr = new RostouciKontejner<int>{};
	ptr->pridej(10);
	ptr->pridej(20);
	ptr->pridej(30);

	ptr->pridejNa(1, 999);

	return 0;
}
