#define _CRT_SECURE_NO_WARNINGS	1
//���캯������
#include <iostream>
using namespace std;
class Date
{
public:
    // 1.�޲ι��캯��
    Date()
    {}

    // 2.���ι��캯��
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
    Date d1; // �����޲ι��캯��
    Date d2(2015, 1, 1); // ���ô��εĹ��캯��
    Date d3();

    d1.Print();
    d2.Print();
    // ע�⣺���ͨ���޲ι��캯����������ʱ��������治�ø����ţ�����ͳ��˺�������
    // ���´���ĺ�����������d3�������ú����޲Σ�����һ���������͵Ķ���
    //d3.Print(); // warning C4930: ��Date d3(void)��: δ����ԭ�ͺ���(�Ƿ��������ñ��������?)
	return 0;
}