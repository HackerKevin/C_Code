#define _CRT_SECURE_NO_WARNINGS	1
//ʵ��һ������is_prime���ж�һ�����ǲ���������
//��������ʵ�ֵ�is_prime��������ӡ100��200֮���������
#include <stdio.h>
#include <math.h>
int is_prime(int a)
{
	int j = 0;
	for (j = 2; j <= sqrt(a); j++)
	{
		if (a % j == 0)
			return 0;
		else if (j == sqrt(a))
			return 1;
	}
}

int main()
{
	int i = 0;
	for (i = 100; i <= 200; i++)
	{
		if (is_prime(i))
		{
			printf("%d ", i);
		}
		else
			continue;
	}
	return 0;
}