#define _CRT_SECURE_NO_WARNINGS	1
#include "Date.h"
int Date::GetMonthDay(int year, int month) const
{
    int monthArray[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    assert(month > 0 && month < 13);
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
    {
        return 29;
    }
    else
    {
        return monthArray[month];
    }
}
Date::Date(int year, int month, int day)
{
    //检查日期是否合法
    if (month > 0 && month < 13
        && (day > 0 && day <= GetMonthDay(year, month)))
    {
        _year = year;
        _month = month;
        _day = day;
    }
    else
    {
        cout << "日期非法" << endl;
    }
}
Date& Date::operator+=(int day)
{
    if (day < 0)
    {
        *this -= (-day);
        return *this;
    }
    _day += day;
    if (_day < 0)
    {

    }
    while (_day > GetMonthDay(_year, _month))
    {
        _day -= GetMonthDay(_year, _month);
        _month++;
        if (_month == 13)
        {
            _year++;
            _month = 1;
        }
    }
    return *this;
}
Date Date::operator+(int day) const
{
    Date tmp = *this;
    /*tmp._day += day;
    while (tmp._day > GetMonthDay(tmp._year, tmp._month))
    {
        tmp._day -= GetMonthDay(tmp._year, tmp._month);
        tmp._month++;
        if (tmp._month == 13)
        {
            tmp._year++;
            tmp._month = 1;
        }
    }*/
    tmp += day;//复用operator+=
    return tmp;
}
Date& Date::operator++()
{
    *this += 1;
    return *this;
}
Date Date::operator++(int)
{
    Date tmp(*this);
    *this += 1;
    return tmp;
}
Date& Date::operator-=(int day)
{
    if (day < 0)
    {
        *this += (-day);
        return *this;
    }
    _day -= day;
    while (_day <= 0)
    {
        _month--;
        if (_month == 0)
        {
            _year--;
            _month = 12;
        }
        _day += GetMonthDay(_year, _month);
    }
    return *this;

}
Date Date::operator-(int day) const
{
    Date tmp = *this;
    tmp -= day;
    return tmp;
}
Date& Date::operator--()
{
    *this -= 1;
    return *this;
}
Date Date::operator--(int)
{
    Date tmp(*this);
    *this -= 1;
    return tmp;
}
int Date::operator-(const Date& d)
{
    Date max = *this;
    Date min = d;
    int flag = 1;
    int n = 0;
    if (*this < d)
    {
        max = d;
        min = *this;
        flag = -1;
    }
    while (min != max)
    {
        min++;
        n++;
    }
    return n;
}
bool Date::operator==(const Date& d) const
{
    return _year == d._year
        && _month == d._month
        && _day == d._day;
}
bool Date::operator<(const Date& d) const
{
    return _year < d._year
        || (_year == d._year && _month < d._month)
        || (_year == d._year && _month == d._month && _day < d._day);
}
bool Date::operator<=(const Date& d) const
{
    return *this < d || *this == d;
}
bool Date::operator>(const Date& d) const
{
    return !(*this <= d);
}
bool Date::operator>=(const Date& d) const
{
    return !(*this < d);
}
bool Date::operator!=(const Date& d) const
{
    return !(*this == d);
}
ostream& operator<<(ostream& out, const Date& d)
{
    out << d._year << "年" << d._month << "月" << d._day << "日" << endl;
    return out;
}
istream& operator>>(istream& in, Date& d)
{
    in >> d._year >> d._month >> d._day;
    return in;
}
void Date::Print()
{
    cout << _year << "年" << _month << "月" << _day << "日" << endl;
}