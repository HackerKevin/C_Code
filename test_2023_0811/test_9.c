#define _CRT_SECURE_NO_WARNINGS	1
//��ȡһ���������������������е�ż��λ������λ���ֱ��ӡ������������
#include <stdio.h>
int main()
{
	int n = 0;
	while (scanf("%d", &n) != EOF)
	{
		int i = 0;
		printf("����λ��");
		for (i = 31; i >= 1; i -= 2)
		{
			printf("%d ", (n >> i) & 1);
		}
		printf("\n");
		printf("ż��λ��");
		for (i = 30; i >= 0; i -= 2)
		{
			printf("%d ", (n >> i) & 1);
		}
		printf("\n");
	}
	return 0;
}