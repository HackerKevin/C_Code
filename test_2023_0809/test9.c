#define _CRT_SECURE_NO_WARNINGS	1
//��һ����������nums����һ������data����data��������nums���Ծɱ�֤nums���򣬷�����������ЧԪ�ظ�����
//���磺nums[100] = { 1, 2, 3, 5, 6, 7, 8, 9 }  size = 8   value = 4
//����֮��numsΪ{ 1, 2, 3, 4, 5, 6, 7, 8, 9 }
//����9
#include <stdio.h>
int InsertData(int* p, int sz, int data)
{
	int end = sz-1;
	while (end >= 0 && data < *(p + end))
	{
		*(p + end + 1) = *(p + end);
		end--;
	}
	*(p + end + 1) = data;
	return sz + 1;
}
int main()
{
	int nums[100] = { 1,2,3,5,6,7,8,9 };
	int* p = nums;
	int data = 0;
	int sz = 8;
	scanf("%d", &data);
	sz = InsertData(nums, sz, data);
	printf("�����������ЧԪ�صĸ���Ϊ��%d\n", sz);
	while (*p != '\0')
	{
		printf("%d ", *p);
		p++;
	}
	return 0;
}