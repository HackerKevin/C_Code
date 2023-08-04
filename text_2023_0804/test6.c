#define _CRT_SECURE_NO_WARNINGS	1
//描述
//输入两个升序排列的序列，将两个序列合并为一个有序序列并输出。
//数据范围：1<=n,m<=1000,序列中的值满足0<=val<=30000
//输入描述：
//输入包含三行，
//第一行包含两个正整数n, m，用空格分隔。n表示第二行第一个升序序列中数字的个数，m表示第三行第二个升序序列中数字的个数。
//第二行包含n个整数，用空格分隔。
//第三行包含m个整数，用空格分隔。
//输出描述：
//输出为一行，输出长度为n + m的升序序列，即长度为n的升序序列和长度为m的升序序列中的元素重新进行升序序列排列合并。
//示例1
//输入：
//5 6
//1 3 7 9 22
//2 8 10 17 33 44
//输出：
//1 2 3 7 8 9 10 17 22 33 44
#define N 1000
#define M 1000
#include <stdio.h>
int main()
{
	int i, j = 0;
	int n, m = 0;
	int temp = 0;
	int arr1[N] = { 0 };
	int arr2[M] = { 0 };
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%d", &arr1[i]);
	for (i = 0; i < m; i++)
		scanf("%d", &arr2[i]);
	//合并
	i = 0;
	j = 0;
	//判断2个数组中是否都有数据
	while (i < n && j < m)
	{
		if (arr1[i] > arr2[j])
		{
			printf("%d ", arr2[j]);
			j++;
		}
		else
		{
			printf("%d ", arr1[i]);
			i++;
		}
	}
	//哪个数组的数据还没打印完就继续打印
	while (i < n)
	{
		printf("%d ", arr1[i]);
		i++;
	}
	while (j < m)
	{
		printf("%d ", arr2[j]);
		j++;
	}
	return 0;
}