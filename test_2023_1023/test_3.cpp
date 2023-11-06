#define _CRT_SECURE_NO_WARNINGS	1
#include <iostream>
#include "Date.h"
using namespace std;
template<class T1, class T2>
class Data
{
public:
	Data() { cout << "Data<T1, T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};
template<>
class Data<int, char>
{
public:
	Data() { cout << "Data<int, char>" << endl; }
private:
	int _d1;
	char _d2;
};
//两个参数偏特化为指针类型
template <typename T1, typename T2>
class Data <T1*, T2*>
{
public:
	Data() { cout << "Data<T1*, T2*>" << endl; }

private:
	T1 _d1;
	T2 _d2;
};
//两个参数偏特化为引用类型
template <typename T1, typename T2>
class Data <T1&, T2&>
{
public:
	Data(const T1& d1, const T2& d2)
		: _d1(d1)
		, _d2(d2)
	{
		cout << "Data<T1&, T2&>" << endl;
	}

private:
	const T1& _d1;
	const T2& _d2;
};
//将第二个参数特化为int
template <class T1>
class Data<T1, int>
{
public:
	Data() { cout << "Data<T1, int>" << endl; }
private:
	T1 _d1;
	int _d2;
};
void Test2()
{
	Data<double, int> d1;      //调用特化的int版本
	Data<int, double> d2;      //调用基础的模板 
	Data<int*, int*> d3; 	   //调用特化的指针版本
	Data<int&, int&> d4(1, 2); //调用特化的引用版本
}
void Test()//全特化
{
	Data<int, int> d1;
	Data<char, int> d2;
}

int main()
{
	Test2();
	return 0;
}

