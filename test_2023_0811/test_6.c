#define _CRT_SECURE_NO_WARNINGS	1
//在一个整型数组中，只有一个数字出现一次，其他数组都是成对出现的，请找出那个只出现一次的数字。
//例如：
//数组中有：1 2 3 4 5 1 2 3 4，只有5出现一次，其他数字都出现2次，找出5
#include <stdio.h>
int FindSingle(int* ptr, int sz)
{
	int a = 0;
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		a ^= *(ptr + i);
	}
	return a;
}
int main()
{
	int arr[] = { 1,2,3,4,5,1,2,3,4 };
	int sz = 0;
	sz = sizeof(arr) / sizeof(arr[0]);
	printf("只出现一次的数字是：%d", FindSingle(arr, sz));
	return 0;
}