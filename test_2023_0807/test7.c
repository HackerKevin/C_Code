#define _CRT_SECURE_NO_WARNINGS	1
//дһ�����ֲ��Һ���
//���ܣ���һ�����������в���ָ������ֵ���ҵ��˾ͷ����±꣬�Ҳ����ͷ��� - 1
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
	while (printf("��������Ҫ���ҵ�ֵ��>"), scanf("%d", &n) != EOF)
	{
		if (bin_search(num, left, right, n) == -1)
		{
			printf("��Ǹ��û���ҵ�����Ҫ��ֵ\n");
		}
		else
		{
			printf("����Ҫ��ֵ����ֵ�еĵ�%dλ\n", bin_search(num, left, right, n) + 1);
		}
	}
	return 0;
}