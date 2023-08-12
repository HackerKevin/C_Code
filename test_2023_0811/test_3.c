#define _CRT_SECURE_NO_WARNINGS	1
//写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和
//例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是19
//输入：1729，输出：19
#include <stdio.h>
unsigned int DigitSum(int a)
{
	int Sum = 0;
	if (a / 10 == 0)
		return a % 10;
	else
		return Sum += (a % 10) + DigitSum(a / 10);
}
int main()
{
	unsigned int n = 0;
	while (scanf("%d", &n) != EOF)
	{
		printf("%d的各位数字之和为：%d\n", n, DigitSum(n));
	}
	return 0;
}