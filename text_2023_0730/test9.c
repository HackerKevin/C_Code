#define _CRT_SECURE_NO_WARNINGS	1
//���������������������������Լ��
//���磺
//���룺20 40
//�����20
#include <stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	int Y = 1;
	scanf("%d %d", &a, &b);
	//շת�����ʵ�������Լ��
	while(Y)//�������Ϊ0˵���ҵ����Լ��
	{
		if (a % b == a)//˵��b��a��
		{
			Y = b % a;
			if (Y != 0)
			{
				b = Y;
				continue;
			}
		}
		else//a��b��
		{
			Y = a % b;
			if (Y != 0)
			{
				a = Y;
				continue;
			}
			
		}
	}
	if (a > b)
		printf("���Լ���ǣ�%d", b);
	else
		printf("���Լ���ǣ�%d", a);
	return 0;
}