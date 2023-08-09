#define _CRT_SECURE_NO_WARNINGS	1
//÷∏’Î - ÷∏’Î
#include <stdio.h>
int my_strlen(char* s)
{
	char* p = s;
	while (*p != '\0')
		p++;
	return p - s;
}
int main()
{
	char arr[] = "abcedf";
	printf("%d\n", my_strlen(arr));
	return 0;
}
