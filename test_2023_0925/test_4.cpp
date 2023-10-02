#define _CRT_SECURE_NO_WARNINGS	1
//函数重载理解
#include <iostream>
using namespace std;
//一、参数类型不同
int Add(int left, int right)
{
	cout << "int Add(int left, int right)" << endl;
	return left + right;
}
double Add(double left, double right)
{
	cout << "double Add(double left, double right)" << endl;
	return left + right;
}
//二、参数个数不同
void f()
{
	cout << "f()" << endl;
}
void f(int a)
{
	cout << "f(int a)" << endl;
}
//三、参数类型顺序不同
void f(int a, char b)
{
	cout << "f(int a,char b)" << endl;
}
void f(char b, int a)
{
	cout << "f(char b, int a)" << endl;
}

int main()
{
	Add(10, 20);
	Add(10.1, 20.2);
	f();
	f(10);
	f(10, 'a');
	f('a', 10);
	return 0;
}