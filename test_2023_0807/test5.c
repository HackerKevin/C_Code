#define _CRT_SECURE_NO_WARNINGS	1
//指针变量和解引用操作符理解
#include <stdio.h>
int main()
{
	int a = 10;
	int* pa = &a;//取出a的地址并存储到指针变量pa中
	printf("%d\n", a);
	*pa = 0;//解引用操作符
	printf("%d\n", a);
	return 0;
}