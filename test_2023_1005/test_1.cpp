#define _CRT_SECURE_NO_WARNINGS	1
//explicit�ؼ��ֵ�����
#include <iostream>
using namespace std;
class A
{
public:
    A(int a)
        :_a1(a)
    {}

    void Print() const
    {
        cout << _a1 << " " << _a2 << endl;
    }
private:
    int _a2;
    int _a1;
};
int main() 
{
    A aa1(1);//���캯��
    const A& ref = 10;
    //A& ref = 10;
    ref.Print();
    return 0;
}