#define _CRT_SECURE_NO_WARNINGS	1
#include <iostream>
#include <string>

using namespace std;
class Person
{
public:
	string _name; // ����
};
class Student : virtual public Person
{
protected:
	int _num; //ѧ��
};
class Teacher : virtual public Person
{
protected:
	int _id; // ְ�����
};
class Assistant : public Student, public Teacher
{
protected:
	string _majorCourse; // ���޿γ�
};

void Test()
{
	// �������ж������޷���ȷ֪�����ʵ�����һ��
	Assistant a;
	a._name = "peter";
	// ��Ҫ��ʾָ�������ĸ�����ĳ�Ա���Խ�����������⣬�����������������޷����
	a.Student::_name = "xxx";
	a.Teacher::_name = "yyy";
}

int main()
{
	Test();
}