#define _CRT_SECURE_NO_WARNINGS	1
//��дһ������void StatCharCount(char str[])���ú�������һ���ַ�����Ϊ��������ͳ�Ƹ��ַ�������ĸ�����֡��ո�������ַ��ĸ�����
//��main�������øú������ֱ��ӡ��ĸ�����֡��ո� �� �����ַ��ĳ��ִ�����
//������ʾ��һ������ֻ�ܷ���һ��ֵ���˴���ͳ�ƽ����4������˷��ؽ������ʹ��ȫ�ֱ�����������
#include <stdio.h>
int Letter = 0;
int Number = 0;
int Space = 0;
int Other = 0;
int n = 0;
int i = 0;
char str[50] = { 0 };

void StatCharCount(char str[]);
void Scanf()
{
	while (n == 0)
	{
		printf("�������ַ������ַ�������");
		scanf("%d", &n);
		if (n > 49)
		{
			printf("\n�ַ���̫��(>49)����������");
			scanf("%d", &n);
			continue;
		}
		else
		{
			getchar();//ǰ���������ֺ�س����س����ڴ���ȡ��������getchar���԰ѻس����յ�
			printf("\n�������ַ�����");
			for (i = 0; i <= n-1; i++)
			{
				scanf("%c", &str[i]);
			}
		}
	}
}


int main()
{
	Scanf();
	StatCharCount(str);
	printf("��ĸ���ֵĴ�����%d\n", Letter);
	printf("���ֳ��ֵĴ�����%d\n", Number);
	printf("�ո���ֵĴ�����%d\n", Space);
	printf("�����ַ����ֵĴ�����%d\n", Other);
	return 0;
}

void StatCharCount(char str[])
{
	int j = 0;
	for (j = 0; j <= n - 1; j++)
	{
		if (str[j] >= 65 && str[j] <= 122)
		{
			Letter++;
			continue;
		}
		if (str[j] >= 48 && str[j] <= 57)
		{
			Number++;
			continue;
		}
		if (str[j] == 32)
		{
			Space++;
			continue;
		}
		else
		{
			Other++;
			continue;
		}
	}
}