#define _CRT_SECURE_NO_WARNINGS	1
//引用理解
#include <iostream>
#include <assert.h>
using namespace std;
void TestRef1()
{
    int a = 10;
    int& ra = a;//<====定义引用类型
    printf("%p\n", &a);
    printf("%p\n", &ra);
}
void TestRef2()
{
    int a = 10;
    // int& ra;   // 该条语句编译时会出错
    int& ra = a;
    //
    int& rra = a;
    printf("%p %p %p\n", &a, &ra, &rra);
}
//引用做参数
void Swap(int& left, int& right)
{
    int temp = left;
    left = right;
    right = temp;
}
//引用做返回值
int Count1()
{
    static int n = 0;
    n++;
    return n;
}
int& Count2()
{
    static int n = 0;
    n++;
    return n;
}
#define N 10
typedef struct Array
{
    int a[N];
    int size;
}AY;
int& PostAt(AY& ay, int i)
{
    assert(i < N);
    return ay.a[i];
}
void TestConstRef()
{
    const int a = 10;
    //int& ra = a;   // 该语句编译时会出错，a为常量
    const int& ra = a;
    // int& b = 10; // 该语句编译时会出错，b为常量
    const int& b = 10;
    double d = 12.34;
    //int& rd = d; // 该语句编译时会出错，类型不同
    const int& rd = d;
}
int& Add(int a, int b)
{
    int c = a + b;
    return c;
}
int main()
{
    int& ret = Add(1, 2);
    Add(3, 4);
    cout << "Add(1, 2) is :" << ret << endl;
    cout << "Add(1, 2) is :" << ret << endl;
    return 0;
}