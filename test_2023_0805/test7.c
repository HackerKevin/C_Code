#define _CRT_SECURE_NO_WARNINGS	1
//用按位取反将指定位变0
#include <stdio.h>
int main()
{
	int a = 0;
	int n = 0;
	printf("输入一个数，以及你想让它的第几位变为0？\n");
	scanf("%d %d", &a, &n);
	a = a & ~(1 << n - 1);//将a的二进制中第n位改成0
	printf("这个数的第%d位变为0后产生的数为：%d", n, a);
	return 0;
}