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
	//strlenͳ�Ƶ���\0֮ǰ�����ַ��ĸ���
	//\0��ASCII����0����ʵ�ҵ�0����
	//-128-1�������127������ѭ��ֱ��i=999���൱��strlenͳ�Ƶ��ǵ�һ��0֮ǰ�����ַ��ĸ���
	return 0;
}