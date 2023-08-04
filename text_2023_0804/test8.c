#define _CRT_SECURE_NO_WARNINGS	1
//实现函数判断year是不是润年。
#include <stdio.h>
void IsLeapYear(int a)
{
	if ((0 == a % 4 && a % 100 != 0) || 0 == a % 400)
		printf("%d是闰年\n", a);
	else
		printf("%d不是闰年\n", a);
}
int main()
{
	int year = 0;
	while (scanf("%d", &year) != EOF)
		IsLeapYear(year);
	return 0;
}