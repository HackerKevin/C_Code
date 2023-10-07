#define _CRT_SECURE_NO_WARNINGS	1
//编译器对拷贝对象时的一些优化
#include <iostream>
using namespace std;
class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A(int a)" << endl;
	}
	A(const A& aa)
		:_a(aa._a)
	{
		cout << "A(const A& aa)" << endl;
	}
	A& operator=(const A& aa)
	{
		cout << "A& operator=(const A& aa)" << endl;
		if (this != &aa)
		{
			_a = aa._a;
		}
		return *this;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};
void Fun1(A aa)
{

}
void Fun2(const A& aa)
{

}
A Fun3()
{
	A aa;//构造
	return aa;//拷贝构造
}
A Fun4()
{
	return A();
}
int main()
{
	A aa1 = 1;//构造+拷贝构造->优化为直接构造
	cout << "-----" << endl;
	Fun3();//无优化
	cout << "-----" << endl;
	A aa2 = Fun3();//本来应该是一个构造，两个拷贝构造，但被编译器优化为一个构造和一个拷贝构造
	cout << "-----" << endl;
	Fun4();
	A aa3 = Fun4();
	cout << "-----" << endl;
	return 0;
}
