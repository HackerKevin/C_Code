#define _CRT_SECURE_NO_WARNINGS	1
//����һ���ǿ��������� nums ������ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ��������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�
//���磺nums = [4, 1, 2, 1, 2]
//���أ�4
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
	printf("ֻ������һ�ε�Ԫ���ǣ�%d", SingleNumber(nums, len));
	return 0;
}