#define _CRT_SECURE_NO_WARNINGS	1
//�����������
#include <iostream>
using namespace std;
class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A(int a)" << endl;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};
class Solution {
public:
	int Sum_Solution(int n) {
		//...
		return n;
	}
};
int main()
{
	A();
	cout << "-----" << endl;
	// �������������³����ͺܺ��ã���Ȼ����һЩ����ʹ�ó�������������Ժ���������˵
	cout << Solution().Sum_Solution(10) << endl;
	return 0;
}
