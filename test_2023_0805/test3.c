#define _CRT_SECURE_NO_WARNINGS	1
//��������ʱ��������������������ʵ���������Ľ�����
#include <stdio.h>
void Method1(int *a, int *b)
{
	*a = *a + *b;//a��b�ĺ���ʱ����a����ȥ
	*b = *a - *b;//ʵ����Ϊa��b��b
	*a = *a - *b;//ʵ������a��b��a
	//ȱ�ݣ�a��b�������ֹ����ʱ�����׵���Խ�硣
}
void Method2(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;//�൱��a^b^b����b^b=0,����a^b^b=a^0=a
	*a = *a ^ *b;//�൱��a^b^a�������������֧�ֽ����ɵõ�a^b^a=a^a^b=b

//�������������о����ԣ�
//1.ֻ����������������
//2.����Ŀɶ��Բ�
//3.ִ�е�Ч�ʵ��ڲ�����ʱ�����ķ���
}
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	printf("����ǰ��a=%d��b=%d\n", a, b);
	Method1(&a, &b);
	printf("��һ�ν�����a=%d��b=%d\n", a, b);
	Method2(&a, &b);
	printf("�ڶ��ν�����a=%d��b=%d\n", a, b);
	return 0;
}