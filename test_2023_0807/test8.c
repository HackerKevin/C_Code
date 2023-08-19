#define _CRT_SECURE_NO_WARNINGS	1
//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以喝多少汽水（编程实现）。
#include <stdio.h>
int Beverage(int money)
{
	int total = money;
	int empty = money;
	while (empty > 1)
	{
		total += empty / 2;
		empty = empty / 2 + empty % 2;
	}
	return total;
}

int main()
{
	int n = 0;
	while (scanf("%d", &n) != EOF)
	{
		printf("可以喝%d瓶汽水\n", Beverage(n));
	}
	return 0;
}
