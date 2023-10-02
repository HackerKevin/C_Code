#define _CRT_SECURE_NO_WARNINGS	1
//柔性数组对比
#include <stdio.h>
typedef struct S
{
	int n;
	int* arr;
}type_a;
int main()
{
	type_a* ps = (type_a*)malloc(sizeof(type_a));
	if (ps == NULL)
	{
		perror("malloc->ps");
		return 1;
	}
	ps->arr = (int*)malloc(40);
	if (ps->arr == NULL)
	{
		perror("malloc->ps->arr");
		return 1;
	}
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		ps->arr[i] = i;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
	//扩容
	int* ptr = (int*)realloc(ps->arr, 60);
	if (ptr == NULL)
	{
		perror("realloc->ps->arr");
		return 1;
	}
	ps->arr = ptr;
	for (i = 10; i < 15; i++)
	{
		ps->arr[i] = i;
	}
	for (i = 0; i < 15; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	free(ps->arr);
	ps->arr = NULL;
	free(ps);
	ps = NULL;
	return 0;
}