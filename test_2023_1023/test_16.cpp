#define _CRT_SECURE_NO_WARNINGS	1
//���μ̳�
#include <iostream>
using namespace std;
class Person
{
public:
	string _name;
};
//ʹ��virtual����Assistant��ֱ�ӻ���Student��Teacher
class Student : virtual public Person
{
protected:
	int _num;
};
class Teacher : virtual public Person
{
protected:
	int _id;
};
class Assistant : public Student, public Teacher
{
protected:
	string _majorCourse;
};

int main()
{
	Assistant a;
	a._name = "peter";
	cout << a._name << endl;
	return 0;
}