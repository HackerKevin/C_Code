#define _CRT_SECURE_NO_WARNINGS	1
//矩阵转置
//KiKi有一个矩阵，他想知道转置后的矩阵（将矩阵的行列互换得到的新矩阵称为转置矩阵），请编程帮他解答。
//输入描述：
//第一行包含两个整数n和m，表示一个矩阵包含n行m列，用空格分隔。(1≤n≤10, 1≤m≤10)
//从2到n + 1行，每行输入m个整数（范围 - 231~231 - 1），用空格分隔，共输入n * m个数，表示第一个矩阵中的元素。
//输出描述：
//输出m行n列，为矩阵转置后的结果。每个数后面有一个空格。
#include <stdio.h>
#define N 10
#define M 10
int main()
{
    int n = 0;
    int m = 0;
    int a[N][M] = { 0 };
    scanf("%d %d", &n, &m);
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j <= m - 1; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i <= m - 1; i++)
    {
        for (int j = 0; j <= n - 1; j++)
        {
            printf("%d ", a[j][i]);
        }
        printf("\n");
    }
    return 0;
}