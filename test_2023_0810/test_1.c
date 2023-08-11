#define _CRT_SECURE_NO_WARNINGS	1
//规避野指针
#include <stdio.h>
int* test()
{
	//局部变量
	int arr[10] = { 1,2,3,4,5,6,7,8,9 };
	//...
	return arr;
}
int main()
{
	int* p = test();//p就是野指针
	return 0;
}
