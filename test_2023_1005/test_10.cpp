#define _CRT_SECURE_NO_WARNINGS	1
//�������Կ�������ʱ��һЩ�Ż�
#include <iostream>
using namespace std;
class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A(int a)" << endl;
	}
	A(const A& aa)
		:_a(aa._a)
	{
		cout << "A(const A& aa)" << endl;
	}
	A& operator=(const A& aa)
	{
		cout << "A& operator=(const A& aa)" << endl;
		if (this != &aa)
		{
			_a = aa._a;
		}
		return *this;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};
void Fun1(A aa)
{

}
void Fun2(const A& aa)
{

}
A Fun3()
{
	A aa;//����
	return aa;//��������
}
A Fun4()
{
	return A();
}
int main()
{
	A aa1 = 1;//����+��������->�Ż�Ϊֱ�ӹ���
	cout << "-----" << endl;
	Fun3();//���Ż�
	cout << "-----" << endl;
	A aa2 = Fun3();//����Ӧ����һ�����죬�����������죬�����������Ż�Ϊһ�������һ����������
	cout << "-----" << endl;
	Fun4();
	A aa3 = Fun4();
	cout << "-----" << endl;
	return 0;
}
