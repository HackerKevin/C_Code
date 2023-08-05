#define _CRT_SECURE_NO_WARNINGS	1
//谷歌笔试题：求一个整数以2进制形式存储在内存中时1的个数。
#include <stdio.h>

int Method1(int a)
{
	int count = 0;//计数
	while (a)
	{
		if (a % 2 == 1)//判断当前最低位是否为1
			count++;
		a = a / 2;//将a去掉一位，再赋给a
	}
	return count;
	//存在缺陷，因为当输入的数为负数时，计算会出错
}

int Method2(int a)
{
	int i = 0;
	int count = 0;
	for (i = 0; i < 32; i++)
	{
		if (((a >> i) & 1) == 1)//判断右移i位后当前最低位是否为1
		{
			count++;
		}
	}
	return count;
	
}

int Method3(int a)
{
	int count = 0;
	while (a)
	{
		count++;
		a = a & (a - 1);//只要执行1次，a的二进制序列中，最右边的1就消失了，能执行几次就说明有几个1
	}
	return count;

}

int main()
{
	int a = 0;
	
	scanf("%d", &a);
	printf("采用方法一得到这个数在二进制形式中1的个数 = %d\n", Method1(a));
	printf("采用方法二得到这个数在二进制形式中1的个数 = %d\n", Method2(a));
	printf("采用方法三得到这个数在二进制形式中1的个数 = %d\n", Method3(a));
	return 0;
}

