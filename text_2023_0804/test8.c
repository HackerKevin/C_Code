#define _CRT_SECURE_NO_WARNINGS	1
//ʵ�ֺ����ж�year�ǲ������ꡣ
#include <stdio.h>
void IsLeapYear(int a)
{
	if ((0 == a % 4 && a % 100 != 0) || 0 == a % 400)
		printf("%d������\n", a);
	else
		printf("%d��������\n", a);
}
int main()
{
	int year = 0;
	while (scanf("%d", &year) != EOF)
		IsLeapYear(year);
	return 0;
}