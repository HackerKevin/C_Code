#define _CRT_SECURE_NO_WARNINGS	1
//дһ�����룬�ж�һ�����Ƿ���2��n�η���
//������2^n������Ķ�������ʽ��ֻ��һ��1�����ȥ��һ��1���������1�ĸ���Ϊ0����˵���������2��n�η�
#include <stdio.h>
int main()
{
	int n = 0;
	while (scanf("%d", &n) != EOF)
	{
		if ((n & (n - 1)) == 0)//ȥ��һ��1���ж϶�������1�ĸ����Ƿ�Ϊ0
		{
			printf("yes\n");
		}
		else
			printf("no\n");
	}
	return 0;
}