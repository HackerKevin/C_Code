#define _CRT_SECURE_NO_WARNINGS	1
//strstr���
#include <stdio.h>
#include <assert.h>
char* my_strstr(const char* str1, const char* str2)
{
	assert(str1 && str2);
	const char* cp = str1;//��ü�const������������ᾯ�棬��Ϊ��һ�������޸ĵ�ָ�븳��һ�����޸ĵ�ָ���ǲ���ȫ��
	const char* s1 = NULL;
	const char* s2 = NULL;
	if (*str2 == '\0')
		return str1;//���⴦������Ӵ��ǿ��ַ�������ֱ�ӷ���str1
	while (*cp)
	{
		s1 = cp;
		s2 = str2;
		while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')//s2�Ѿ�ƥ�����ˣ�˵���Ѿ��ҵ�
			return cp;
		cp++;//û�ҵ�������һ���ַ�����ƥ��
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