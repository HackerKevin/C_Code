#define _CRT_SECURE_NO_WARNINGS	1
//�����������
#include <stdio.h>
typedef struct st_type
{
	int i;
	int arr[0];//���������Ա
}type_a;
int main()
{
	printf("%d\n", sizeof(type_a));
	return 0;
}
