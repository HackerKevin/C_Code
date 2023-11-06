#pragma once
#include <iostream>
#include <assert.h>
using namespace std;
class Date
{
    friend ostream& operator<<(ostream& out, const Date& d);
    friend istream& operator>>(istream& in, Date& d);
public:
    explicit Date(int year = 1900, int month = 1, int day = 1);//һ��涨�������ĵط�����ȱʡ����
    int GetMonthDay(int year, int month) const;
    Date& operator+=(int day);
    Date operator+(int day) const;
    Date& operator-=(int day);
    Date operator-(int day) const;
    Date& operator++();//ǰ��++
    Date operator++(int);//����++
    Date& operator--();//ǰ��--
    Date operator--(int);//����--
    int operator-(const Date& d);
    bool operator==(const Date& d) const;
    bool operator<(const Date& d) const;
    bool operator<=(const Date& d) const;
    bool operator>(const Date& d) const;
    bool operator>=(const Date& d) const;
    bool operator!=(const Date& d) const;
    void Print();

private:
    int _year;
    int _month;
    int _day;
};
ostream& operator<<(ostream& out, const Date& d);
istream& operator>>(istream& in, Date& d);