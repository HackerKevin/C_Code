#define _CRT_SECURE_NO_WARNINGS	1
//���ӷ�ֳ���⣺�ٶ�һ�Դ�����ÿ������һ��С���ӣ���ÿ��������С���Ӿ���һ���¿��Գ���һ�Դ�����,�߱���ֳ���������������������
//��ÿ�ξ�����һ��һ�ۡ�������һ��С���ӣ���һ����ж��ٶ����ӣ�
#include <stdio.h>

int Rabbit(int month)
{
	int a = 1;
	int b = 1;
	int c = 1;
	for (int i = 3; i <= month; i++)
	{
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}
int main()
{
	int n = 12;
	printf("һ�����%d������",  Rabbit(n));
	return 0;
}
