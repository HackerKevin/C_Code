#define _CRT_SECURE_NO_WARNINGS	1
//�ݹ�ͷǵݹ�ֱ�ʵ�����n��쳲�������
//���磺
//���룺5  �����5
//���룺10�� �����55
//���룺2�� �����1
#include <stdio.h>
//ѭ��ʵ��
int Fib1(int n)
{
	int a = 1;
	int b = 1;
	int c = 1;
	while (n > 2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}
//�ݹ�ʵ��
int Fib2(int n)
{
	if (n == 1 || n == 2)
		return 1;
	else
		return Fib2(n - 1) + Fib2(n - 2);
}
int main()
{
	int n = 0;
	while (scanf("%d", &n) != EOF)
	{
		printf("ѭ��ʵ�֣���%d��쳲��������ǣ�%d\n", n, Fib1(n));
		printf("�ݹ�ʵ�֣���%d��쳲��������ǣ�%d\n", n, Fib2(n));
		
	}
	return 0;
}