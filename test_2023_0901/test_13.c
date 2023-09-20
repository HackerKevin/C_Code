#define _CRT_SECURE_NO_WARNINGS	1
//memmoveÄ£ÄâÊµÏÖ
#include <stdio.h>
#include <string.h>
#include <assert.h>
void* my_memmove(void* dest, void* src, size_t num)
{
	assert(dest && src);
	void* ret = dest;
	if (dest < src)
	{
		while (num--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	else
	{
		while (num--)
		{
			*((char*)dest + num) = *((char*)src + num);
		}
	}
	return ret;
}
int main()
{
	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr2[] = { 1,2,3,4,5,6,7,8,9,10 };
	my_memmove(arr1, arr1 + 2, 20);
	my_memmove(arr2 + 2, arr2, 20);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr2[i]);
	}
	printf("\n");
	return 0;
}