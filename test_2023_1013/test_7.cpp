#define _CRT_SECURE_NO_WARNINGS	1
//string��ķǳ�Ա����
#include <iostream>
#include <string>
using namespace std;
//����operator+
void Teststring1()
{
	cout << "����operator+" << endl;
	string s1("Hello");
	string s2(" World!");
	string s3;
	s3 = s1 + s2;
	cout << s3 << endl;
}
//����getline
void Teststring2()
{
	cout << "����getline" << endl;
	string name;
	string age;
	cout << "Please, enter your full name: ";
	getline(cin, name);
	cout << "Hello, " << name << "!\n";
	cout << "Please, enter your age: ";
	getline(cin, age, 'Y');
	cout << "OK, you're " << age << " years old" << "\n";
}

//���Թ�ϵ�����
void Teststring3()
{
	cout << "���Թ�ϵ�����" << endl;
	string s1("Hello World!");
	string s2("Hello World!");
	string s3;
	string s4("hello world!");
	if (s1 == s2)//����==
		cout << "s1 == s2" << endl;
	if (s1 != s3)//����!=
		cout << "s1 != s3" << endl;
	if (s1 < s4)//����<
		cout << "s1 < s3" << endl;
	if (s4 <= s4)//����<=
		cout << "s4 <= s4" << endl;
	if (s4 > s1)//����>
		cout << "s4 > s1" << endl;
	if (s4 >= s1)//����>=
		cout << "s4 >= s4" << endl;
}
int main()
{
	Teststring1();
	Teststring2();
	Teststring3();
	return 0;
}
