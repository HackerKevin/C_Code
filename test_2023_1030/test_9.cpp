#define _CRT_SECURE_NO_WARNINGS	1
//以下程序输出结果是什么？
#include <iostream>
class A
{
public:
    virtual void func(int val = 1) { std::cout << "A->" << val << std::endl; }
};

class B : public A
{
public:
    void func(int val = 0) { std::cout << "B->" << val << std::endl; }
    virtual void test() { func(); }
};

int main()
{
    B* p = new B;
    p->test();
    return 0;
}