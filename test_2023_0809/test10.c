#define _CRT_SECURE_NO_WARNINGS	1
//求出0～100000之间的所有“水仙花数”并输出。
//“水仙花数”是指一个n位数，其各位数字的n次方之和确好等于该数本身，如:153＝1 ^ 3＋5 ^ 3＋3 ^ 3，则153是一个“水仙花数”。
#include <stdio.h>
#include <math.h>
int IsPPDI(int a,int n)
{
	int arr[6] = { 0 };//用来存放每一位的数字
	int i = 0;
	int j = 0;
	int temp = 0;
	int b = 0;
	j = n;
	temp = a;
	while (j)
	{
		arr[i] = temp % 10;
		temp /= 10;
		i++;
		j--;
	}
	for (i = 0; i < n; i++)
	{
		b += pow(arr[i], n);
	}
	if (a == b)
		return 1;
	else
		return 0;
}
int main()

{
	int i = 0;
	for (i = 0; i <= 100000; i++)
	{
		//计算当前数字的位数
		int n = 1;
		int j = i;
		while (j / 10 != 0)
		{
			n++;
			j /= 10;
		}
		//判断是否为水仙花数
		if (IsPPDI(i,n))
			printf("%d ", i);
		else
			continue;
		
	}
	
	return 0;
}