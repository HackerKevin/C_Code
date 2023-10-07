#define _CRT_SECURE_NO_WARNINGS	1
//友元的应用
#include <iostream>
using namespace std;
class Time
{
    friend class Date;   // 声明日期类为时间类的友元类，则在日期类中就直接访问Time类中的私有成员变量
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
        // 直接访问时间类私有的成员变量
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
    _cout << d._year << "年" << d._month << "月" << d._day << "日"
          << d._t._hour << "时" << d._t._minute << "分" << d._t._second << "秒" << endl;
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

