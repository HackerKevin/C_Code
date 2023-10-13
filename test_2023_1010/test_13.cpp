#define _CRT_SECURE_NO_WARNINGS	1
//模板参数的匹配原则1
#include <iostream>
using namespace std;
// 专门处理int的加法函数
int Add(int left, int right)
{
	return left + right;
}
// 通用加法函数
template<class T>
T Add(T left, T right)
{
	return left + right;
}
int main()
{
	//与非模板函数匹配，编译器不需要实例化
	cout << Add(1, 2) << endl;
	//调用编译器实例化的Add版本
	cout << Add<int>(1, 2) << endl;
	/*cout << Add(1.0, 2.0) << endl;*/
	return 0;
}