#define _CRT_SECURE_NO_WARNINGS	1
#include <iostream>
using namespace std;
class Car 
{
public:
	void Drive() {}
};
class Benz :public Car 
{
public:
	virtual void Drive() override { cout << "Benz-ÊæÊÊ" << endl; }
};