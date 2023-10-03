#define _CRT_SECURE_NO_WARNINGS	1
//构造函数缺陷
#include <iostream>
using namespace std;
class Time
{
public:
	Time()
	{
		cout << "Time()" << endl;
		_hour = 0;
		_minute = 0;
		_second = 0;
	}
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
	void Print()
	{
		cout << _year << "年" << _month << "月" << _day << "日";
		this->_t.Print();
	}
	/*Date()
	{
		cout << "Date()" << endl;
	}*/
private:
	//基本类型
	int _year = 2023;
	int _month = 10;
	int _day = 3;
	/*int _year;
	int _month;
	int _day;*/
	//自定义类型
	Time _t;
};
int main()
{
	Date d;
	d.Print();
	return 0;
}