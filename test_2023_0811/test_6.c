#define _CRT_SECURE_NO_WARNINGS	1
//��һ�����������У�ֻ��һ�����ֳ���һ�Σ��������鶼�ǳɶԳ��ֵģ����ҳ��Ǹ�ֻ����һ�ε����֡�
//���磺
//�������У�1 2 3 4 5 1 2 3 4��ֻ��5����һ�Σ��������ֶ�����2�Σ��ҳ�5
#include <stdio.h>
int FindSingle(int* ptr, int sz)
{
	int a = 0;
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		a ^= *(ptr + i);
	}
	return a;
}
int main()
{
	int arr[] = { 1,2,3,4,5,1,2,3,4 };
	int sz = 0;
	sz = sizeof(arr) / sizeof(arr[0]);
	printf("ֻ����һ�ε������ǣ�%d", FindSingle(arr, sz));
	return 0;
}