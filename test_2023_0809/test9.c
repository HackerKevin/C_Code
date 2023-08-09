#define _CRT_SECURE_NO_WARNINGS	1
//有一个升序数组nums，给一个数字data，将data插入数组nums中仍旧保证nums升序，返回数组中有效元素个数。
//比如：nums[100] = { 1, 2, 3, 5, 6, 7, 8, 9 }  size = 8   value = 4
//插入之后，nums为{ 1, 2, 3, 4, 5, 6, 7, 8, 9 }
//返回9
#include <stdio.h>
int InsertData(int* p, int sz, int data)
{
	int end = sz-1;
	while (end >= 0 && data < *(p + end))
	{
		*(p + end + 1) = *(p + end);
		end--;
	}
	*(p + end + 1) = data;
	return sz + 1;
}
int main()
{
	int nums[100] = { 1,2,3,5,6,7,8,9 };
	int* p = nums;
	int data = 0;
	int sz = 8;
	scanf("%d", &data);
	sz = InsertData(nums, sz, data);
	printf("插入后数组有效元素的个数为：%d\n", sz);
	while (*p != '\0')
	{
		printf("%d ", *p);
		p++;
	}
	return 0;
}