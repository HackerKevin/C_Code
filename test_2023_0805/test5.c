#define _CRT_SECURE_NO_WARNINGS	1
//写一个代码，判断一个数是否是2的n次方？
//分析：2^n这个数的二进制形式中只有一个1，如果去掉一个1后二进制中1的个数为0，则说明这个数是2的n次方
#include <stdio.h>
int main()
{
	int n = 0;
	while (scanf("%d", &n) != EOF)
	{
		if ((n & (n - 1)) == 0)//去掉一个1后判断二进制中1的个数是否为0
		{
			printf("yes\n");
		}
		else
			printf("no\n");
	}
	return 0;
}