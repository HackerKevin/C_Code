#define _CRT_SECURE_NO_WARNINGS	1
//1�� 100 �����������г��ֶ��ٸ�����9
#include <stdio.h>
int main()
{
	int i = 0;
	int count = 0;
	for (i = 1; i <= 100; i++)
	{
		if (9 == i % 10)
			count++;
		else
			continue;
	}
	printf("1��100�����������г���%d������9", count);
	return 0;
}