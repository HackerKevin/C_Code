#define _CRT_SECURE_NO_WARNINGS	1
//��Sn = a + aa + aaa + aaaa + aaaaa��ǰ5��֮�ͣ�����a��һ�����֣�
//���磺2 + 22 + 222 + 2222 + 22222
#include <stdio.h>
int main()
{
	int a = 0;
	
	while (scanf("%d", &a) != EOF)
	{
		int Sn = 0;
		int n = 5;
		while (n)
		{
			Sn += a;
			a = a * 10 + 2;
			n--;
		}
		printf("Sn=%d\n", Sn);
	}
	return 0;
}