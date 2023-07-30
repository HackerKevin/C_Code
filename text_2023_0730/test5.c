#define _CRT_SECURE_NO_WARNINGS	1
//输入10个整数，求平均值
#include <stdio.h>
int main()
{
	int a[10] = {0};
	int i = 0;
	int sum = 0;
	double average = 0;
	while ((scanf("%d", &a[i]) != EOF))
	{
		sum += a[i];
		if (9 == i)
		{
			average = sum / 10.0;
			printf("平均值是%.1lf\n", average);
		}
		i++;
	}
	return 0;
}