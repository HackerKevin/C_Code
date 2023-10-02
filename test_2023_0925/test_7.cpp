#define _CRT_SECURE_NO_WARNINGS	1
//引用和指针的区别
#include <iostream>
using namespace std;
void test1()
{
	int a = 10;
	int& ra = a;
	cout << "&a = " << &a << endl;
	cout << "&ra = " << &ra << endl;

}
void test2()
{
	int a = 10;
	int& ra = a;
	ra = 20;
	int* pa = &a;
	*pa = 20;
}
int main()
{
	test2();
	return 0;
}