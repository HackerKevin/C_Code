#define _CRT_SECURE_NO_WARNINGS	1
//实现一个函数is_prime，判断一个数是不是素数。
//利用上面实现的is_prime函数，打印100到200之间的素数。
#include <stdio.h>
#include <math.h>
int is_prime(int a)
{
	int j = 0;
	for (j = 2; j <= sqrt(a); j++)
	{
		if (a % j == 0)
			return 0;
		else if (j == sqrt(a))
			return 1;
	}
}

int main()
{
	int i = 0;
	for (i = 100; i <= 200; i++)
	{
		if (is_prime(i))
		{
			printf("%d ", i);
		}
		else
			continue;
	}
	return 0;
}