#define _CRT_SECURE_NO_WARNINGS	1
//���������ɵ�Ĭ�ϸ�ֵ��������غ������
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
		cout << _hour << "ʱ" << _minute << "��" << _second << "��" << endl;
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
		cout << _year << "��" << _month << "��" << _day << "��";
		this->_t.Print();
	}
private:
	// ��������(��������)
	int _year;
	int _month;
	int _day;
	// �Զ�������
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
