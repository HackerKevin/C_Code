#define _CRT_SECURE_NO_WARNINGS	1
//���0��100000֮������С�ˮ�ɻ������������
//��ˮ�ɻ�������ָһ��nλ�������λ���ֵ�n�η�֮��ȷ�õ��ڸ���������:153��1 ^ 3��5 ^ 3��3 ^ 3����153��һ����ˮ�ɻ�������
#include <stdio.h>
#include <math.h>
int IsPPDI(int a,int n)
{
	int arr[6] = { 0 };//�������ÿһλ������
	int i = 0;
	int j = 0;
	int temp = 0;
	int b = 0;
	j = n;
	temp = a;
	while (j)
	{
		arr[i] = temp % 10;
		temp /= 10;
		i++;
		j--;
	}
	for (i = 0; i < n; i++)
	{
		b += pow(arr[i], n);
	}
	if (a == b)
		return 1;
	else
		return 0;
}
int main()

{
	int i = 0;
	for (i = 0; i <= 100000; i++)
	{
		//���㵱ǰ���ֵ�λ��
		int n = 1;
		int j = i;
		while (j / 10 != 0)
		{
			n++;
			j /= 10;
		}
		//�ж��Ƿ�Ϊˮ�ɻ���
		if (IsPPDI(i,n))
			printf("%d ", i);
		else
			continue;
		
	}
	
	return 0;
}