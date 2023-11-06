#define _CRT_SECURE_NO_WARNINGS	1
//string�ı���
#include <iostream>
#include <string>
using namespace std;
//������operator[pos]���ʼ������ַ���
void Teststring1()
{
	cout << "������operator[pos]���ʼ������ַ���" << endl;
	string s1("hello world");
	const string s2("Hello World");
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s1[0] << " " << s2[0] << endl;
	s1[0] = 'H';
	cout << s1 << endl;
	// s2[0] = 'h';   �������ʧ�ܣ���Ϊconst���Ͷ������޸�
}
//������at[pos]���ʼ������ַ���
void Teststring2()
{
	cout << "������at[pos]���ʼ������ַ���" << endl;
	string str("Test string");
	for (unsigned i = 0; i < str.length(); ++i)
	{
		cout << str.at(i) << " ";
	}
	cout << endl;
}
//������begin + end���ʼ������ַ���
void Teststring3()
{
	cout << "������begin + end���ʼ������ַ���" << endl;
	string s1("hello world");
	for (string::iterator it = s1.begin(); it != s1.end(); ++it)
		cout << *it;
	cout << endl;
}
//������rbegin + rend���ʼ������ַ���
//rbegin()+rend()���ʹ������Ҫʹ��STL�ṩ���㷨����stringʱ�����磺����reverse����string
void Teststring4()
{
	cout << "������rbegin + rend���ʼ������ַ���" << endl;
	string s1("hello world");
	cout << s1 << endl;
	for (string::reverse_iterator rit = s1.rbegin(); rit != s1.rend(); ++rit)
		cout << *rit;
	cout << endl;
}
//�����÷�Χfor���ʼ������ַ���
void Teststring5()
{

	cout << "�����÷�Χfor���ʼ������ַ���" << endl;
	string s1("hello world");
	for (auto e : s1)
		cout << e;
}
// begin()+end()   for+[]  ��Χfor
// ע�⣺string����ʱʹ�����Ļ���for+�±� ���� ��Χfor(C++11���֧��)
int main()
{
	Teststring1();
	Teststring2();
	Teststring3();
	Teststring4();
	Teststring5();
	return 0;
}