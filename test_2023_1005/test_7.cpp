#define _CRT_SECURE_NO_WARNINGS	1
//�ڲ������
#include <iostream>
using namespace std;
class A
{
private:
    static int k;
    int h;
public:
    class B // B��������A����Ԫ
    {
    public:
        void foo(const A& a)
        {
            //B���Է���A��˽�г�Ա
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
