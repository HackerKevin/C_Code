#define _CRT_SECURE_NO_WARNINGS	1
//strerror理解
#include <stdio.h>
#include <string.h>
int main()
{
	FILE* pf = fopen("add.txt", "r");
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}
	else
	{
		printf("打开文件成功\n");
	}
	return 0;
}