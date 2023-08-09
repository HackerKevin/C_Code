#define _CRT_SECURE_NO_WARNINGS	1
//scanf不同返回值测试
#include <stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	char c = 0;
	if (scanf("%d %d",&a, &b) == 2)
	{
		printf("1");
	}
	else if (scanf("%c %d %d", &c, &a, &b) == 3)
	{
		printf("2");
	}
	return 0;
}