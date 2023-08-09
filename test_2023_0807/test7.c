#define _CRT_SECURE_NO_WARNINGS	1
//写一个二分查找函数
//功能：在一个升序数组中查找指定的数值，找到了就返回下标，找不到就返回 - 1
#include <stdio.h>
int bin_search(int arr[], int left, int right, int key)
{
	while (left <= right)
	{
		if (arr[left] == key || arr[right] == key)
		{
			if (arr[left] == key)
				return left;
			else if (arr[right] == key)
				return right;
		}
		left++;
		right--;
	}
}
int main()
{
	int n = 0;
	int num[] = { 0,1,2,3,4,5,6,7,8,9 };
	int right = sizeof(num) / sizeof(num[0]) - 1;
	int left = 0;
	while (printf("请输入你要查找的值：>"), scanf("%d", &n) != EOF)
	{
		if (bin_search(num, left, right, n) == -1)
		{
			printf("抱歉，没有找到你想要的值\n");
		}
		else
		{
			printf("你想要的值在数值中的第%d位\n", bin_search(num, left, right, n) + 1);
		}
	}
	return 0;
}