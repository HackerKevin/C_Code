#define _CRT_SECURE_NO_WARNINGS	1
//string��ĳ�������
#include <iostream>
#include <string>
using namespace std;
void Teststring()
{
	string s1; // ����յ�string�����s1,�����ַ���
	string s2("hello bit"); // ��C��ʽ�ַ�������string�����s2
	string s3(5, 'c');
	string s4(s2); // ��������s4
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
}

int main()
{
	Teststring();
}