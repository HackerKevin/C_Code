#define _CRT_SECURE_NO_WARNINGS	1
//类模板的定义
#include <iostream>
using namespace std;
//typedef int STDataType;
//class Stack
//{
//private:
//	STDataType* _a;
//	size_t _top;
//	size_t _capacity;
//};

template<class T>
class Stack
{
private:
	T* _a;
	size_t _top;
	size_t _capacity;
};