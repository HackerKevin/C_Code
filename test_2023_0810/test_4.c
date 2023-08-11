#define _CRT_SECURE_NO_WARNINGS	1
//数组名理解
#include <stdio.h>
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	printf("&arr[0]   = %p\n", &arr[0]);
	printf("&arr[0]+1 = %p\n", &arr[0] + 1);
	printf("arr       = %p\n", arr);
	printf("arr+1     = %p\n", arr + 1);
	printf("&arr      = %p\n", &arr);
	printf("&arr+1    = %p\n", &arr + 1);
	return 0;
}