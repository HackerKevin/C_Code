#define _CRT_SECURE_NO_WARNINGS	1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Test(void)
{
	char* str = (char*)malloc(100);
	strcpy(str, "hello");
	free(str);
	if (str != NULL)
	{
		strcpy(str, "world");
		printf(str);
	}
}

int main()
{
	Test();
	return 0;
}