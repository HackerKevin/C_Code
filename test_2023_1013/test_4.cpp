#define _CRT_SECURE_NO_WARNINGS	1
#include <iostream>
#include <string>
using namespace std;
//����string������صĽӿ�
void Teststring1()
{
	//ע�⣺string�����֧��ֱ����cin��cout������������
	cout << "����string������صĽӿ�" << endl;
	string s("hello world!!!");
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;
	cout << "----------" << endl;
	//��s�е��ַ�����գ�ע�����ʱֻ�ǽ�size��0�����ı�ײ�ռ�Ĵ�С
	s.clear();
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << "----------" << endl;
	//��s����Ч�ַ��������ӵ�10�������λ����'a'�������
	//��aaaaaaaaaa��
	s.resize(10, 'a');
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << "----------" << endl;
	//��s����Ч�ַ��������ӵ�15�������λ����ȱʡֵ'\0'�������
	//"aaaaaaaaaa\0\0\0\0\0"
	//ע���ʱs����Ч�ַ������Ѿ����ӵ�15��
	s.resize(15);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;
	cout << "----------" << endl;
	//��s����Ч�ַ�������С��5��
	s.resize(5);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;
	cout << "----------" << endl;
}
//����reserve�Ƿ��ı�string����ЧԪ�ظ���
void Teststring2()
{
	cout << "����reserve�Ƿ��ı�string����ЧԪ�ظ���" << endl;
	string s;
	s.reserve(100);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << "----------" << endl;
	//����reserve����С��string�ĵײ�ռ��Сʱ���Ƿ�Ὣ�ռ���С
	s.reserve(50);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
}
//����empty��clear
void Teststring3()
{
	cout << "����empty��clear" << endl;
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