#define _CRT_SECURE_NO_WARNINGS	1
//将数组A中的内容和数组B中的内容进行交换。（数组一样大）
#define N 10
#include <stdio.h>
int main()
{
    int n = 0;
    int temp = 0;
	int a[N] = { 0 };
	int b[N] = { 0 };
    printf("输入两个数组的大小：>");
    scanf("%d", &n);
    printf("\n输入数组a要存放的内容：>");
    for (int i = 0; i <= n - 1; i++)
    {
       
            scanf("%d", &a[i]);
        
    }
    printf("\n输入数组b要存放的内容：>");
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
    printf("交换后两个数组的内容为：\n");
    printf("数组a：");
    for (int i = 0; i <= n - 1; i++)
    {
            printf("%d ", a[i]);
    }
    printf("\n数组b：");
    for (int i = 0; i <= n - 1; i++)
    {
            printf("%d ", b[i]);
    }
	return 0;
}