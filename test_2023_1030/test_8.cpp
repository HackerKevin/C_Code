#define _CRT_SECURE_NO_WARNINGS	1
//Э������
#include <iostream>
using namespace std;
class A {};
class B : public A {};
class Person 
{
public:
	virtual A* BuyTicket() 
	{ 
		cout << "��Ʊ-ȫ��" << endl; 
		return nullptr;
	}
};
class Student : public Person 
{
public:
	virtual B* BuyTicket()
	{
		cout << "��Ʊ-���" << endl;
		return nullptr;
	}
	/*virtual int BuyTicket() 
	{ 
		cout << "��Ʊ-���" << endl; 
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