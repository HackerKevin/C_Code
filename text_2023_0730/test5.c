#define _CRT_SECURE_NO_WARNINGS	1
//����10����������ƽ��ֵ
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
			printf("ƽ��ֵ��%.1lf\n", average);
		}
		i++;
	}
	return 0;
}