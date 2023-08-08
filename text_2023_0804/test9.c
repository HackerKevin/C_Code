#define _CRT_SECURE_NO_WARNINGS	1
//创建一个整形数组，完成对数组的操作
//1.实现函数init() 初始化数组为全0
//2.实现print()  打印数组的每个元素
//3.实现reverse()  函数完成数组元素的逆置。
//要求：自己设计以上函数的参数，返回值。
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