#define _CRT_SECURE_NO_WARNINGS	1
//��Ĵ�С���
#include <iostream>
using namespace std;
//���м��г�Ա���������г�Ա����
class A1 {
public:
    void f1() {}
private:
    int _a;
};
//���н��г�Ա
class A2 {
private:
    int _a;
};
//���н��г�Ա����
class A3 {
public:
    void f2() {}
};
//����ʲô��û�С�������
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