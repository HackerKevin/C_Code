#define _CRT_SECURE_NO_WARNINGS	1
//strerror���
#include <stdio.h>
#include <string.h>
int main()
{
	FILE* pf = fopen("add.txt", "r");
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}
	else
	{
		printf("���ļ��ɹ�\n");
	}
	return 0;
}