#define _CRT_SECURE_NO_WARNINGS	1
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int num = 0;
	int i = 0;
	scanf("%d", &num);//输入空间的大小
	int* ptr = NULL;
	ptr = (int*)malloc(num * sizeof(int));
	if (NULL != ptr)//判断ptr指针是否为空
	{
		for (i = 0; i < num; i++)
		{
			*(ptr + i) = 0;
		}
	}
	for (i = 0; i < num; i++)
	{
		printf("%d ", *(ptr + i));
	}
	free(ptr);//释放ptr所指向的动态内存
	ptr = NULL;
	return 0;
}