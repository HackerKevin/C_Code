#define _CRT_SECURE_NO_WARNINGS	1
//��Ԫ��ϵ���ܱ��̳�
#include <iostream>
using namespace std;
class Student;
class Person
{
public:
	friend void Display(const Person& p, const Student& s);
protected:
	string _name = "����"; // ����
};

class Student : public Person
{
public:
	friend void Display(const Person& p, const Student& s);
protected:
	int _stuNum = 12345678; // ѧ��
};

void Display(const Person& p, const Student& s)
{
	cout << p._name << endl;
	cout << s._stuNum << endl;
}

int main()
{
	Person p;
	Student s;
	Display(p, s);
	return 0;
}