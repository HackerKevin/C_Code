#define _CRT_SECURE_NO_WARNINGS	1
//����һ���������飬��ɶ�����Ĳ���
//1.ʵ�ֺ���init() ��ʼ������Ϊȫ0
//2.ʵ��print()  ��ӡ�����ÿ��Ԫ��
//3.ʵ��reverse()  �����������Ԫ�ص����á�
//Ҫ���Լ�������Ϻ����Ĳ���������ֵ��
#include <stdio.h>

int arr[10];

void init(int a[],int b)
{
	int i = 0;
	
	for (i = 0; i < b; i++)
	{
		a[i] = 0;
	}
}

void print(int a[],int b)
{
	int i = 0;
	for (i = 0; i < b; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void reverse(int a[],int b)
{
	int i = 0;
	int temp = 0;
	while (i < b-1)
	{
		temp = a[i];
		a[i] = arr[b];
		a[b] = temp;
		i++;
		b--;
	}
}

int main()
{	
	int len = sizeof(arr) / sizeof(arr[0]);
	init(arr,len);
	print(arr, len);
	for (int i = 0; i < len; i++)
		scanf("%d", &arr[i]);

	reverse(arr,len-1); 
	print(arr,len);
	return 0;
}