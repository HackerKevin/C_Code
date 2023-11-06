#pragma once
#include <iostream>
#include <assert.h>
using namespace std;
class Date
{
    friend ostream& operator<<(ostream& out, const Date& d);
    friend istream& operator>>(istream& in, Date& d);
public:
    explicit Date(int year = 1900, int month = 1, int day = 1);//一般规定在声明的地方给出缺省参数
    int GetMonthDay(int year, int month) const;
    Date& operator+=(int day);
    Date operator+(int day) const;
    Date& operator-=(int day);
    Date operator-(int day) const;
    Date& operator++();//前置++
    Date operator++(int);//后置++
    Date& operator--();//前置--
    Date operator--(int);//后置--
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