#define _CRT_SECURE_NO_WARNINGS	1
//多态
#include <iostream>
using namespace std;
//class Person {
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//};
//class Student : public Person {
//public:
//	/*virtual void BuyTicket() { cout << "买票-半价" << endl; }*/
//	/*注意：在重写基类虚函数时，派生类的虚函数在不加virtual关键字时，虽然也可以构成重写(因
//	为继承后基类的虚函数被继承下来了在派生类依旧保持虚函数属性),但是该种写法不是很规范，不建议
//	这样使用*/
//	void BuyTicket() { cout << "买票-半价" << endl; }
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
