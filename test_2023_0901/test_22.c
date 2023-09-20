#define _CRT_SECURE_NO_WARNINGS	1
#include <stdio.h>
int main()
{
	int a[4] = { 1,2,3,4 };
	int* ptr1 = (int*)(&a + 1);
	//将整个数组的地址+1，得到跳过整个数组后的下一个地址
	int* ptr2 = (int*)((int)a + 1);
	//地址被强制转换成int类型后再+1，进而再强制转换为int*类型
	//相当于拿到a首元素下一个字节的地址
	//这个时候ptr2指向的内存块为00000002
	printf("%x,%x", ptr1[-1], *ptr2);
	//ptr1[-1]==*(ptr1+(-1))==*(ptr1-1)
	//输出ptr1前面一个地址的内存块
	//数据在内存中是小端存储
	//输出ptr2指向的内存块（00000002）时会还原成02000000
	//也就是打印出2000000
	return 0;
}