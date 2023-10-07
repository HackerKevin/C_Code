#define _CRT_SECURE_NO_WARNINGS	1
//static¿ÌΩ‚
#include <iostream>
using namespace std;
class A
{
public:
	A(int a = 0) { ++_scount; }
	A(const A& t) { ++_scount; }
	/*~A() { --_scount; }*/
	static int GetACount() { return _scount; }
private:
	static int _scount;
};
int A::_scount = 0;
void Test()
{
	A a1 = 1, a2 = 1;
	A a3(a1);
}
int main()
{
	Test();
	/*A* ptr = nullptr;*/
	/*cout << A::GetACount() << endl;*/
	cout << A::GetACount() << endl;
	/*cout << a2.GetACount() << endl;
	cout << ptr->GetACount() << endl;*/
	return 0;
}
