#define _CRT_SECURE_NO_WARNINGS	1
//ģ�������ƥ��ԭ��1
#include <iostream>
using namespace std;
// ר�Ŵ���int�ļӷ�����
int Add(int left, int right)
{
	return left + right;
}
// ͨ�üӷ�����
template<class T>
T Add(T left, T right)
{
	return left + right;
}
int main()
{
	//���ģ�庯��ƥ�䣬����������Ҫʵ����
	cout << Add(1, 2) << endl;
	//���ñ�����ʵ������Add�汾
	cout << Add<int>(1, 2) << endl;
	/*cout << Add(1.0, 2.0) << endl;*/
	return 0;
}