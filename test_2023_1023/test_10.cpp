#define _CRT_SECURE_NO_WARNINGS	1
//继承的概念
#include <iostream>
#include <string>
using namespace std;
class Person
{
public:
	void Print()
	{
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
protected:
	string _name = "peter"; //姓名
	int _age = 18;  //年龄
};
// 继承后父类的Person的成员（成员函数+成员变量）都会变成子类的一部分。这里体现出了
//Student和Teacher复用了Person的成员。下面我们使用监视窗口查看Student和Teacher对象，可
//以看到变量的复用。调用Print可以看到成员函数的复用。
class Student : public Person
{
protected:
	int _stuid; // 学号
};
class Teacher : public Person
{
protected:
	int _jobid; // 工号
};
int main()
{
	Student s;
	Teacher t;
	s.Print();
	t.Print();
	return 0;
}
