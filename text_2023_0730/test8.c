#define _CRT_SECURE_NO_WARNINGS	1
//������A�е����ݺ�����B�е����ݽ��н�����������һ����
#define N 10
#include <stdio.h>
int main()
{
    int n = 0;
    int temp = 0;
	int a[N] = { 0 };
	int b[N] = { 0 };
    printf("������������Ĵ�С��>");
    scanf("%d", &n);
    printf("\n��������aҪ��ŵ����ݣ�>");
    for (int i = 0; i <= n - 1; i++)
    {
       
            scanf("%d", &a[i]);
        
    }
    printf("\n��������bҪ��ŵ����ݣ�>");
    for (int i = 0; i <= n - 1; i++)
    {
        
            scanf("%d", &b[i]);
       
    }
    for (int i = 0; i <= n - 1; i++)
    {
       
            temp = a[i];
            a[i] = b[i];
            b[i] = temp;
      
    }
    printf("�������������������Ϊ��\n");
    printf("����a��");
    for (int i = 0; i <= n - 1; i++)
    {
            printf("%d ", a[i]);
    }
    printf("\n����b��");
    for (int i = 0; i <= n - 1; i++)
    {
            printf("%d ", b[i]);
    }
	return 0;
}