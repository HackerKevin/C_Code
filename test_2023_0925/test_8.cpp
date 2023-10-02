#define _CRT_SECURE_NO_WARNINGS	1
//内联函数理解
#include <iostream>
using namespace std;
inline int Add(int left, int right)
{
	return left + right;
}
int main()
{
	int ret = 0;
	ret = Add(1, 2);
	return 0;
}


