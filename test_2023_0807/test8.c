#define _CRT_SECURE_NO_WARNINGS	1
//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Ժȶ�����ˮ�����ʵ�֣���
#include <stdio.h>
int Beverage(int money)
{
	static int beverage = 0;
	int lid = 0;
	while (money)
	{
		lid++;
		beverage++;
		money--;
	}
	lid /= 2;
	if (lid != 0)
		Beverage(lid);
	return beverage;
}
int main()
{
	int n = 20;
	printf("���Ժ�%dƿ��ˮ", Beverage(n));
	return 0;
}