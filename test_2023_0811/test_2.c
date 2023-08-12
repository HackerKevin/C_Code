#define _CRT_SECURE_NO_WARNINGS	1
//递归实现n的k次方
#include <stdio.h>
int pow(int n, int k)
{
	if (k == 0)
		return 1;
	else
		return n * pow(n, k - 1);
}
int main()
{
	int n = 0;
	int k = 0;
	while (scanf("%d %d", &n, &k) != EOF)
	{
		printf("%d的%d次方为：%d\n", n, k, pow(n, k));
	}
	
	return 0;
}