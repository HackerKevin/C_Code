#define _CRT_SECURE_NO_WARNINGS	1
//常见的动态内存错误
#include <stdio.h>
#include <stdlib.h>
void test1()
{
	int* p = (int*)malloc(INT_MAX / 4);
	*p = 20;//如果p的值是NULL，就会有问题
	free(p);
}
void test2()
{
	int i = 0;
	int* p = (int*)malloc(10 * sizeof(int));//开辟40个字节即10个整型的空间
	if (NULL == p)
	{
		exit(EXIT_FAILURE);
	}
	for (i = 0; i <= 10; i++)
	{
		*(p + i) = i;//当i是10的时候越界访问
	}
	free(p);
}
void test3()
{
	int a = 10;
	int* p = &a;
	free(p);//ok?
}
void test4()
{
	int* p = (int*)malloc(100);
	p++;//p不再指向动态内存的起始位置
	free(p);
}
void test5()
{
	int* p = (int*)malloc(100);
	free(p);
	free(p);//重复释放
}
void test6()
{
	int* p = (int*)malloc(100);
	if (NULL != p)
	{
		*p = 20;
	}
}
int main()
{
	test6();
	return 0;
}