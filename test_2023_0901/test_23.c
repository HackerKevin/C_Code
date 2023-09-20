#define _CRT_SECURE_NO_WARNINGS	1
//÷∏’Î µœ÷√∞≈›≈≈–Ú
#include <stdio.h>
void bubble_sort(int* ptr, size_t num)
{
	int i = 0;
	for (i = 0; i < num - 1; i++)
	{
		int j = 0;
		for (j = 0; j < num - i - 1; j++)
		{
			if (ptr[j] > ptr[j + 1])
			{
				int temp = ptr[j];
				ptr[j] = ptr[j + 1];
				ptr[j + 1] = temp;
			}
		}
	}
}
int main()
{
	int arr[] = { 3,5,7,9,1,4,2,6,8 };
	size_t sz = sizeof(arr) / sizeof(arr[0]);
	int* ptr = arr;
	bubble_sort(arr, sz);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", ptr[i]);
	}
	return 0;
}