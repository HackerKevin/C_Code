#define _CRT_SECURE_NO_WARNINGS	1
//求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）
#include <iostream>
using namespace std;
class Sum
{
public:
	Sum()
	{
		_sum += _i;
		++_i;
	}
	static int GetSum()
	{
		return _sum;
	}
private:
	static int _i;
	static int _sum;
};
int Sum::_i = 1;
int Sum::_sum = 0;

class Solution
{
public:
	int Sum_Solution(int n)
	{
		Sum a[n];
		return Sum::GetSum();
	}
};