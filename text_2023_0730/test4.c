#define _CRT_SECURE_NO_WARNINGS	1
//打印100~200之间的素数
#include <stdio.h>
#include <math.h>
int main()
{
	int i = 0;
	for (i = 100; i <= 200; i++)
	{
		int j = 0;
		int flag = 1;
		for (j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0)
			{
				flag = 0;
				break;
			}
		}
		if (1 == flag)
			printf("%d ", i);
	}
	return 0;
}