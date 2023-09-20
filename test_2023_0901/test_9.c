#define _CRT_SECURE_NO_WARNINGS	1
//strtok¿ÌΩ‚
#include <stdio.h>
#include <string.h>
int main()
{
	char arr[] = "23333@qq.com";
	char buf[30] = { 0 };
	strcpy(buf, arr);
	char* p = "@.";
	char* r = NULL;
	for (r = strtok(buf, p); r != NULL; r = strtok(NULL, p))
	{
		printf("%s\n", r);
	}
	return 0;
}

