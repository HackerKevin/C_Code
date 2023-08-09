#define _CRT_SECURE_NO_WARNINGS	1
//const修饰指针变量	
#include <stdio.h>
//测试⽆const修饰的情况
void test1()
{
	int n = 10;
	int m = 20;
	int* p = &n;
	*p = 20;//ok?
	p = &m; //ok?
}
//测试const放在*的左边情况
void test2()
{
	int n = 10;
	int m = 20;
	const int* p = &n;
	*p = 20;//ok?
	p = &m; //ok?
}
//测试const放在*的右边情况
void test3()
{
	int n = 10;
	int m = 20;
	int* const p = &n;
	*p = 20; //ok?
	p = &m; //ok?
}
//测试*的左右两边都有const的情况
void test4()
{
	int n = 10;
	int m = 20;
	int const* const p = &n;
	*p = 20; //ok?
	p = &m; //ok?
}
int main()
{
	test1();
	test2();
	test3();
	test4();
	return 0;
}
