#define _CRT_SECURE_NO_WARNINGS	1
//递归和非递归分别实现求第n个斐波那契数
//例如：
//输入：5  输出：5
//输入：10， 输出：55
//输入：2， 输出：1
#include <stdio.h>
//循环实现
int Fib1(int n)
{
	int a = 1;
	int b = 1;
	int c = 1;
	while (n > 2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}
//递归实现
int Fib2(int n)
{
	if (n == 1 || n == 2)
		return 1;
	else
		return Fib2(n - 1) + Fib2(n - 2);
}
int main()
{
	int n = 0;
	while (scanf("%d", &n) != EOF)
	{
		printf("循环实现：第%d个斐波那契数是：%d\n", n, Fib1(n));
		printf("递归实现：第%d个斐波那契数是：%d\n", n, Fib2(n));
		
	}
	return 0;
}