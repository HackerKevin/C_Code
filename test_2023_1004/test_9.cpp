#define _CRT_SECURE_NO_WARNINGS	1
//初始化列表理解
#include <iostream>
using namespace std;
class A
{
public:
	A(int a)//不是A的默认构造函数
		:_a(1)
	{}
	void Print()
	{
		cout << _a;
	}
private:
	int _a;
};
class B
{
public:
	B(int a = 1, int ref = 1)
		: _aobj(1)
		, _ref(ref)
		/*, _n(10)*/
	{}
	void Print()
	{
		_aobj.Print();
		cout << " " << _ref << " " << _n << endl;
	}
private:
	A _aobj;      // 没有默认构造函数
	int& _ref;	  // 引用
	const int _n; // const 
};

int main()
{
	B bb;
	bb.Print();
	return 0;
}




