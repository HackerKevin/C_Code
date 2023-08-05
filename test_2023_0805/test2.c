#define _CRT_SECURE_NO_WARNINGS	1
//输入一个数，看它二进制形式下从右往左数的第n位是几
#include <stdio.h>
int main()
{
	int a = 0;
	int n = 0;
	while (printf("请输入一个数以及你想观察的位数："), scanf("%d %d", &a, &n) != EOF)
	{
		printf("%d二进制形式下从右往左数的第%d位是%d\n", a, n, a >> n - 1 & 1);
	}
	return 0;
}