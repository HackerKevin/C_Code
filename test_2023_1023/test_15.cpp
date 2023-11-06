#define _CRT_SECURE_NO_WARNINGS	1
//实现一个不能被继承的类
#include <iostream>
using namespace std;
class A
{
public:
	static A CreatObj()
	{
		return A();
	}
private:
	A()
	{}
};

class B :public A
{};
int main()
{
	A::CreatObj();
	return 0;
}