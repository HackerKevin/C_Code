#define _CRT_SECURE_NO_WARNINGS	1
#include <iostream>
using namespace std;
class A//继承
{
public:
	void Func() {}
protected:
	int _a1;
	int _a2;
};
class B :public A
{
};
class C
{
public:
	void Func(){}
protected:
	int _c1;
	int _c2;
};
class D//对象组合
{
private:
	C _cc;
};
int main()
{
}