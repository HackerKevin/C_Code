#define _CRT_SECURE_NO_WARNINGS	1
//Ĭ�ϵĿ������캯��
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
private:
	//��������(��������)
	int _year = 1970;
	int _month = 1;
	int _day = 1;
	//�Զ�������
	Time _t;
};

int main()
{
	Date d1;

	// ���Ѿ����ڵ�d1��������d2���˴������Date��Ŀ������캯��
	// ��Date�ಢû����ʽ���忽�����캯��������������Date������һ��Ĭ�ϵĿ������캯��
	Date d2(d1);
	d2.Print();
	return 0;
}