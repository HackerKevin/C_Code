#define _CRT_SECURE_NO_WARNINGS	1
//协变的理解
#include <iostream>
using namespace std;
class A {};
class B : public A {};
class Person 
{
public:
	virtual A* BuyTicket() 
	{ 
		cout << "买票-全价" << endl; 
		return nullptr;
	}
};
class Student : public Person 
{
public:
	virtual B* BuyTicket()
	{
		cout << "买票-半价" << endl;
		return nullptr;
	}
	/*virtual int BuyTicket() 
	{ 
		cout << "买票-半价" << endl; 
		return 0;
	}*/
};
void Func(Person& p)
{
	p.BuyTicket();
}
int main()
{
	Person ps;
	Student st;
	Func(ps);
	Func(st);
	return 0;
}