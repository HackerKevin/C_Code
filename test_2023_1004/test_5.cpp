#define _CRT_SECURE_NO_WARNINGS	1
//编译器生成的默认赋值运算符重载函数理解
#include <iostream>
using namespace std; 
class Time
{
public:
	Time()
	{
		_hour = 1;
		_minute = 1;
		_second = 1;
	}
	//Time& operator=(const Time& t)
	//{
	//	if (this != &t)
	//	{
	//		_hour = t._hour;
	//		_minute = t._minute;
	//		_second = t._second;
	//	}
	//	return *this;
	//}
	void Print()
	{
		cout << _hour << "时" << _minute << "分" << _second << "秒" << endl;
	}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void Print()
	{
		cout << _year << "年" << _month << "月" << _day << "日";
		this->_t.Print();
	}
private:
	// 基本类型(内置类型)
	int _year;
	int _month;
	int _day;
	// 自定义类型
	Time _t;
};
int main()
{
	Date d1;
	Date d2(2023, 10, 4);
	d1.Print();
	d2.Print();
	d1 = d2;
	d1.Print();
	d2.Print();
	return 0;
}
