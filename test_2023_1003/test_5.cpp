#define _CRT_SECURE_NO_WARNINGS	1
//默认构造函数只能有一个
#include <iostream>
using namespace std;
class Date
{
public:
	Date()
	{
		_year = 1900;
		_month = 1;
		_day = 1;
	}
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};

void Test()
{
	Date d1;
}
int main()
{
	Test();
	return 0;
}

