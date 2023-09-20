#define _CRT_SECURE_NO_WARNINGS	1
#include <stdio.h>
#include <string.h>
int main()
{
	char arr1[] = "aacdef";
	char arr2[] = "abcdef"; 
	char arr3[] = "abcdef";
	char arr4[] = "accdef";
	int ret1 = memcmp(arr1, arr2, 2);
	int ret2 = memcmp(arr2, arr3, 2);
	int ret3 = memcmp(arr4, arr3, 2);
	printf("%d\n", ret1);
	printf("%d\n", ret2);
	printf("%d\n", ret3);
	return 0;
}