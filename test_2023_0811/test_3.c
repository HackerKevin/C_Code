#define _CRT_SECURE_NO_WARNINGS	1
//дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮��
//���磬����DigitSum(1729)����Ӧ�÷���1 + 7 + 2 + 9�����ĺ���19
//���룺1729�������19
#include <stdio.h>
unsigned int DigitSum(int a)
{
	int Sum = 0;
	if (a / 10 == 0)
		return a % 10;
	else
		return Sum += (a % 10) + DigitSum(a / 10);
}
int main()
{
	unsigned int n = 0;
	while (scanf("%d", &n) != EOF)
	{
		printf("%d�ĸ�λ����֮��Ϊ��%d\n", n, DigitSum(n));
	}
	return 0;
}