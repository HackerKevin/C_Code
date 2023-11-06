#define _CRT_SECURE_NO_WARNINGS	1
//string类的常见构造
#include <iostream>
#include <string>
using namespace std;
void Teststring()
{
	string s1; // 构造空的string类对象s1,即空字符串
	string s2("hello bit"); // 用C格式字符串构造string类对象s2
	string s3(5, 'c');
	string s4(s2); // 拷贝构造s4
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
}

int main()
{
	Teststring();
}