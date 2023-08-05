#define _CRT_SECURE_NO_WARNINGS	1
//输入一个数，用按位或将第n位变为1
#include <stdio.h>
int main()
{
	int a = 0;
	int n = 0;
	printf("请输入一个数以及你想观察的位数：");
	scanf("%d %d", &a, &n);
	printf("%d二进制形式下从右往左数的第%d位是%d\n", a, n, a >> n - 1 & 1);
	return 0;
}