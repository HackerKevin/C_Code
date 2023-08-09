#define _CRT_SECURE_NO_WARNINGS	1
//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以喝多少汽水（编程实现）。
#include <stdio.h>
int Beverage(int money)
{
	static int beverage = 0;
	int lid = 0;
	while (money)
	{
		lid++;
		beverage++;
		money--;
	}
	lid /= 2;
	if (lid != 0)
		Beverage(lid);
	return beverage;
}
int main()
{
	int n = 20;
	printf("可以喝%d瓶汽水", Beverage(n));
	return 0;
}