#define _CRT_SECURE_NO_WARNINGS	1
//命名空间的使用
#include <stdio.h>
namespace Kevin
{
	int a = 0;
	int b = 1;
	int Add(int left, int right)
	{
		return left + right;
	}
	struct Node
	{
		struct Node* next;
		int val;
	};
	namespace N2
	{
		int c = 0;
		int d = 0;
	}
}
void test1()
{
	printf("%d\n", Kevin::a);
	printf("%d\n", Kevin::N2::c);
}
void test2()
{
	using Kevin::b;
	printf("%d\n", Kevin::a);
	printf("%d\n", b);
}
void test3()
{
	using namespace Kevin;
	printf("%d\n", a);
	printf("%d\n", b);
	Add(10, 20);
}
int main()
{
	test1();
	test2();
	test3();
	return 0;
}
