#define _CRT_SECURE_NO_WARNINGS	1
//��ʼ���б����
#include <iostream>
using namespace std;
class A
{
public:
	A(int a)//����A��Ĭ�Ϲ��캯��
		:_a(1)
	{}
	void Print()
	{
		cout << _a;
	}
private:
	int _a;
};
class B
{
public:
	B(int a = 1, int ref = 1)
		: _aobj(1)
		, _ref(ref)
		/*, _n(10)*/
	{}
	void Print()
	{
		_aobj.Print();
		cout << " " << _ref << " " << _n << endl;
	}
private:
	A _aobj;      // û��Ĭ�Ϲ��캯��
	int& _ref;	  // ����
	const int _n; // const 
};

int main()
{
	B bb;
	bb.Print();
	return 0;
}




