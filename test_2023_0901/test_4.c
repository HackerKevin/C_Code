#define _CRT_SECURE_NO_WARNINGS	1
//дһ�����룬ʵ���ַ����е�Сд��ĸת��д���������ַ����䡣
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main()
{
	char str[] = "I am a stduent.";
	int len = strlen(str);
	for (int i = 0; i < len; i++)//�����ַ���
	{
		if (islower(str[i]))
		{
			str[i] = toupper(str[i]);//����Сд��ĸ��ת��д
		}
	}
	printf("%s\n", str);
	return 0;
}