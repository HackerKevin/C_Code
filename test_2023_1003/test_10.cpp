#define _CRT_SECURE_NO_WARNINGS	1
//默认的拷贝构造函数
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
	Time(const Time& t)
	{
		_hour = t._hour;
		_minute = t._minute;
		_second = t._second;
		cout << "Time::Time(const Time&)" << endl;
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
private:
	//基本类型(内置类型)
	int _year = 1970;
	int _month = 1;
	int _day = 1;
	//自定义类型
	Time _t;
};

int main()
{
	Date d1;

	// 用已经存在的d1拷贝构造d2，此处会调用Date类的拷贝构造函数
	// 但Date类并没有显式定义拷贝构造函数，则编译器会给Date类生成一个默认的拷贝构造函数
	Date d2(d1);
	d2.Print();
	return 0;
}