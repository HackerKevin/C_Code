#define _CRT_SECURE_NO_WARNINGS	1
//ģ�������ƥ��ԭ��2
#include <iostream>
using namespace std;
//ר�Ŵ���int�ļӷ�����
int Add(int left, int right)
{
	return left + right;
}
//ͨ�üӷ�����
template<class T1, class T2>
T1 Add(T1 left, T2 right)
{
	return left + right;
}
int main()
{
	cout << Add(1, 2) << endl; // ��Ǻ���ģ��������ȫƥ�䣬����Ҫ����ģ��ʵ����
	cout << Add(1, 2.0) << endl; // ģ�庯���������ɸ���ƥ��İ汾������������ʵ�����ɸ���ƥ���Add����
	return 0;
}