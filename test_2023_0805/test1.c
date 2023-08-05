#define _CRT_SECURE_NO_WARNINGS	1
//兔子繁殖问题：假定一对大兔子每月能生一对小兔子，且每对新生的小兔子经过一个月可以长成一对大兔子,具备繁殖能力，如果不发生死亡，
//且每次均生下一雌一雄。现在有一对小兔子，问一年后共有多少对兔子？
#include <stdio.h>

int Rabbit(int month)
{
	int a = 1;
	int b = 1;
	int c = 1;
	for (int i = 3; i <= month; i++)
	{
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}
int main()
{
	int n = 12;
	printf("一年后有%d对兔子",  Rabbit(n));
	return 0;
}
