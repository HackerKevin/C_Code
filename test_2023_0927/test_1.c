#define _CRT_SECURE_NO_WARNINGS	1
//malloc���
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int* p = (int*)malloc(40);
	if (p == NULL)//���pΪ�գ��򿪱ٿռ�ʧ��
	{
		perror("malloc");
		return 1;
	}
	//���ٳɹ�
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d\n", *(p + i));//��ӡ�����ٿռ��ֵ
	}
	return 0;
}
