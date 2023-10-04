#define _CRT_SECURE_NO_WARNINGS	1
//const成员函数理解
#include <iostream>
using namespace std;
class A
{
public:
	A* operator&()
	{
		return nullptr;
	}
	const A* operator&() const
	{
		return nullptr;
	}
private:
	int _a = 10;
};
int main()
{
	A aa;
	const A bb;

	cout << &aa << endl;
	cout << &bb << endl;
	return 0;
}