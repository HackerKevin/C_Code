#define _CRT_SECURE_NO_WARNINGS	1
//求两个数二进制中不同位的个数
#include <stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	int i = 0;
	while (scanf("%d %d", &a, &b) != EOF)
	{
		int count = 0;
		for (i = 0; i < 32; i++)
		{
			if ((a & (1 << i)) != (b & (1 << i)))
				count++;
			else
				continue;
		}
		printf("%d和%d二进制中不同位的个数为：%d\n", a, b, count);
	}
	return 0;
	
}