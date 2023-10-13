#define _CRT_SECURE_NO_WARNINGS	1
#include <iostream>
using namespace std;
class A
{
public:
	A(int a = 0)
		: _a(a)
	{
		cout << "A():" << this << endl;
	}
	/*~A()
	{
		cout << "~A():" << this << endl;
	}*/
private:
	int _a;
};
int main()
{
	A* p9 = new A[10];
	/*delete p9;*/
	/*free(p9);*/
	delete[] p9;
	return 0;
}