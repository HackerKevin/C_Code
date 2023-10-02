#define _CRT_SECURE_NO_WARNINGS	1
//this指针为空时
#include <iostream>
using namespace std;
class A
{
public:
	void Print()
	{
		cout << "Print()" << endl;
	}
private:
	int _a;
};
void test1()
{
	A* p = nullptr;//空指针
	p->Print();
}
void test2()
{
	A* p = nullptr;//空指针
	(*p).Print();
}
int main()
{
	test1();
	test2();
	return 0;
}