#define _CRT_SECURE_NO_WARNINGS	1
//内部类理解
#include <iostream>
using namespace std;
class A
{
private:
    static int k;
    int h;
public:
    class B // B天生就是A的友元
    {
    public:
        void foo(const A& a)
        {
            //B可以访问A的私有成员
            cout << k << endl;//OK
            cout << a.h << endl;//OK
        }
    };
};
int A::k = 1;
int main()
{
    A::B b;
    b.foo(A());
    return 0;
}
