#define _CRT_SECURE_NO_WARNINGS	1
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int num = 0;
	int i = 0;
	scanf("%d", &num);//����ռ�Ĵ�С
	int* ptr = NULL;
	ptr = (int*)malloc(num * sizeof(int));
	if (NULL != ptr)//�ж�ptrָ���Ƿ�Ϊ��
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
	free(ptr);//�ͷ�ptr��ָ��Ķ�̬�ڴ�
	ptr = NULL;
	return 0;
}