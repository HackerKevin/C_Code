#define _CRT_SECURE_NO_WARNINGS	1
//Ұָ�����
#include <stdio.h>
int* test()
{
	int n = 100;
	return &n;
}
int main()
{
	int* p = test();
	printf("%d\n", *p);
	return 0;
}