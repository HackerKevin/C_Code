#define _CRT_SECURE_NO_WARNINGS	1
//定位new理解
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
	~A()
	{
		cout << "~A():" << this << endl;
	}
private:
	int _a;
};
// 定位new/replacement new
int main()
{
	// p1现在指向的只不过是与A对象相同大小的一段空间，还不能算是一个对象，因为构造函数没有执行
	A* p1 = (A*)malloc(sizeof(A));
	new(p1)A;  // 注意：如果A类的构造函数有参数时，此处需要传参
	p1->~A();
	free(p1);
	A* p2 = (A*)operator new(sizeof(A));
	new(p2)A(10);
	p2->~A();
	operator delete(p2);
	return 0;
}