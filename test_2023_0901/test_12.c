#define _CRT_SECURE_NO_WARNINGS	1
//memcpy模拟实现
#include <stdio.h>
#include <string.h>
#include <assert.h>
void* my_memcpy(void* dest, void* src, size_t num)
{
	assert(dest && src);
	void* ret = dest;
	while (num)
	{
		//拷贝一个字节
		*(char*)dest = *(char*)src;
		//由于强制类型转换是临时的，所以想要地址+1也要强制转换
		dest = (char*)dest + 1;
		src = (char*)src + 1;
		num--;
	}
	return ret;
}
int main()
{
	int arr1[10] = { 0 };
	int arr2[] = { 1,2,3,4,5,6,7,8 };
	char arr3[] = { 'a','b','c' ,'d' ,'e' ,'f','g','h','i' };
	char arr4[] = "abcde";
	my_memcpy(arr2+2, arr2, 20);
	my_memcpy(arr3, arr4, 7);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr2[i]);
	}
	return 0;
}