#define _CRT_SECURE_NO_WARNINGS	1
//this指针理解
#include <iostream>
using namespace std;
class Date
{
public:
	void Init(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	void func()
	{
		cout << "func()" << endl;
	}
private:
	int _year;     // 年
	int _month;    // 月
	int _day;      // 日
};
int main()
{
	Date d1, d2;
	d1.Init(2022, 1, 11);
	d2.Init(2022, 1, 12);
	d1.Print();
	d2.Print();
	return 0;
}