#define _CRT_SECURE_NO_WARNINGS	1
//匿名对象理解
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
	// 匿名对象在以下场景就很好用，当然还有一些其他使用场景，这个我们以后遇到了再说
	cout << Solution().Sum_Solution(10) << endl;
	return 0;
}
