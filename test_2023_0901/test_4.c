#define _CRT_SECURE_NO_WARNINGS	1
//写一个代码，实现字符串中的小写字母转大写，而其他字符不变。
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main()
{
	char str[] = "I am a stduent.";
	int len = strlen(str);
	for (int i = 0; i < len; i++)//遍历字符串
	{
		if (islower(str[i]))
		{
			str[i] = toupper(str[i]);//发现小写字母，转大写
		}
	}
	printf("%s\n", str);
	return 0;
}