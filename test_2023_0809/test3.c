#define _CRT_SECURE_NO_WARNINGS	1
//理解指针加减整数
#include <stdio.h>
int main()
{
	int n = 10;
	char* pc = (char*)&n;
	int* pi = &n;
	printf("%p\n", &n);
	printf("%p\n", pc);
	printf("%p\n", pc + 1);
	printf("%p\n", pi);
	printf("%p\n", pi + 1);
	return 0;
}
