#define _CRT_SECURE_NO_WARNINGS	1
//��ӡ1000�굽2000��֮�������
#include <stdio.h>

int main()
{
	int i = 1000;
	int j = 0;
	int flag = 1;
	while (flag)//�ҵ�1000���ĵ�һ������
	{
		if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
		{
			flag = 0;
		}
		else
			i++;
	}
	for (j = i; j <= 2000; j+=4)
	{
		printf("%d ", j);
	}
	return 0;
}