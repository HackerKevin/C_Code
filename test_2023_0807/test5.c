#define _CRT_SECURE_NO_WARNINGS	1
//ָ������ͽ����ò��������
#include <stdio.h>
int main()
{
	int a = 10;
	int* pa = &a;//ȡ��a�ĵ�ַ���洢��ָ�����pa��
	printf("%d\n", a);
	*pa = 0;//�����ò�����
	printf("%d\n", a);
	return 0;
}