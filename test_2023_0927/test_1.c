#define _CRT_SECURE_NO_WARNINGS	1
//malloc理解
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int* p = (int*)malloc(40);
	if (p == NULL)//如果p为空，则开辟空间失败
	{
		perror("malloc");
		return 1;
	}
	//开辟成功
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d\n", *(p + i));//打印所开辟空间的值
	}
	return 0;
}
