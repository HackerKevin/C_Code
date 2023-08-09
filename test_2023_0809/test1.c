#define _CRT_SECURE_NO_WARNINGS	1
//理解指针变量的大小
//指针变量的⼤⼩取决于地址的⼤⼩
//32位平台下地址是32个bit位（即4个字节）
//64位平台下地址是64个bit位（即8个字节）
#include <stdio.h>
int main()
{
	printf("%zd\n", sizeof(char*));
	printf("%zd\n", sizeof(short*));
	printf("%zd\n", sizeof(int*));
	printf("%zd\n", sizeof(double*));
	return 0;
}
