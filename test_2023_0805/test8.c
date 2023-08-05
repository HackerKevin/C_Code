#define _CRT_SECURE_NO_WARNINGS	1
//请实现函数: int isPowerOfTwo(unsigned int n)。该函数接收一个非负数n，请判断n是否为2的幂次方。如果是返回真；否则返回假。
//为简单起见，不考虑n为负数的情况。如果存在一个整数X使得 x = 2^n，则认为n是2的幂次方。
#include <stdio.h>
int isPowerOfTwo(unsigned int n)
{
	if ((n & (n - 1)) == 0)
		return 1;
	else
		return 0;
}
int main()
{
	unsigned int a = 0;
	scanf("%d", &a);
	if (isPowerOfTwo(a))
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}