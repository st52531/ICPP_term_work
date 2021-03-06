#include "RostouciKontejner.h"
#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	try {
		RostouciKontejner<int> rk{};
		for (int i = 0; i < 100; i++)
			rk.pridej(10 * i);
		cout << rk[54] << " " << rk[22] << endl;

		RostouciKontejner<int>* ptr = new RostouciKontejner<int>{};
		ptr->pridej(10);
		ptr->pridej(20);
		ptr->pridej(30);

		cout << (*ptr)[1] << endl;

		ptr->pridejNa(1, 999);
		ptr->odeber(3);
		cout << endl;
		cout << (*ptr)[0] << endl;
		cout << (*ptr)[1] << endl;
		cout << (*ptr)[2] << endl;
		//cout << (*ptr)[3]<<endl;
	}
	catch (out_of_range& ex) {
		cout << ex.what() << endl;
	}
	catch (...) {
		cout << "Another exception caught" << endl;
	}
	return 0;
}
