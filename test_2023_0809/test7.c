#define _CRT_SECURE_NO_WARNINGS	1
//ָ��Ĺ�ϵ����
#include <stdio.h>
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int* p = arr;//����������������Ԫ�صĵ�ַ
	while (p < arr + sz)//arr+sz �����������־����\0���ĵ�ַ
	{
		printf("%d ", *p);
		p++;
	}
	return 0;
}