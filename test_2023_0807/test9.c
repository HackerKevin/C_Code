#define _CRT_SECURE_NO_WARNINGS	1
//��ӡ����
#include <stdio.h>
void InitArr(char arr[13][13])
{
	int left = 0;
	int right = 0;
	int i = 0;
	for (i = 0; i < 7; i++)//�ϰ벿��
	{
		int j = 0;
		int left = 6;
		int right = 6;
		do
		{
			arr[i][left - j] = '*';
			arr[i][right + j] = '*';
			j++;
		} while (j<=i);
	}
	for (i = 7; i < 13; i++)//�°벿��
	{
		int j = 0;
		int left = 6;
		int right = 6;
		do
		{
			arr[i][left - j] = '*';
			arr[i][right + j] = '*';
			j++;
		} while (j <= 12 - i);
	}
}
void Printf(char arr[13][13])//��ӡ
{
	
	
	for (int i = 0; i < 13; i++)
	{
		
		for (int j = 0; j < 13; j++)
		{
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	char arr[13][13];
	for (int i = 0; i < 13; i++)//��ʼ��
	{

		for (int j = 0; j < 13; j++)
		{
			arr[i][j] = ' ';
		}
	}
	InitArr(arr);
	Printf(arr);
	return 0;
}