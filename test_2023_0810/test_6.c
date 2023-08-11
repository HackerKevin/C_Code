#define _CRT_SECURE_NO_WARNINGS	1
//一维数组传参的本质
#include <stdio.h>
void test1(int arr[])//参数写成数组形式，本质上还是指针
{
	printf("%d\n", sizeof(arr));
}
void test2(int* arr)//参数写成指针形式
{
	printf("%d\n", sizeof(arr));//计算⼀个指针变量的⼤⼩
}
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	test1(arr); 
	test2(arr);
	return 0;
}
