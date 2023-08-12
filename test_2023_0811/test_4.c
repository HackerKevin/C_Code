#define _CRT_SECURE_NO_WARNINGS	1
//递归和非递归分别实现求n的阶乘（不考虑溢出的问题）
#include <stdio.h>
int Fact1(int n)
{
	if (n == 0)
		return 1;
	else
		return n * Fact1(n - 1);
}
int Fact2(int n)
{
	int Sum = 1;
	int i = 0;
	for (i = 1; i <= n; i++)
	{
		Sum *= i;
	}
	return Sum;
}
int main()
{
	int n = 0;
	while (scanf("%d", &n) != EOF)
	{
		printf("递归实现：%d的阶乘为：%d\n", n, Fact1(n));
		printf("循环实现：%d的阶乘为：%d\n", n, Fact2(n));
	}
	return 0;
}