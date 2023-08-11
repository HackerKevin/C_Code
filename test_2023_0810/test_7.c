#define _CRT_SECURE_NO_WARNINGS	1
//冒泡排序
#include <stdio.h>
//方法一
void bubble_sort1(int arr[], int sz)//参数接收数组元素个数
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)// 确定排序的趟数
	{
		int j = 0;
		for (j = 0; j < sz - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
//方法二
void bubble_sort2(int arr[], int sz)//参数接收数组元素个数
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int flag = 1;//假设这⼀趟已经有序了
		int j = 0;
		for (j = 0; j < sz - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				flag = 0;//发⽣交换就说明，⽆序
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
		if (flag == 1)//这⼀趟没交换就说明已经有序，后续⽆序排序了
			break;
	}
}

void print(int* arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}

int main()
{
	int arr1[] = { 3,1,7,5,8,9,0,2,4,6 }; 
	int arr2[] = { 3,1,7,5,8,9,0,2,4,6 };
	int sz1 = sizeof(arr1) / sizeof(arr1[0]); 
	int sz2 = sizeof(arr2) / sizeof(arr2[0]);
	bubble_sort1(arr1, sz1);
	bubble_sort2(arr2, sz2);
	print(arr1, sz1);
	printf("\n");
	print(arr2, sz2);
	return 0;
}