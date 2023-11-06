#define _CRT_SECURE_NO_WARNINGS	1
#include <iostream>
using namespace std;
//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	string _name = "peter"; //姓名
//	int _age = 18;  //年龄
//};
//
//class Student : public Person
//{
//protected:
//	int _stuid; // 学号
//};
//class Teacher : public Person
//{
//protected:
//	int _jobid; // 工号
//};
//int main()
//{
//	double d = 1.1;
//	int i = d;//以前我们说d要赋值给i会产生一个具有常性的临时变量，这是隐式类型转换
//	
//	const int& ri = d;//由于隐式类型转换的临时变量具有常性，所以定义引用ri时也要加const
//
//
//	//现在有一个问题，在公有继承下，一个子类对象能不能赋给一个父类对象呢
//	Student s;
//	Person p = s;
//
//	Person& rp = s;//这里不加const没报错，说明这里不存在类型转换的发生
//				   //对父类Person中包含子类Student那部分对象的引用
//
//	Person* ptrp = &s;//取父类Person中包含子类Student那部分对象的地址
//
//
//
//}







class Person
{
protected:
	string _name = "小李子"; // 姓名
	int _num = 111;   // 身份证号
	//子类子类和父类中有同名成员，子类成员将屏蔽父类对同名成员的直接访问，这种情况叫隐藏，也叫重定义。
};
class Student : public Person
{
public:
	void Print()
	{
		cout << " 姓名:" << _name << endl;
		cout << " 学号:" << _num << endl;//_num和Person中的重名，按照就近原则，输出自己的_num
		cout << " 身份证号:" << Person::_num << endl;//显式访问Person中的_num
		
	}
protected:
	int _num = 999; // 学号
};


// B中的fun和A中的fun不是构成重载，因为不是在同一作用域。
// B中的fun和A中的fun构成隐藏，成员函数满足函数名相同就构成隐藏。
class A
{
public:
	void fun()
	{
		cout << "func()" << endl;
	}
};
class B : public A
{
public:
	void fun(int i)
	{
		A::fun();
		cout << "func(int i)->" << i << endl;
	}
};







int main()
{
	return 0;
}


//析构函数会被处理成