#define _CRT_SECURE_NO_WARNINGS	1
//拷贝构造函数典型调用场景
#include <iostream>
using namespace std;
class Date
{
public:
	Date(int year, int minute, int day)
	{
		cout << "Date(int,int,int):" << this << endl;
	}
	Date(const Date& d)
	{
		cout << "Date(const Date& d):" << this << endl;
	}
	~Date()
	{
		cout << "~Date():" << this << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2022, 1, 13);
	Test(d1);
	return 0;
}
Date Test(Date d)
{
	Date temp(d);
	return temp;
}