#define _CRT_SECURE_NO_WARNINGS	1
//柔性数组理解
#include <stdio.h>
typedef struct st_type
{
	int i;
	int arr[0];//柔性数组成员
}type_a;
int main()
{
	printf("%d\n", sizeof(type_a));
	return 0;
}
