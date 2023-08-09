#define _CRT_SECURE_NO_WARNINGS	1
//指针的应用：访问数组
#include <stdio.h>
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	//下标的方式访问
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	//指针的方式访问
	int j = 0;
	int* p = &arr[0];
	for (j = 0; j < sz; j++)
	{
		printf("%d ", *p);
		p = p + 1;
	}
	return 0;
}