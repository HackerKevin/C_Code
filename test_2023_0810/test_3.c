#define _CRT_SECURE_NO_WARNINGS	1
//strlen的模拟实现
#include <stdio.h>
#include <assert.h>
size_t my_strlen(const char* str)
{
	size_t count = 0;
	assert(str != NULL);
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}
int main()
{
	char arr[] = "abcdef";
	int len = my_strlen(arr);
	printf("%d\n", len);
	return 0;
}