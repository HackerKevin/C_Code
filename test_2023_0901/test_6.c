#define _CRT_SECURE_NO_WARNINGS	1
//strcpy模拟实现
#include <stdio.h>
#include <string.h>
#include <assert.h>

char* my_strcpy(char* dest, const char* src)
{
	char* ret = dest;
	assert(dest && src);
	while (*dest++ = *src++)
	{
		;
	}
	return ret;//返回目标空间起始地址
}
int main()
{
	char arr1[] = "abcdef";
	char arr2[20] = { 0 };
	
	printf("%s", my_strcpy(arr2, arr1));
	return 0;
}