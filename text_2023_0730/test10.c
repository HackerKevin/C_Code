#define _CRT_SECURE_NO_WARNINGS	1
//打印1000年到2000年之间的闰年
#include <stdio.h>

int main()
{
	int i = 1000;
	int j = 0;
	int flag = 1;
	while (flag)//找到1000年后的第一个闰年
	{
		if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
		{
			flag = 0;
		}
		else
			i++;
	}
	for (j = i; j <= 2000; j+=4)
	{
		printf("%d ", j);
	}
	return 0;
}