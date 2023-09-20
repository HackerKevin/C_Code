#define _CRT_SECURE_NO_WARNINGS	1
#include <stdio.h>
int check_sys()
{
	int a = 1;
	return (*(char*)&a);//小端返回1，大端返回0
}
int main()
{
	if (check_sys() == 1)
		printf("小端\n");
	else
		printf("大端\n");
	return 0;
}