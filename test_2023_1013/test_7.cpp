#define _CRT_SECURE_NO_WARNINGS	1
//stringÀàµÄ·Ç³ÉÔ±º¯Êı
#include <iostream>
#include <string>
using namespace std;
//²âÊÔoperator+
void Teststring1()
{
	cout << "²âÊÔoperator+" << endl;
	string s1("Hello");
	string s2(" World!");
	string s3;
	s3 = s1 + s2;
	cout << s3 << endl;
}
//²âÊÔgetline
void Teststring2()
{
	cout << "²âÊÔgetline" << endl;
	string name;
	string age;
	cout << "Please, enter your full name: ";
	getline(cin, name);
	cout << "Hello, " << name << "!\n";
	cout << "Please, enter your age: ";
	getline(cin, age, 'Y');
	cout << "OK, you're " << age << " years old" << "\n";
}

//²âÊÔ¹ØÏµÔËËã·û
void Teststring3()
{
	cout << "²âÊÔ¹ØÏµÔËËã·û" << endl;
	string s1("Hello World!");
	string s2("Hello World!");
	string s3;
	string s4("hello world!");
	if (s1 == s2)//²âÊÔ==
		cout << "s1 == s2" << endl;
	if (s1 != s3)//²âÊÔ!=
		cout << "s1 != s3" << endl;
	if (s1 < s4)//²âÊÔ<
		cout << "s1 < s3" << endl;
	if (s4 <= s4)//²âÊÔ<=
		cout << "s4 <= s4" << endl;
	if (s4 > s1)//²âÊÔ>
		cout << "s4 > s1" << endl;
	if (s4 >= s1)//²âÊÔ>=
		cout << "s4 >= s4" << endl;
}
int main()
{
	Teststring1();
	Teststring2();
	Teststring3();
	return 0;
}
