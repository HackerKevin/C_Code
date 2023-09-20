#define _CRT_SECURE_NO_WARNINGS	1
//strcmpÄ£ÄâÊµÏÖ
#include <stdio.h>
#include <assert.h>
int my_strcmp(const char* p1, const char* p2)
{
	assert(p1 && p2);
	while (*p1 == *p2)
	{
		if (*p1 == '\0')
			return 0;
		p1++;
		p2++;
	}
	if (*p1 > *p2)
		return 1;
	else
		return -1;
}
int main()
{
	int ret1 = my_strcmp("abwdef", "abq");
	int ret2 = my_strcmp("abq", "abq");
	int ret3 = my_strcmp("abcdef", "abq");
	printf("%d\n", ret1);
	printf("%d\n", ret2);
	printf("%d\n", ret3);
	return 0;
}