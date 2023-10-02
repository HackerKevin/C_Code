#define _CRT_SECURE_NO_WARNINGS	1
//�������
#include <iostream>
#include <assert.h>
using namespace std;
void TestRef1()
{
    int a = 10;
    int& ra = a;//<====������������
    printf("%p\n", &a);
    printf("%p\n", &ra);
}
void TestRef2()
{
    int a = 10;
    // int& ra;   // ����������ʱ�����
    int& ra = a;
    //
    int& rra = a;
    printf("%p %p %p\n", &a, &ra, &rra);
}
//����������
void Swap(int& left, int& right)
{
    int temp = left;
    left = right;
    right = temp;
}
//����������ֵ
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
    //int& ra = a;   // ��������ʱ�����aΪ����
    const int& ra = a;
    // int& b = 10; // ��������ʱ�����bΪ����
    const int& b = 10;
    double d = 12.34;
    //int& rd = d; // ��������ʱ��������Ͳ�ͬ
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