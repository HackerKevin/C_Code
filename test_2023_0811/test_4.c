#define _CRT_SECURE_NO_WARNINGS	1
//�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳ˣ���������������⣩
#include <stdio.h>
int Fact1(int n)
{
	if (n == 0)
		return 1;
	else
		return n * Fact1(n - 1);
}
int Fact2(int n)
{
	int Sum = 1;
	int i = 0;
	for (i = 1; i <= n; i++)
	{
		Sum *= i;
	}
	return Sum;
}
int main()
{
	int n = 0;
	while (scanf("%d", &n) != EOF)
	{
		printf("�ݹ�ʵ�֣�%d�Ľ׳�Ϊ��%d\n", n, Fact1(n));
		printf("ѭ��ʵ�֣�%d�Ľ׳�Ϊ��%d\n", n, Fact2(n));
	}
	return 0;
}