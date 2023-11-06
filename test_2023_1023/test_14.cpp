#define _CRT_SECURE_NO_WARNINGS	1
//继承与静态成员
#include <iostream>
using namespace std;
class Person
{
public:
	Person() { ++_count; }
protected:
	string _name; // 姓名
public:
	static int _count; // 统计人的个数。
};

int Person::_count = 0;

class Student : public Person
{
protected:
	int _stuNum; // 学号
};
class Graduate : public Student
{
protected:
	string _seminarCourse; // 研究科目
};

int main()
{
	/*Student s1;
	Student s2;
	Student s3;
	Graduate s4;
	cout << " 人数 :" << Person::_count << endl;
	Student::_count = 0;
	cout << " 人数 :" << Person::_count << endl;*/
	Person p;
	Student s;
	Graduate g;
	cout << &(p._count) << endl;
	cout << &(s._count) << endl;
	cout << &(g._count) << endl;
	cout << "人数:" << Person::_count << endl;
	cout << "人数:" << Student::_count << endl;
	cout << "人数:" << Graduate::_count << endl;
	return 0;
}