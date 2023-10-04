#define _CRT_SECURE_NO_WARNINGS	1
//��ֵ��������
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
   /* void operator=(const Date& d)
    {
        _year = d._year;
        _month = d._month;
        _day = d._day;
    }*/
    bool operator==(const Date& d2)
    {
        return _year == d2._year
            && _month == d2._month
            && _day == d2._day;
    }
    bool operator!=(const Date& d)
    {
        return !(*this == d);
    }
    Date& operator=(const Date& d)//֧��������ֵ�����ظ�ֵ�����
    {
        if (this != &d)//��ַ��һ��ʱ�Ÿ�ֵ
        {
            _year = d._year;
            _month = d._month;
            _day = d._day;
            return *this;
        } 
    }
    void Print()
    {
        cout << _year << "��" << _month << "��" << _day << "��" << endl;
    }
private:
    int _year;
    int _month;
    int _day;
};
void Test()
{
    Date d1(2023, 9, 27);
    Date d2 = d1;
    d1.Print();
    d2.Print();
    Date d3;
    d3 = d1;
    cout << "--------------------------------" << endl;
    d1.Print();
    d2.Print();
    d3.Print();
}
int main()
{
    Test();
    return 0;
}