#define _CRT_SECURE_NO_WARNINGS	1
//string���޸�
#include <iostream>
#include <string>
using namespace std;
//������push_backβ���ַ�c
void Teststring1()
{
	cout << "������push_backβ���ַ�c" << endl;
	string s1("Hello");
	s1.push_back('!');
	cout << s1 << endl;
}
//������append���ַ�����׷���ַ���str
void Teststring2()
{
	cout << "������append���ַ�����׷���ַ���str" << endl;
	string s1("Hello");
	s1.append(" Wordld!");
	cout << s1 << endl;
}
//������operator+=���ַ�����׷���ַ���str
void Teststring3()
{
	cout << "������operator+=���ַ�����׷���ַ���str" << endl;
	string s1("Hello");
	s1 += " World!";
	cout << s1 << endl;
}
//������c_str����C��ʽ�ַ���
void Teststring4()
{
	cout << "������c_str����C��ʽ�ַ���" << endl;
	char c[20];
	string s1("1234");
	strcpy(c, s1.c_str());
	cout << c << endl;
}
//������find���в���
void Teststring5()
{
	cout << "������find���в���" << endl;
	string s1("There are two needles in this haystack with needles.");
	string s2("needle");
	size_t found = s1.find(s2);
	if (found != string::npos)
		cout << "first 'needle' found at: " << found << endl;
}
//������rfind���в���
void Teststring6()
{
	cout << "������rfind���в���" << endl;
	string s1("There are two needles in this haystack with needles.");
	string s2("needle");
	size_t found = s1.rfind(s2);
	if (found != string::npos)
		cout << "last 'needle' found at: " << found << endl;
}
//������substr���캯��
void Teststring7()
{
	cout << "������substr���캯��" << endl;
	string s1("Hello World��");
	string s2 = s1.substr(0, 5);
	cout << s2 << endl;
}
//������erase
int main()
{
	Teststring1();
	Teststring2();
	Teststring3();
	Teststring4();
	Teststring5();
	Teststring6();
	Teststring7();
	return 0;
}






