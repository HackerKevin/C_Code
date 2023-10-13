#define _CRT_SECURE_NO_WARNINGS	1
//内存泄漏理解
#include <iostream>
using namespace std;
void MemoryLeaks()
{
	// 1.内存申请了忘记释放
	int* p1 = (int*)malloc(sizeof(int));
	int* p2 = new int;

	// 2.异常安全问题
	int* p3 = new int[10];

	Func(); // 这里Func函数抛异常导致 delete[] p3未执行，p3没被释放.

	delete[] p3;
}
