#define _CRT_SECURE_NO_WARNINGS	1
//1到 100 的所有整数中出现多少个数字9
#include <stdio.h>
int main()
{
	int i = 0;
	int count = 0;
	for (i = 1; i <= 100; i++)
	{
		if (9 == i % 10)
			count++;
		else
			continue;
	}
	printf("1到100的所有整数中出现%d个数字9", count);
	return 0;
}