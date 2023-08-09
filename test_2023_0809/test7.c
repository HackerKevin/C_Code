#define _CRT_SECURE_NO_WARNINGS	1
//指针的关系运算
#include <stdio.h>
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int* p = arr;//数组名就是数组首元素的地址
	while (p < arr + sz)//arr+sz 是数组结束标志处（\0）的地址
	{
		printf("%d ", *p);
		p++;
	}
	return 0;
}