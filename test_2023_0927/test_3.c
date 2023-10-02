#define _CRT_SECURE_NO_WARNINGS	1
//calloc¿ÌΩ‚
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i = 0;
	int* p = (int*)calloc(10, sizeof(int));
	for (i = 0; i < 10; i++)
	{
		printf("%d ", *(p + i));
	}
	printf("\n");
	if (NULL != p)
	{
		for (i = 0; i < 10; i++)
		{
			*(p + i) = 1;
		}
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", *(p + i));
	}
	free(p);
	p = NULL;
	return 0;
}