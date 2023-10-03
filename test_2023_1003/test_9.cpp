#define _CRT_SECURE_NO_WARNINGS	1
//实现一个程序，获取多少天以后的日期
#include <iostream>
#include <assert.h>
using namespace std;
class Date
{
public:
    Date(int year = 1900, int month = 1, int day = 1)
    {
        _year = year;
        _month = month;
        _day = day;
    }
    Date(const Date& d)   // 正确写法
    {
        _year = d._year;
        _month = d._month;
        _day = d._day;
        cout << "Date(const Date& d)" << endl;
    }
    Date GetAfterXDay(int x)
    {
        Date tmp(*this);//拷贝一份
        tmp._day += x;
        while (tmp._day > GetMonthDay(tmp._year, tmp._month))
        {
            //进位
            tmp._day -= GetMonthDay(tmp._year, tmp._month);
            ++tmp._month;
            if (tmp._month == 13)
            {
                tmp._year++;
                tmp._month = 1;
            }
        }
        return tmp;
    }
    int GetMonthDay(int year, int month)
    {
        int monthArray[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
        assert(month > 0 && month < 13);
        if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400) == 0))
        {
            return 29;
        }
        else
        {
            return monthArray[month];
        }
    }
    void Print()
    {
        cout << _year << "-" << _month << "-" << _day << endl;
    }
private:
    int _year;
    int _month;
    int _day;
};
int main()
{
    Date d1(2023, 2, 2);
    Date d2 = d1.GetAfterXDay(150);
    d1.Print();
    d2.Print();
}