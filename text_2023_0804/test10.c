#define _CRT_SECURE_NO_WARNINGS	1
//ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ��
//�磺����9�����9 * 9�ھ������12�����12 * 12�ĳ˷��ھ���
#include <stdio.h>
int main()
{
	int n = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf(" %2d*%2d =%3d ", j, i, i * j);
		}
		printf("\n");
	}
	return 0;
}