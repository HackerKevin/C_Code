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
//	string _name = "peter"; //����
//	int _age = 18;  //����
//};
//
//class Student : public Person
//{
//protected:
//	int _stuid; // ѧ��
//};
//class Teacher : public Person
//{
//protected:
//	int _jobid; // ����
//};
//int main()
//{
//	double d = 1.1;
//	int i = d;//��ǰ����˵dҪ��ֵ��i�����һ�����г��Ե���ʱ������������ʽ����ת��
//	
//	const int& ri = d;//������ʽ����ת������ʱ�������г��ԣ����Զ�������riʱҲҪ��const
//
//
//	//������һ�����⣬�ڹ��м̳��£�һ����������ܲ��ܸ���һ�����������
//	Student s;
//	Person p = s;
//
//	Person& rp = s;//���ﲻ��constû����˵�����ﲻ��������ת���ķ���
//				   //�Ը���Person�а�������Student�ǲ��ֶ��������
//
//	Person* ptrp = &s;//ȡ����Person�а�������Student�ǲ��ֶ���ĵ�ַ
//
//
//
//}







class Person
{
protected:
	string _name = "С����"; // ����
	int _num = 111;   // ���֤��
	//��������͸�������ͬ����Ա�������Ա�����θ����ͬ����Ա��ֱ�ӷ��ʣ�������������أ�Ҳ���ض��塣
};
class Student : public Person
{
public:
	void Print()
	{
		cout << " ����:" << _name << endl;
		cout << " ѧ��:" << _num << endl;//_num��Person�е����������վͽ�ԭ������Լ���_num
		cout << " ���֤��:" << Person::_num << endl;//��ʽ����Person�е�_num
		
	}
protected:
	int _num = 999; // ѧ��
};


// B�е�fun��A�е�fun���ǹ������أ���Ϊ������ͬһ������
// B�е�fun��A�е�fun�������أ���Ա�������㺯������ͬ�͹������ء�
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


//���������ᱻ�����