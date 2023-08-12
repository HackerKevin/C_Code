#define _CRT_SECURE_NO_WARNINGS	1
//递归方式实现打印一个整数的每一位
#include <stdio.h>
int print(int a,int n)
{
	if (n != 1)
	{
		int temp = a;
		int b = n;
		while (b > 1)
		{
			temp /= 10;
			b--;
		}
		printf("%d ", temp%10);
		print(a , n - 1);
	}
	else
		printf("%d\n", a % 10);
}
int main()
{
	int n = 0;
	while (scanf("%d", &n) != EOF)
	{
		
		int digit = 0;//获取位数
		int b = n;
		while (b != 0)
		{
			digit++;
			b /= 10;
		}
		print(n,digit);
	}
	return 0;
}