#define _CRT_SECURE_NO_WARNINGS	1
//非类型模板参数理解
#include <iostream>
using namespace std;
//template<class T, size_t N = 10>
//void Func(const T& a)
//{
//	N = 10;
//}
template<class T, double N = 10>
class Array
{
private:
	T _a[N];
};
int main()
{
	/*Func(1);*/
	Array<int> a1;
	Array<double, 100> a2;
	return 0;
}