#define _CRT_SECURE_NO_WARNINGS	1
//��̬
#include <iostream>
using namespace std;
//class Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
//};
//class Student : public Person {
//public:
//	/*virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }*/
//	/*ע�⣺����д�����麯��ʱ����������麯���ڲ���virtual�ؼ���ʱ����ȻҲ���Թ�����д(��
//	Ϊ�̳к������麯�����̳������������������ɱ����麯������),���Ǹ���д�����Ǻܹ淶��������
//	����ʹ��*/
//	void BuyTicket() { cout << "��Ʊ-���" << endl; }
//};
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//int main()
//{
//	Person ps;
//	Student st;
//	Func(ps);
//	Func(st);
//	return 0;
//}
class Person 
{
public:
	virtual ~Person() { cout << "~Person()" << endl; }
};
class Student : public Person 
{
public:
	 virtual ~Student() { cout << "~Student()" << endl; }
};

int main()
{
	Person* p1 = new Person;
	Person* p2 = new Student;
	delete p2;
	delete p1;
	return 0;
}
