#define _CRT_SECURE_NO_WARNINGS	1
#include <stdio.h>
int main()
{
	char a[1000];
	int i;
	for (i = 0; i < 1000; i++)
	{
		a[i] = -1 - i;
	}
	printf("%d", strlen(a));
	//strlen统计的是\0之前出现字符的个数
	//\0的ASCII码是0，其实找到0就行
	//-128-1后会跳到127，往复循环直到i=999，相当于strlen统计的是第一个0之前出现字符的个数
	return 0;
}