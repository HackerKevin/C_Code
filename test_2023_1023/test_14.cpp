#define _CRT_SECURE_NO_WARNINGS	1
//�̳��뾲̬��Ա
#include <iostream>
using namespace std;
class Person
{
public:
	Person() { ++_count; }
protected:
	string _name; // ����
public:
	static int _count; // ͳ���˵ĸ�����
};

int Person::_count = 0;

class Student : public Person
{
protected:
	int _stuNum; // ѧ��
};
class Graduate : public Student
{
protected:
	string _seminarCourse; // �о���Ŀ
};

int main()
{
	/*Student s1;
	Student s2;
	Student s3;
	Graduate s4;
	cout << " ���� :" << Person::_count << endl;
	Student::_count = 0;
	cout << " ���� :" << Person::_count << endl;*/
	Person p;
	Student s;
	Graduate g;
	cout << &(p._count) << endl;
	cout << &(s._count) << endl;
	cout << &(g._count) << endl;
	cout << "����:" << Person::_count << endl;
	cout << "����:" << Student::_count << endl;
	cout << "����:" << Graduate::_count << endl;
	return 0;
}