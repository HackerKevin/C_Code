#define _CRT_SECURE_NO_WARNINGS	1
//���������������в�ͬλ�ĸ���
#include <stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	int i = 0;
	while (scanf("%d %d", &a, &b) != EOF)
	{
		int count = 0;
		for (i = 0; i < 32; i++)
		{
			if ((a & (1 << i)) != (b & (1 << i)))
				count++;
			else
				continue;
		}
		printf("%d��%d�������в�ͬλ�ĸ���Ϊ��%d\n", a, b, count);
	}
	return 0;
	
}