#define _CRT_SECURE_NO_WARNINGS	1
//realloc���
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
	//���ӿռ�
	int* ptr = realloc(p, 80);
	if (ptr != NULL)//�ж������Ƿ�ɹ�
	{
		p = ptr;
		ptr = NULL;
	}
	else
	{
		perror("realloc");//����ʧ�ܣ�����
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