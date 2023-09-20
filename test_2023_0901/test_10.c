#define _CRT_SECURE_NO_WARNINGS	1
//strstr理解
#include <stdio.h>
#include <assert.h>
char* my_strstr(const char* str1, const char* str2)
{
	assert(str1 && str2);
	const char* cp = str1;//最好加const，否则编译器会警告，因为把一个不可修改的指针赋给一个可修改的指针是不安全的
	const char* s1 = NULL;
	const char* s2 = NULL;
	if (*str2 == '\0')
		return str1;//特殊处理，如果子串是空字符串，就直接返回str1
	while (*cp)
	{
		s1 = cp;
		s2 = str2;
		while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')//s2已经匹配完了，说明已经找到
			return cp;
		cp++;//没找到，从下一个字符重新匹配
	}
	return NULL;
}
int main()
{
	char arr1[] = "abcdefg";
	char arr2[] = "def";
	char arr3[] = "defq";
	char* ret1 = my_strstr(arr1, arr2);
	char* ret2 = my_strstr(arr1, arr3);
	printf("%s\n", ret1);
	printf("%s\n", ret2);
	return 0;
}