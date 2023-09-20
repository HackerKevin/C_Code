#define _CRT_SECURE_NO_WARNINGS	1
#include <stdio.h>
#include <windows.h>
int main()
{
	unsigned int i;
	for (i = 9; i >= 0; i--)
	{
		printf("%u\n", i);
		Sleep(1000);
	}
	return 0;
}
