#define _CRT_SECURE_NO_WARNINGS	1
//��1+2+3+...+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C��
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