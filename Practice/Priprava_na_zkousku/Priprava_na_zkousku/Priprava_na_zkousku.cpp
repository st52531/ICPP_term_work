#include "pch.h"
#include <iostream>
//#include "matrix.h"
#include"Cat.h"
#include"Dog.h"
#include"Singleton.h"
using namespace std;

int main()
{
	/*string s = "matrix.txt";
	Matrix* m = new Matrix{s};
	m->vypisMatici(m);
	m->zapisDoSouboru("matrix_out.txt",m);
	delete m;*/

	Cat c{ 4 };
	cout << c.MakeSound() << endl;
	Animal& a = c;
	cout << dynamic_cast<Cat&>(a).purr() << endl;
	Dog d{ 4 };
	cout << d.MakeSound() << endl;

	/*Singleton* s = Singleton::getInstance();
	s->WriteToConsole("sdfdsfsf");
	delete s;*/

	/*int i = 4;
	int& refi = i;
	int* pointi = &i;
	refi = 8;
	cout << i << endl;
	*pointi = 50;
	cout << i << endl;*/
}