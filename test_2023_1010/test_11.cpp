#define _CRT_SECURE_NO_WARNINGS	1
//ÒþÊ½ÊµÀý»¯
#include <iostream>
using namespace std;
template<class T>
T Add(const T& left, const T& right)
{
	return left + right;
}
int main()
{
	int a1 = 10, a2 = 20;
	double d1 = 10.0, d2 = 20.0;
	Add(a1, (int)d1);
	return 0;
}