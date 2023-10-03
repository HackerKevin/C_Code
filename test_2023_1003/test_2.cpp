#define _CRT_SECURE_NO_WARNINGS	1
//构造函数重载
#include <iostream>
using namespace std;
class Date
{
public:
    // 1.无参构造函数
    Date()
    {}

    // 2.带参构造函数
    Date(int year, int month, int day)
    {
        _year = year;
        _month = month;
        _day = day;
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
    Date d1; // 调用无参构造函数
    Date d2(2015, 1, 1); // 调用带参的构造函数
    Date d3();

    d1.Print();
    d2.Print();
    // 注意：如果通过无参构造函数创建对象时，对象后面不用跟括号，否则就成了函数声明
    // 以下代码的函数：声明了d3函数，该函数无参，返回一个日期类型的对象
    //d3.Print(); // warning C4930: “Date d3(void)”: 未调用原型函数(是否是有意用变量定义的?)
	return 0;
}