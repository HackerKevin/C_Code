#define _CRT_SECURE_NO_WARNINGS	1
//�ݹ�ʵ��n��k�η�
#include <stdio.h>
int pow(int n, int k)
{
	if (k == 0)
		return 1;
	else
		return n * pow(n, k - 1);
}
int main()
{
	int n = 0;
	int k = 0;
	while (scanf("%d %d", &n, &k) != EOF)
	{
		printf("%d��%d�η�Ϊ��%d\n", n, k, pow(n, k));
	}
	
	return 0;
}