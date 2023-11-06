#define _CRT_SECURE_NO_WARNINGS	1
//final¿ÌΩ‚
#include <iostream>
using namespace std;
class Car
{
public:
	virtual void Drive() final {}
};
class Benz :public Car
{
public:
	virtual void Drive() { cout << "Benz- Ê  " << endl; }
};
