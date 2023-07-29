#define _CRT_SECURE_NO_WARNINGS	1
#include <stdio.h>
int GetDaysOfYear(int a, int b, int c)
{
	if ((0 == a % 4 && 0 != a % 100) || 0 == a % 400)
	{
		int LeapYear[] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
		int count = 0;
		for (int i = 1; i <= b-1; i++)
		{
			count += LeapYear[i];
			//for (int j = 1; j <= c; j++)
			//{
				//count++;
			//}
		}
		count += c;
		return count;
	}
	else
	{
		int LeapYear[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		int count = 0;
		for (int i = 1; i <= b - 1; i++)
		{
			count += LeapYear[i];

		}
		count += c;
		return count;
	}
}
int main()
{
	int x, y, z = 0;
	scanf("%d%*c%d%*c%d%", &x, &y, &z);
	//printf("%d %d %d", x, y, z);
	printf("该日期是今年的第%d天\n", GetDaysOfYear(x, y, z));
	return 0;
}