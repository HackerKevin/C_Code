#define _CRT_SECURE_NO_WARNINGS	1
//��̬�ڴ澭����������
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void GetMemory(char** p, int num)
{
	*p = (char*)malloc(num);
}
void Test(void)
{
	char* str = NULL;
	GetMemory(&str, 100);
	strcpy(str, "hello");
	printf(str);
}

int main()
{
	Test();
	return 0;
}