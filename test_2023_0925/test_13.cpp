#define _CRT_SECURE_NO_WARNINGS	1
//类的大小理解
#include <iostream>
using namespace std;
//类中既有成员变量，又有成员函数
class A1 {
public:
    void f1() {}
private:
    int _a;
};
//类中仅有成员
class A2 {
private:
    int _a;
};
//类中仅有成员函数
class A3 {
public:
    void f2() {}
};
//类中什么都没有——空类
class A4
{

};
int main()
{
    cout << sizeof(A1) << endl;
    cout << sizeof(A2) << endl;
    cout << sizeof(A3) << endl;
    cout << sizeof(A4) << endl;
    return 0;
}