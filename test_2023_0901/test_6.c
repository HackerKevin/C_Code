#define _CRT_SECURE_NO_WARNINGS	1
//strcpyģ��ʵ��
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
	return ret;//����Ŀ��ռ���ʼ��ַ
}
int main()
{
	char arr1[] = "abcdef";
	char arr2[20] = { 0 };
	
	printf("%s", my_strcpy(arr2, arr1));
	return 0;
}