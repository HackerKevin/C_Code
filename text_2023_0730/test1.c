#define _CRT_SECURE_NO_WARNINGS	1
#include <stdio.h>
//求十个整数中的最大值
int main()
{
	int a[10] = { 0 };
	int temp = 0;
	int i = 0;
	while (scanf("%d %d %d %d %d %d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5], &a[6], &a[7], &a[8], &a[9]) == 10)
	{
		for (i = 0; i <= 9; i++)
		{
			if (a[i] > temp)
				temp= a[i];
		}
		printf("最大值为：%d", temp);
	}
	return 0;
}