#define _CRT_SECURE_NO_WARNINGS	1
//抽象类理解
#include <iostream>
using namespace std;

class Car
{
public:
	virtual void Drive() = 0;
};
class Benz :public Car
{
public:
};
class BMW :public Car
{
public:
	virtual void Drive()
	{
		cout << "BMW-操控" << endl;
	}
};

int main()
{
	
	BMW bmw;
	bmw.Drive();
	//Car* pBenz = new Benz;
	//pBenz->Drive();
	//Car* pBMW = new BMW;
	//pBMW->Drive();
	return 0;
} 