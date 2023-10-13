#define _CRT_SECURE_NO_WARNINGS	1
//ÏÔÊ½ÊµÀý»¯
#include <iostream>
using namespace std;
template<class T>
T Add(const T& left, const T& right)
{
	return left + right;
}
int main()
{
	int a1 = 10;
	double d1 = 10.0;
	int a2 = Add<int>(a1, d1);
	cout << a2 << endl;
	return 0;
}