#define _CRT_SECURE_NO_WARNINGS	1
// ʵ����ʾ���ּ̳й�ϵ�»����Ա�ĸ����ͳ�Ա���ʹ�ϵ�ı仯
#include <iostream>
using namespace std;
class Person
{
public:
	void Print()
	{
		cout << _name << endl;
	}
protected:
	string _name; // ����
private:
	int _age; // ����
};
//class Student : protected Person
//class Student : private Person
class Student : public Person
{
protected:
	int _stunum; // ѧ��
};
