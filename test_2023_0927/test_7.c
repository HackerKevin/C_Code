#define _CRT_SECURE_NO_WARNINGS	1
//��̬�ڴ澭���������
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* GetMemory(void)
{
	char p[] = "hello world";
	return p;
}
void Test(void)
{
	char* str = NULL;
	str = GetMemory();
	printf(str);
}

int main()
{
	Test();
	return 0;
}