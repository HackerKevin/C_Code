#define _CRT_SECURE_NO_WARNINGS	1
//ǰ��++�ͺ���++����
#include <iostream>
using namespace std;
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	// ǰ��++������+1֮��Ľ��
	// ע�⣺thisָ��Ķ����������󲻻����٣��������÷�ʽ�������Ч��
	Date& operator++()
	{
		_day += 1;
		return *this;
	}
	// ����++��
	// ǰ��++�ͺ���++����һԪ�������Ϊ����ǰ��++�����++�γ�����ȷ����
	// C++�涨������++����ʱ������һ��int���͵Ĳ����������ú���ʱ�ò������ô��ݣ��������Զ�����
	// ע�⣺����++����ʹ�ú�+1�������Ҫ����+1֮ǰ�ľ�ֵ��������ʵ��ʱ��Ҫ�Ƚ�this����һ�ݣ�Ȼ���this + 1
	//       ��temp����ʱ�������ֻ����ֵ�ķ�ʽ���أ����ܷ�������
	Date operator++(int)
	{
		Date temp(*this);
		_day += 1;
		return temp;
	}
	void Print()
	{
		cout << _year << "��" << _month << "��" << _day << "��" << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d;
	Date d1(2022, 1, 13);
	d = d1++;
	d.Print();
	d1.Print();
	cout << "-------------------------" << endl;
	d = ++d1;
	d.Print();
	d1.Print();
	return 0;
}
