#define _CRT_SECURE_NO_WARNINGS	1
#include <stdio.h>
int check_sys()
{
	int a = 1;
	return (*(char*)&a);//С�˷���1����˷���0
}
int main()
{
	if (check_sys() == 1)
		printf("С��\n");
	else
		printf("���\n");
	return 0;
}