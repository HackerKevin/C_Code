#define _CRT_SECURE_NO_WARNINGS	1
//����һ������������������ʽ�´����������ĵ�nλ�Ǽ�
#include <stdio.h>
int main()
{
	int a = 0;
	int n = 0;
	while (printf("������һ�����Լ�����۲��λ����"), scanf("%d %d", &a, &n) != EOF)
	{
		printf("%d��������ʽ�´����������ĵ�%dλ��%d\n", a, n, a >> n - 1 & 1);
	}
	return 0;
}