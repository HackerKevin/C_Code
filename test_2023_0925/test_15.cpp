#define _CRT_SECURE_NO_WARNINGS	1
//thisָ��Ϊ��ʱ
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
	A* p = nullptr;//��ָ��
	p->Print();
}
void test2()
{
	A* p = nullptr;//��ָ��
	(*p).Print();
}
int main()
{
	test1();
	test2();
	return 0;
}