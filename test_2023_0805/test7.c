#define _CRT_SECURE_NO_WARNINGS	1
//�ð�λȡ����ָ��λ��0
#include <stdio.h>
int main()
{
	int a = 0;
	int n = 0;
	printf("����һ�������Լ����������ĵڼ�λ��Ϊ0��\n");
	scanf("%d %d", &a, &n);
	a = a & ~(1 << n - 1);//��a�Ķ������е�nλ�ĳ�0
	printf("������ĵ�%dλ��Ϊ0���������Ϊ��%d", n, a);
	return 0;
}