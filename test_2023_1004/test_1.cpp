#define _CRT_SECURE_NO_WARNINGS	1
//全局operator==理解
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
//private:
    int _year;
    int _month;
    int _day;
};
bool operator==(const Date& d1, const Date& d2)//第一个参数为左操作符，第二个参数为右操作符
{
    return d1._year == d2._year
        && d1._month == d2._month
        && d1._day == d2._day;
}
void Test()
{
    Date d1(2023, 9, 27);
    Date d2(2023, 9, 27);
    Date d3(2023, 9, 27);
    Date d4(2023, 9, 26);
    cout << (d1 == d2) << endl;//d1 == d2会被转换成operator==(d1,d2)
    cout << (d3 == d4) << endl;
}

int main()
{
    Test();
	return 0;
}