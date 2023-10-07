#define _CRT_SECURE_NO_WARNINGS	1
//友元的引入
#include <iostream>
using namespace std;
class Date
{
public:
    Date(int year, int month, int day)
        : _year(year)
        , _month(month)
        , _day(day)
    {}
    
//private:
    int _year;
    int _month;
    int _day;
};
ostream& operator<<(ostream& _cout, const Date& d)
{
    _cout << d._year << "-" << d._month << "-" << d._day << endl;
    return _cout;
}
int main()
{
    Date d1(2023, 10, 5);
    //d1 << cout << endl;
    cout << d1 << endl;
    return 0;
}