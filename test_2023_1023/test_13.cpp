#define _CRT_SECURE_NO_WARNINGS	1
//友元关系不能被继承
#include <iostream>
using namespace std;
class Student;
class Person
{
public:
	friend void Display(const Person& p, const Student& s);
protected:
	string _name = "张三"; // 姓名
};

class Student : public Person
{
public:
	friend void Display(const Person& p, const Student& s);
protected:
	int _stuNum = 12345678; // 学号
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