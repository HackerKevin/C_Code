#define _CRT_SECURE_NO_WARNINGS	1
//输入一个整数 n ，输出该数32位二进制表示中1的个数。其中负数用补码表示。
//数据范围：
//−2147483648 <= n <= 2147483647
#include <stdio.h>
int main()
{
	int n = 0;
	while (scanf("%d", &n) != EOF)
	{
		int count = 0;
		while (n)
		{
			count++;
			n &= (n - 1);
		}
		printf("%d\n", count);
	}
	return 0;
}