#define _CRT_SECURE_NO_WARNINGS	1
//给你一个非空整数数组 nums ，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
//比如：nums = [4, 1, 2, 1, 2]
//返回：4
#include <stdio.h>
int SingleNumber(int arr[], int len)
{
	int a = 0;
	int i = 0;
	for (i = 0; i < len; i++)
	{
		a ^= arr[i];
	}
	return a;
}
int main()
{
	int nums[] = { 4,1,2,1,2 };
	int len = sizeof(nums) / sizeof(nums[0]);
	printf("只出现了一次的元素是：%d", SingleNumber(nums, len));
	return 0;
}