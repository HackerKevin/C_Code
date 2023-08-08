#define _CRT_SECURE_NO_WARNINGS	1
//描述
//输入10个整数，要求按输入时的逆序把这10个数打印出来。逆序输出，就是按照输入相反的顺序打印这10个数。
//输入描述：
//一行，输入10个整数（范围-2^31~2^31-1），用空格分隔。
//输出描述：
//一行，逆序输出输入的10个整数，用空格分隔。
//示例1
//输入：
//1 2 3 4 5 6 7 8 9 10
//输出：
//10 9 8 7 6 5 4 3 2 1
#include <stdio.h>
#define N 10
int main()
{
	int arr[N] = { 0 };
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = N - 1; i >= 0; i--)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}