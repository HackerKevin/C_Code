#define _CRT_SECURE_NO_WARNINGS	1
//构造函数理解
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
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1;
	d1.Init(2022, 7, 5);
	d1.Print();
	Date d2;
	d2.Init(2022, 7, 6);
	d2.Print();
	return 0;
}