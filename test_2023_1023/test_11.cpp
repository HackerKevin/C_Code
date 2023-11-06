#define _CRT_SECURE_NO_WARNINGS	1
// 实例演示三种继承关系下基类成员的各类型成员访问关系的变化
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
	string _name; // 姓名
private:
	int _age; // 年龄
};
//class Student : protected Person
//class Student : private Person
class Student : public Person
{
protected:
	int _stunum; // 学号
};
