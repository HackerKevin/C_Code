#define _CRT_SECURE_NO_WARNINGS	1
//给定两个数，求这两个数的最大公约数
//例如：
//输入：20 40
//输出：20
#include <stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	int Y = 1;
	scanf("%d %d", &a, &b);
	//辗转相除法实现求最大公约数
	while(Y)//如果余数为0说明找到最大公约数
	{
		if (a % b == a)//说明b比a大
		{
			Y = b % a;
			if (Y != 0)
			{
				b = Y;
				continue;
			}
		}
		else//a比b大
		{
			Y = a % b;
			if (Y != 0)
			{
				a = Y;
				continue;
			}
			
		}
	}
	if (a > b)
		printf("最大公约数是：%d", b);
	else
		printf("最大公约数是：%d", a);
	return 0;
}