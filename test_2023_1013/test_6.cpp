#define _CRT_SECURE_NO_WARNINGS	1
//string的修改
#include <iostream>
#include <string>
using namespace std;
//测试用push_back尾插字符c
void Teststring1()
{
	cout << "测试用push_back尾插字符c" << endl;
	string s1("Hello");
	s1.push_back('!');
	cout << s1 << endl;
}
//测试用append在字符串后追加字符串str
void Teststring2()
{
	cout << "测试用append在字符串后追加字符串str" << endl;
	string s1("Hello");
	s1.append(" Wordld!");
	cout << s1 << endl;
}
//测试用operator+=在字符串后追加字符串str
void Teststring3()
{
	cout << "测试用operator+=在字符串后追加字符串str" << endl;
	string s1("Hello");
	s1 += " World!";
	cout << s1 << endl;
}
//测试用c_str返回C格式字符串
void Teststring4()
{
	cout << "测试用c_str返回C格式字符串" << endl;
	char c[20];
	string s1("1234");
	strcpy(c, s1.c_str());
	cout << c << endl;
}
//测试用find进行查找
void Teststring5()
{
	cout << "测试用find进行查找" << endl;
	string s1("There are two needles in this haystack with needles.");
	string s2("needle");
	size_t found = s1.find(s2);
	if (found != string::npos)
		cout << "first 'needle' found at: " << found << endl;
}
//测试用rfind进行查找
void Teststring6()
{
	cout << "测试用rfind进行查找" << endl;
	string s1("There are two needles in this haystack with needles.");
	string s2("needle");
	size_t found = s1.rfind(s2);
	if (found != string::npos)
		cout << "last 'needle' found at: " << found << endl;
}
//测试用substr构造函数
void Teststring7()
{
	cout << "测试用substr构造函数" << endl;
	string s1("Hello World！");
	string s2 = s1.substr(0, 5);
	cout << s2 << endl;
}
//测试用erase
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






