#define _CRT_SECURE_NO_WARNINGS	1
//realloc理解
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int* p = (int*)malloc(40);
	if (p == NULL)
	{
		perror("malloc");
		return 1;
	}
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		p[i] = i + 1;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", *(p + i));
	}
	printf("\n");
	//增加空间
	int* ptr = realloc(p, 80);
	if (ptr != NULL)//判断扩容是否成功
	{
		p = ptr;
		ptr = NULL;
	}
	else
	{
		perror("realloc");//扩容失败，报错
		return 1;
	}
	for (i = 0; i < 20; i++)
	{
		printf("%d ", *(p + i));
	}
	free(p);
	p = NULL;
	return 0;
}