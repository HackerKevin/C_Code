#define _CRT_SECURE_NO_WARNINGS	1
//��Ԫ��Ӧ��
#include <iostream>
using namespace std;
class Time
{
    friend class Date;   // ����������Ϊʱ�������Ԫ�࣬�����������о�ֱ�ӷ���Time���е�˽�г�Ա����
    friend ostream& operator<<(ostream& _cout, const Date& d);
    friend istream& operator>>(istream& _cin, Date& d);
public:
    Time(int hour = 0, int minute = 0, int second = 0)
        : _hour(hour)
        , _minute(minute)
        , _second(second)
    {}

private:
    int _hour;
    int _minute;
    int _second;
};
class Date
{
    friend ostream& operator<<(ostream& _cout, const Date& d);
    friend istream& operator>>(istream& _cin, Date& d);
public:
    Date(int year = 1900, int month = 1, int day = 1)
        : _year(year)
        , _month(month)
        , _day(day)
    {}

    void SetTimeOfDate(int hour, int minute, int second)
    {
        // ֱ�ӷ���ʱ����˽�еĳ�Ա����
        _t._hour = hour;
        _t._minute = minute;
        _t._second = second;
    }

private:
    int _year;
    int _month;
    int _day;
    Time _t;
};
ostream& operator<<(ostream& _cout, const Date& d)
{
    _cout << d._year << "��" << d._month << "��" << d._day << "��"
          << d._t._hour << "ʱ" << d._t._minute << "��" << d._t._second << "��" << endl;
    return _cout;
}
istream& operator>>(istream& _cin, Date& d)
{
    _cin >> d._year;
    _cin >> d._month;
    _cin >> d._day;
    _cin >> d._t._hour;
    _cin >> d._t._minute;
    _cin >> d._t._second;
    return _cin;
}
int main()
{
    Date d1;
    cin >> d1;
    cout << d1;
}

