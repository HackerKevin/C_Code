#define _CRT_SECURE_NO_WARNINGS	1
//strlen函数模拟实现
#include <stdio.h>
#include <string.h>
#include <assert.h>
size_t my_strlen(const char* str)
{
	assert(str != NULL);
	if (*str == '\0')
		return 0;
	else
		return 1 + my_strlen(str + 1);
}
int main()
{
	char arr[] = "abcdef";
	size_t len = my_strlen(arr);
	printf("%zd\n", len);
	return 0;
}