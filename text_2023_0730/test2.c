#define _CRT_SECURE_NO_WARNINGS	1
//计算1/1-1/2+1/3-1/4+1/5 …… + 1/99 - 1/100 的值，打印出结果
#include <stdio.h>
int main()
{
	double i = 0;
	double sum = 0;
	for (i = 1; i <= 100; i++)
	{
		sum += 1 / i;
	}
	printf("%lf", sum);
	return 0;
}