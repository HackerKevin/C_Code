#define _CRT_SECURE_NO_WARNINGS	1
//����һ���������飬ʵ��һ��������
//�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
//����ż��λ������ĺ�벿�֡�
#include <stdio.h>
void bubble_sort(int* ptr, size_t num)
{
	int i = 0;
	for (i = 0; i < num - 1; i++)
	{
		int j = 0;
		for (j = 0; j < num - i - 1; j++)
		{
			if (ptr[j] > ptr[j + 1])
			{
				int temp = ptr[j];
				ptr[j] = ptr[j + 1];
				ptr[j + 1] = temp;
			}
		}
	}
}
void adjust_arr(int* ptr, size_t num)
{

}
int main()
{
	int arr[] = { 1,5,9,7,3,4,2,6,8,11,19,17,14,16,12,13,15,18 };
	size_t sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz);
	adjust_arr(arr, sz);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}