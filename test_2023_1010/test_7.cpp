#define _CRT_SECURE_NO_WARNINGS	1
//��λnew���
#include <iostream>
using namespace std;
class A
{
public:
	A(int a = 0)
		: _a(a)
	{
		cout << "A():" << this << endl;
	}
	~A()
	{
		cout << "~A():" << this << endl;
	}
private:
	int _a;
};
// ��λnew/replacement new
int main()
{
	// p1����ָ���ֻ��������A������ͬ��С��һ�οռ䣬����������һ��������Ϊ���캯��û��ִ��
	A* p1 = (A*)malloc(sizeof(A));
	new(p1)A;  // ע�⣺���A��Ĺ��캯���в���ʱ���˴���Ҫ����
	p1->~A();
	free(p1);
	A* p2 = (A*)operator new(sizeof(A));
	new(p2)A(10);
	p2->~A();
	operator delete(p2);
	return 0;
}