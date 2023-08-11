#define _CRT_SECURE_NO_WARNINGS	1
//写⼀个函数，交换两个整型变量的值
#include <stdio.h>
void Swap2(int* px, int* py)
{
	int tmp = 0;
	tmp = *px;
	*px = *py;
	*py = tmp;
}

int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	printf("交换前：a=%d b=%d\n", a, b);
	Swap2(&a, &b);
	printf("交换后：a=%d b=%d\n", a, b);
	return 0;
}

