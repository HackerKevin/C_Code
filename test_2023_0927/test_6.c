#define _CRT_SECURE_NO_WARNINGS	1
//��̬�ڴ澭��������һ
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void GetMemory(char* p)
{
	p = (char*)malloc(100);
}
void Test(void)
{
	char* str = NULL;
	GetMemory(str);
	strcpy(str, "hello world");
	printf(str);
}

int main()
{
	Test();
	return 0;
}