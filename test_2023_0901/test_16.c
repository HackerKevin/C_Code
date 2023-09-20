#define _CRT_SECURE_NO_WARNINGS	1
//百度笔试题：设计一个小程序，判断当前机器的字节序。
#include <stdio.h>
int main()
{
	int a = 1;
	if (*((char*)&a) == 1)
		printf("小端\n");
	else
		printf("大端\n");
	return 0;
}
