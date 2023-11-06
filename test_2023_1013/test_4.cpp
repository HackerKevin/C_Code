#define _CRT_SECURE_NO_WARNINGS	1
#include <iostream>
#include <string>
using namespace std;
//测试string容量相关的接口
void Teststring1()
{
	//注意：string类对象支持直接用cin和cout进行输入和输出
	cout << "测试string容量相关的接口" << endl;
	string s("hello world!!!");
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;
	cout << "----------" << endl;
	//将s中的字符串清空，注意清空时只是将size清0，不改变底层空间的大小
	s.clear();
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << "----------" << endl;
	//将s中有效字符个数增加到10个，多出位置用'a'进行填充
	//“aaaaaaaaaa”
	s.resize(10, 'a');
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << "----------" << endl;
	//将s中有效字符个数增加到15个，多出位置用缺省值'\0'进行填充
	//"aaaaaaaaaa\0\0\0\0\0"
	//注意此时s中有效字符个数已经增加到15个
	s.resize(15);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;
	cout << "----------" << endl;
	//将s中有效字符个数缩小到5个
	s.resize(5);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;
	cout << "----------" << endl;
}
//测试reserve是否会改变string中有效元素个数
void Teststring2()
{
	cout << "测试reserve是否会改变string中有效元素个数" << endl;
	string s;
	s.reserve(100);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << "----------" << endl;
	//测试reserve参数小于string的底层空间大小时，是否会将空间缩小
	s.reserve(50);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
}
//测试empty和clear
void Teststring3()
{
	cout << "测试empty和clear" << endl;
	string s("hello world!!!");
	cout << s << endl;
	if (!s.empty())
		s.clear();
	cout << s << endl;
}
int main()
{
	Teststring1();
	Teststring2();
	Teststring3();
	return 0;
}