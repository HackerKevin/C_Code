#define _CRT_SECURE_NO_WARNINGS	1
//�����Ķ�̬�ڴ����
#include <stdio.h>
#include <stdlib.h>
void test1()
{
	int* p = (int*)malloc(INT_MAX / 4);
	*p = 20;//���p��ֵ��NULL���ͻ�������
	free(p);
}
void test2()
{
	int i = 0;
	int* p = (int*)malloc(10 * sizeof(int));//����40���ֽڼ�10�����͵Ŀռ�
	if (NULL == p)
	{
		exit(EXIT_FAILURE);
	}
	for (i = 0; i <= 10; i++)
	{
		*(p + i) = i;//��i��10��ʱ��Խ�����
	}
	free(p);
}
void test3()
{
	int a = 10;
	int* p = &a;
	free(p);//ok?
}
void test4()
{
	int* p = (int*)malloc(100);
	p++;//p����ָ��̬�ڴ����ʼλ��
	free(p);
}
void test5()
{
	int* p = (int*)malloc(100);
	free(p);
	free(p);//�ظ��ͷ�
}
void test6()
{
	int* p = (int*)malloc(100);
	if (NULL != p)
	{
		*p = 20;
	}
}
int main()
{
	test6();
	return 0;
}