#define _CRT_SECURE_NO_WARNINGS	1
//strcat函数模拟实现
#include <stdio.h>
#include <string.h>
#include <assert.h>
char* my_strcat(char* dest, const char* src)
{
	char* ret = dest;
	assert(dest && src);
	while (*dest != '\0')
	{
		dest++;
	}
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}
int main()
{
	char arr1[20] = "hello ";
	char* p = "world";
	printf("%s\n", strcat(arr1, arr1));
	return 0;
}