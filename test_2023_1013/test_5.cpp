#define _CRT_SECURE_NO_WARNINGS	1
//string的遍历
#include <iostream>
#include <string>
using namespace std;
//测试用operator[pos]访问及遍历字符串
void Teststring1()
{
	cout << "测试用operator[pos]访问及遍历字符串" << endl;
	string s1("hello world");
	const string s2("Hello World");
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s1[0] << " " << s2[0] << endl;
	s1[0] = 'H';
	cout << s1 << endl;
	// s2[0] = 'h';   代码编译失败，因为const类型对象不能修改
}
//测试用at[pos]访问及遍历字符串
void Teststring2()
{
	cout << "测试用at[pos]访问及遍历字符串" << endl;
	string str("Test string");
	for (unsigned i = 0; i < str.length(); ++i)
	{
		cout << str.at(i) << " ";
	}
	cout << endl;
}
//测试用begin + end访问及遍历字符串
void Teststring3()
{
	cout << "测试用begin + end访问及遍历字符串" << endl;
	string s1("hello world");
	for (string::iterator it = s1.begin(); it != s1.end(); ++it)
		cout << *it;
	cout << endl;
}
//测试用rbegin + rend访问及遍历字符串
//rbegin()+rend()大多使用在需要使用STL提供的算法操作string时，比如：采用reverse逆置string
void Teststring4()
{
	cout << "测试用rbegin + rend访问及遍历字符串" << endl;
	string s1("hello world");
	cout << s1 << endl;
	for (string::reverse_iterator rit = s1.rbegin(); rit != s1.rend(); ++rit)
		cout << *rit;
	cout << endl;
}
//测试用范围for访问及遍历字符串
void Teststring5()
{

	cout << "测试用范围for访问及遍历字符串" << endl;
	string s1("hello world");
	for (auto e : s1)
		cout << e;
}
// begin()+end()   for+[]  范围for
// 注意：string遍历时使用最多的还是for+下标 或者 范围for(C++11后才支持)
int main()
{
	Teststring1();
	Teststring2();
	Teststring3();
	Teststring4();
	Teststring5();
	return 0;
}