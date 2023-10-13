#define _CRT_SECURE_NO_WARNINGS	1
//new理解
#include <iostream>
using namespace std;
int main()
{
	int* p1 = new int;//申请1个int，不初始化
	int* p2 = new int(10);//申请1个int，初始化为10
	int* p3 = new int[10];//申请1个有10个int的数组，不初始化
	int* p4 = new	int[10]{ 1,2,3,4 };////申请1个有10个int的数组，前4个元素初始化为1、2、3、4

	delete p1;
	delete p2;
	delete[] p3;
	delete[] p4;
	return 0;
}