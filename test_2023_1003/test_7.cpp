#define _CRT_SECURE_NO_WARNINGS	1
//���캯��ȱ��
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
	void Print()
	{
		cout << _year << "��" << _month << "��" << _day << "��";
		this->_t.Print();
	}
	/*Date()
	{
		cout << "Date()" << endl;
	}*/
private:
	//��������
	int _year = 2023;
	int _month = 10;
	int _day = 3;
	/*int _year;
	int _month;
	int _day;*/
	//�Զ�������
	Time _t;
};
int main()
{
	Date d;
	d.Print();
	return 0;
}