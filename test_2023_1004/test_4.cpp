#define _CRT_SECURE_NO_WARNINGS	1
//赋值运算符重载只能是类的成员函数
#include <iostream>
using namespace std;
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	int _year;
	int _month;
	int _day;
};
// 赋值运算符重载成全局函数，注意重载成全局函数时没有this指针了，需要给两个参数
Date& operator=(Date& left, const Date& right)
{
	if (&left != &right)
	{
		left._year = right._year;
		left._month = right._month;
		left._day = right._day;
	}
	return left;
}
void Test()
{
	Date d1(2023, 9, 27);
	Date d2;
	Date d3;
	d3 = d2 = d1;
}
int main()
{
	Test();
	return 0;
}