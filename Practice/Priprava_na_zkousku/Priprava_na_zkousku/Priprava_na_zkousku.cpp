#include "pch.h"
#include <iostream>
#include "matrix.h"

using namespace std;

int main()
{
	string s = "matrix.txt";
	Matrix* m = new Matrix{s};
	m->vypisMatici(m);
	m->zapisDoSouboru("matrix_out.txt",m);
	delete m;
}

