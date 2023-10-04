#define _CRT_SECURE_NO_WARNINGS	1
//局部operator==理解
#include <iostream>
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

    // bool operator==(Date* this, const Date& d2)
    // 这里需要注意的是，左操作数是this，指向调用函数的对象
    bool operator==(const Date & d2)
    {
        return _year == d2._year
            && _month == d2._month
            && _day == d2._day;
    }
    bool operator<(const Date& d)
    {
        return _year < d._year
            || (_year == d._year && _month < d._month)
            || (_year == d._year && _month == d._month && _day < d._day);  
    }
    bool operator<=(const Date& d)
    {
        return *this < d || *this == d;
    }
    bool operator>(const Date& d)
    {
        return !(*this <= d);
    }
    bool operator>=(const Date& d)
    {
        return !(*this < d);
    }
    bool operator!=(const Date& d)
    {
        return !(*this == d);
    }
private:
    int _year;
    int _month;
    int _day;
};
void Test()
{
    Date d1(2023, 9, 27);
    Date d2(2023, 9, 27);
    Date d3(2023, 9, 27);
    Date d4(2023, 9, 26);
    cout << (d1 == d2) << endl;
    cout << (d3 == d4) << endl;
}
int main()
{
    Test();
    return 0;
}



