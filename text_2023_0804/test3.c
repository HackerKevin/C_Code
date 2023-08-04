#define _CRT_SECURE_NO_WARNINGS	1
//编写一个函数void StatCharCount(char str[])，该函数接收一个字符串作为参数，请统计该字符串中字母、数字、空格和其他字符的个数，
//在main函数调用该函数，分别打印字母、数字、空格 和 其他字符的出现次数。
//返回提示：一个函数只能返回一个值，此处的统计结果有4个，因此返回结果可以使用全局变量带出来。
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
		printf("请输入字符串的字符个数：");
		scanf("%d", &n);
		if (n > 49)
		{
			printf("\n字符串太长(>49)，重新输入");
			scanf("%d", &n);
			continue;
		}
		else
		{
			getchar();//前面输入数字后回车，回车会在待读取的区域，用getchar可以把回车吸收掉
			printf("\n请输入字符串：");
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
	printf("字母出现的次数：%d\n", Letter);
	printf("数字出现的次数：%d\n", Number);
	printf("空格出现的次数：%d\n", Space);
	printf("其他字符出现的次数：%d\n", Other);
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