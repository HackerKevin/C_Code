#define _CRT_SECURE_NO_WARNINGS	1
//取地址操作符理解
#include <stdio.h>
int main()
{
	int a = 10;
	&a;//取出a的地址
	printf("%p", &a);
	return 0;
}


